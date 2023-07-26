#define HALFSTEP 8
#include "StepperRotatingSystem.h"

StepperRotatingSystem::StepperRotatingSystem(int pin1, int pin2, int pin3, int pin4) {
  Serial.print("StepperRotatingSystem using PINS: ");
  Serial.print(pin1);
  Serial.print(" ");
  Serial.print(pin2);
  Serial.print(" ");
  Serial.print(pin3);
  Serial.print(" ");
  Serial.println(pin4);
  this->stepper = new AccelStepper(HALFSTEP, pin1, pin3, pin2, pin4);
}

void StepperRotatingSystem::setup() {
  Serial.print("StepperRotatingSystem setup: ");

  this->counterClockwiseExtreme = -16960;
  this->clockwiseExtreme = 16960;

  this->stepper->setMaxSpeed(1800.0);
  this->stepper->setAcceleration(200.0);
  this->stepper->setSpeed(1800.0);
  this->stepper->setCurrentPosition(0);

  Serial.println("DONE");
}

void StepperRotatingSystem::startRotatingClockwise() {
  Serial.print("Start Rotating Clockwise");
  this->stepper->setSpeed(2100.0);
  this->stepper->setCurrentPosition(0);
  this->stepper->moveTo(this->clockwiseExtreme);
}

void StepperRotatingSystem::startRotatingCounterClockwise() {
   Serial.print("Start Rotating Counter-clockwise");
   this->stepper->setSpeed(2100.0);
   this->stepper->setCurrentPosition(0);
   this->stepper->moveTo(this->counterClockwiseExtreme);
}

void StepperRotatingSystem::stop() {
  Serial.print("Stopping");
  this->stepper->setSpeed(0.0);
  this->stepper->stop();
}

void StepperRotatingSystem::loop() {
  this->stepper->run();
}
