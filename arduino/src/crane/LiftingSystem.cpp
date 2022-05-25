#include "Arduino.h"
#include "Servo.h"
#include "LiftingSystem.h"

LiftingSystem::LiftingSystem(int servoPin) {
    this->servo = new ContinuousServo(servoPin);
}

void LiftingSystem::setup() {
    this->servo->setup();
}

void LiftingSystem::startRaising() {
    Serial.print("Start Raising");
    this->servo->rotate(true);
}

void LiftingSystem::stopRaising() {
    Serial.print("Stop Raising");
    this->servo->stop();
}

void LiftingSystem::startLowering() {
    Serial.print("Start Lowering");
    this->servo->rotate(false);
}

void LiftingSystem::stopLowering() {
    Serial.print("Stop Lowering");
    this->servo->stop();
}

void LiftingSystem::loop() {
}
