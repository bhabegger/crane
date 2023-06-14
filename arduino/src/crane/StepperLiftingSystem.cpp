#include "StepperLiftingSystem.h"

StepperLiftingSystem::StepperLiftingSystem(int pin1, int pin2, int pin3, int pin4) {
  this->stepper = new AccelStepper(AccelStepper::FULL4WIRE, pin1, pin2, pin3, pin4);
}

void StepperLiftingSystem::setup() {
  this->stepper->setMaxSpeed(200.0);
  this->stepper->setAcceleration(100.0);
  this->top = 0;
  this->bottom = 200;
}

void StepperLiftingSystem::startRaising() {
  this->stepper->moveTo(top);
}

void StepperLiftingSystem::startLowering() {
   this->stepper->moveTo(bottom);
}

void StepperLiftingSystem::stop() {
  this->stepper->stop();
}

void StepperLiftingSystem::loop() {
  this->stepper->run();
}
