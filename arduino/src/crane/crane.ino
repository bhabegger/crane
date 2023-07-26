#include "Button.h"
#include "RemoteControl.h"
#include "StepperLiftingSystem.h"
#include "StepperRotatingSystem.h"
#include "StepperTranslatingSystem.h"

LiftingSystem*      liftingSystem     = new StepperLiftingSystem(4,5,6,7);
RotatingSystem*     rotatingSystem    = new StepperRotatingSystem(8,9,10,11);
TranslatingSystem*  translatingSystem = new StepperTranslatingSystem(24,26,28,30);

RemoteControl       remoteControl(2);
int loopCount = 0;
void setup() {
    Serial.begin(115200);
    Serial.println("Setting up...");
    Serial.print("File: ");
    Serial.println(__FILE__ );
    Serial.print("Date: ");
    Serial.println(__DATE__);

    liftingSystem->setup();
    translatingSystem->setup();
    rotatingSystem->setup();

    remoteControl.onCommand(REMOTE_VOL_UP, startRaisingAction);
    remoteControl.onCommand(REMOTE_VOL_DOWN, startLoweringAction);
    remoteControl.onCommand(REMOTE_LEFT, startRotatingClockwise);
    remoteControl.onCommand(REMOTE_RIGHT, startRotatingCounterClockwise);
    remoteControl.onCommand(REMOTE_UP, startMovingForwardAction);
    remoteControl.onCommand(REMOTE_DOWN, startMovingBackwardAction);
    remoteControl.onCommand(REMOTE_OK, stopAllAction);
    remoteControl.setup();

    Serial.println("Done.");
}

void startRaisingAction() {
    Serial.println("Raising");
    liftingSystem->startRaising();
}

void startLoweringAction() {
    Serial.println("Lowering");
    liftingSystem->startLowering();
}

void stopLiftingAction() {
    Serial.println("Stopping lifting");
    liftingSystem->stop();
}

void startRotatingClockwise() {
    Serial.println("Rotating ->");
    rotatingSystem->startRotatingClockwise();
}

void startRotatingCounterClockwise() {
    Serial.println("Rotating <-");
    rotatingSystem->startRotatingCounterClockwise();
}
void startMovingForwardAction() {
    Serial.println("Forward");
    translatingSystem->startMovingForward();
}

void startMovingBackwardAction() {
    Serial.println("Backward");
    translatingSystem->startMovingBackward();
}

void stopAllAction() {
    Serial.println("Stop");
    liftingSystem->stop();
    translatingSystem->stop();
    rotatingSystem->stop();
}

void loop() {
    remoteControl.loop();
    liftingSystem->loop();
    translatingSystem->loop();
    rotatingSystem->loop();
}
