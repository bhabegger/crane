#include <Servo.h>
#include "Arduino.h"
#include "ContinuousServo.h"

ContinuousServo::ContinuousServo(int servoPin) {
    this->servoPin = servoPin;
    this->servo.attach(servoPin);
}

void ContinuousServo::setup() {
    this->stopAngle = servo.read(); // read the angle which will never change as potentiometer is unplugged
    this->clockwiseAngle = 150;
    this->counterClockwiseAngle = 20;
    
    Serial.print("stop angle: ");
    Serial.println(this->stopAngle);
}

void ContinuousServo::rotate(bool clockwise) {  
    if(clockwise) {
        Serial.println("Rotating clockwise with angle: ");
        Serial.println(this->clockwiseAngle);
        int pos;
        for (pos = this->stopAngle; pos <= 180; pos += 1) {
          this->servo.write(pos);
          delay(15);
        }
        
    } else {
        Serial.println("Rotating counter clockwise with angle: ");
        Serial.println(this->counterClockwiseAngle);
        this->servo.write(this->clockwiseAngle);
    }
}

void ContinuousServo::stop() {
    this->servo.write(this->stopAngle);
}
