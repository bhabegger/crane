#include "Arduino.h"
#include "Servo.h"
#include "LiftingSystem.h"

LiftingSystem::LiftingSystem(int raiseButtonPin, int lowerButtonPin, int servoPin) {
    this->raiseButtonPin = raiseButtonPin;
    this->lowerButtonPin = lowerButtonPin;
    this->servo = new ContinuousServo(servoPin);
}

void LiftingSystem::setup() {
    pinMode(this->raiseButtonPin, INPUT);
    pinMode(this->lowerButtonPin, INPUT);
    this->servo->setup();
}

void LiftingSystem::cycle() {
    int raiseNewState = digitalRead(this->raiseButtonPin);
    int lowerNewState = digitalRead(this->lowerButtonPin);

    if(raiseNewState == lowerNewState) {
        this->servo->stop();
    } else if(raiseNewState == HIGH) {
        this->servo->rotate(true);
    } else if(lowerNewState == HIGH) {
        this->servo->rotate(false);
    }
}