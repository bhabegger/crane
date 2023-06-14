#include "Arduino.h"
#include "Servo.h"
#include "ServoLiftingSystem.h"


ServoLiftingSystem::ServoLiftingSystem(int servoPin) {
    this->servo = new ContinuousServo(servoPin);
}

void ServoLiftingSystem::setup() {
    this->servo->setup();
}

void ServoLiftingSystem::startRaising() {
    Serial.print("Start Raising");
    this->servo->rotate(true);
}

void ServoLiftingSystem::stop() {
    Serial.print("Stop");
    this->servo->stop();
}

void ServoLiftingSystem::startLowering() {
    Serial.print("Start Lowering");
    this->servo->rotate(false);
}

void ServoLiftingSystem::loop() {
}
