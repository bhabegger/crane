#include <Servo.h>
#include "Arduino.h"
#include "ContinuousServo.h"

const int defaultStep = 10;
const int stopAngle = 87;
ContinuousServo::ContinuousServo(int servoPin) {
    this->servoPin = servoPin;
}

void ContinuousServo::setup() {
    this->servo.attach(servoPin);
    delay(1000);

    this->initAngle = servo.read();
    
    Serial.print("Init angle: ");
    Serial.println(this->initAngle);

    this->servo.write(stopAngle);
}

void ContinuousServo::rotate(bool clockwise) {  
    int currentAngle = servo.read();
    Serial.print("Current angle: ");
    Serial.println(currentAngle);
    if(clockwise) {
        Serial.println("Rotating clockwise");
        this->servo.write(stopAngle-defaultStep);
    } else {
        Serial.println("Rotating counter clockwise");
        this->servo.write(stopAngle+defaultStep);
    }
    delay(15);
}

void ContinuousServo::stop() {
    this->servo.write(stopAngle);
}
