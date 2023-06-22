#include "Arduino.h"
#include "ServoTranslatingSystem.h"
ServoTranslatingSystem::ServoTranslatingSystem(int servoPin) {
    this->servo = new ContinuousServo(servoPin);
}

void ServoTranslatingSystem::setup() {
    this->servo->setup();
}

void ServoTranslatingSystem::startMovingForward() {
   this->servo->rotate(false);
}

void ServoTranslatingSystem::startMovingBackward() {
  this->servo->rotate(true);
}

void ServoTranslatingSystem::stop() {
    this->servo->stop();
}

void ServoTranslatingSystem::loop() {

}
