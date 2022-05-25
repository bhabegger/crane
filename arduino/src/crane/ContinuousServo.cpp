#include <Servo.h>
#include "Arduino.h"
#include "ContinuousServo.h"

const int defaultStep = 5;
const int stopAngle = 89;
ContinuousServo::ContinuousServo(int servoPin) {
    this->servoPin = servoPin;
}

void ContinuousServo::setup() {
    this->servo.attach(servoPin);
    this->initAngle = servo.read();
    
    Serial.print("Init angle: ");
    Serial.println(this->initAngle);
}

void ContinuousServo::rotate(bool clockwise) {  
    int currentAngle = servo.read();
    Serial.print("Current angle: ");
    Serial.println(currentAngle);
    if(clockwise) {
        Serial.println("Rotating clockwise");
        this->servo.write(stopAngle+5);
    } else {
        Serial.println("Rotating counter clockwise");
        this->servo.write(stopAngle-5);
    }
    delay(15);
}

void ContinuousServo::stop() {
    this->servo.write(stopAngle);
}
