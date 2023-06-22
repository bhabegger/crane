#include <Servo.h>
#include "Arduino.h"
#include "ContinuousServo.h"

const int defaultStep = 45;
const int stopAngle = 90;
ContinuousServo::ContinuousServo(int servoPin) {
    this->servoPin = servoPin;
}

void ContinuousServo::setup() {
    this->servo.attach(servoPin);
    this->servo.write(90);
    this->initAngle = servo.read();
    delay(2000);
    this->servo.detach();
    
    Serial.print("Init angle: ");
    Serial.println(this->initAngle);
}

void ContinuousServo::rotate(bool clockwise) {  
    this->servo.attach(servoPin);
    int currentAngle = servo.read();
    Serial.print("Current target angle: ");
    Serial.println(currentAngle);
    int targetAngle = stopAngle;
    if(clockwise) {
        Serial.println("Rotating clockwise");
        targetAngle += defaultStep;
    } else {
        Serial.println("Rotating counter clockwise");
        targetAngle -= defaultStep;
    }
    Serial.print("Target angle: ");
    Serial.println(targetAngle);
    this->servo.write(targetAngle);
    delay(15);
}

void ContinuousServo::stop() {
    int currentAngle = servo.read();
    this->servo.write(currentAngle);
    this->servo.detach();
}
