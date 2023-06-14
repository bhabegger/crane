#include "Button.h"
#include "RemoteControl.h"
#include "StepperLiftingSystem.h"
#include "StepperRotatingSystem.h"
#include "ServoTranslatingSystem.h"

LiftingSystem*      liftingSystem     = new StepperLiftingSystem(4,5,6,7);
RotatingSystem*     rotatingSystem    = new StepperRotatingSystem(8,9,10,11);
TranslatingSystem*  translatingSystem = new ServoTranslatingSystem(3);

RemoteControl       remoteControl(2);

void setup() {
    Serial.begin(115200);
    Serial.println("Setting up...");
    Serial.print("File: ");
    Serial.println(__FILE__ );
    Serial.print("Date: ");
    Serial.println(__DATE__);

    liftingSystem->setup();

    remoteControl.onCommand(REMOTE_UP, startRaisingAction);
    remoteControl.onCommand(REMOTE_DOWN, startLoweringAction);
    remoteControl.onCommand(REMOTE_LEFT, startRotatingClockwise);
    remoteControl.onCommand(REMOTE_RIGHT, startRotatingCounterClockwise);
    remoteControl.onCommand(REMOTE_5, startMovingForwardAction);
    remoteControl.onCommand(REMOTE_0, startMovingBackwardAction);
    remoteControl.onCommand(REMOTE_OK, stopAllAction);
    remoteControl.setup();

    Serial.println("Done.");
}

void startRaisingAction() {
    liftingSystem->startRaising();
}

void startLoweringAction() {
    liftingSystem->startLowering();
}

void stopLiftingAction() {
    liftingSystem->stop();
}

void startRotatingClockwise() {
    rotatingSystem->startRotatingClockwise();
}

void startRotatingCounterClockwise() {
    rotatingSystem->startRotatingCounterClockwise();
}
void startMovingForwardAction() {
    translatingSystem->startMovingForward();
}

void startMovingBackwardAction() {
    translatingSystem->startMovingBackward();
}

void stopAllAction() {
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
