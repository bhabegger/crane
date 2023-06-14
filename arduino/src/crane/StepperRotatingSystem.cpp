#include "StepperRotatingSystem.h"

StepperRotatingSystem::StepperRotatingSystem(int pin1, int pin2, int pin3, int pin4) {
  this->stepper = new AccelStepper(AccelStepper::FULL4WIRE, pin1, pin2, pin3, pin4);
}

void StepperRotatingSystem::setup() {
  this->stepper->setMaxSpeed(200.0);
  this->stepper->setAcceleration(100.0);
  this->counterClockwiseExtreme = 0;
  this->clockwiseExtreme = 200;
}

void StepperRotatingSystem::startRotatingClockwise() {
  this->stepper->moveTo(clockwiseExtreme);
}

void StepperRotatingSystem::startRotatingCounterClockwise() {
   this->stepper->moveTo(counterClockwiseExtreme);
}

void StepperRotatingSystem::stop() {
  this->stepper->stop();
}

void StepperRotatingSystem::loop() {
  this->stepper->run();
}