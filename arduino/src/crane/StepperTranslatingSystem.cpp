#define HALFSTEP 8
#include "StepperTranslatingSystem.h"

StepperTranslatingSystem::StepperTranslatingSystem(int pin1, int pin2, int pin3, int pin4) {
  Serial.print("StepperTranslatingSystem using PINS: ");
  Serial.print(pin1);
  Serial.print(" ");
  Serial.print(pin2);
  Serial.print(" ");
  Serial.print(pin3);
  Serial.print(" ");
  Serial.println(pin4);
  this->stepper = new AccelStepper(HALFSTEP, pin1, pin3, pin2, pin4);
}

void StepperTranslatingSystem::setup() {
  Serial.print("StepperTranslatingSystem setup: ");

  this->front = 16960;
  this->rear = -16960;

  this->stepper->setMaxSpeed(1800.0);
  this->stepper->setAcceleration(200.0);
  this->stepper->setSpeed(1800.0);
  this->stepper->setCurrentPosition(0);
  
  Serial.println("DONE");
}

void StepperTranslatingSystem::startMovingForward() {
  Serial.print("Start moving forward");
  this->stepper->setSpeed(2100.0);
  this->stepper->setCurrentPosition(0);
  this->stepper->moveTo(this->front);
}

void StepperTranslatingSystem::startMovingBackward() {
   Serial.print("Start moving backward");
   this->stepper->setSpeed(2100.0);
   this->stepper->setCurrentPosition(0);
   this->stepper->moveTo(this->rear);
}

void StepperTranslatingSystem::stop() {  
  Serial.print("Stopping");
  this->stepper->setSpeed(0.0);
  this->stepper->stop();
}

void StepperTranslatingSystem::loop() {
  this->stepper->run();
}
