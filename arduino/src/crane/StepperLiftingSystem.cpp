#define HALFSTEP 8
#include "StepperLiftingSystem.h"

StepperLiftingSystem::StepperLiftingSystem(int pin1, int pin2, int pin3, int pin4) {
  Serial.print("StepperLiftingSystem using PINS: ");
  Serial.print(pin1);
  Serial.print(" ");
  Serial.print(pin2);
  Serial.print(" ");
  Serial.print(pin3);
  Serial.print(" ");
  Serial.println(pin4);
  this->stepper = new AccelStepper(HALFSTEP, pin1, pin3, pin2, pin4);
}

void StepperLiftingSystem::setup() {
  Serial.print("StepperLiftingSystem setup: ");

  this->top = 16960;
  this->bottom = -16960;

  this->stepper->setMaxSpeed(2100.0);
  this->stepper->setAcceleration(100.0);
  this->stepper->setSpeed(2100.0);
  this->stepper->setCurrentPosition(0);
  
  Serial.println("DONE");
}

void StepperLiftingSystem::startRaising() {  
  Serial.print("Start Raising");
  this->stepper->setSpeed(2100.0);
  this->stepper->setCurrentPosition(0);
  this->stepper->moveTo(this->top);
}

void StepperLiftingSystem::startLowering() {
   Serial.print("Start Lowering");
   this->stepper->setSpeed(2100.0);
   this->stepper->setCurrentPosition(0);
   this->stepper->moveTo(this->bottom);
}

void StepperLiftingSystem::stop() {  
  Serial.print("Stopping");
  this->stepper->setSpeed(0.0);
  this->stepper->stop();
}

void StepperLiftingSystem::loop() {
  this->stepper->run();
}
