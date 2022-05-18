#include<Servo.h>

class ContinuousServo {
    public:
        ContinuousServo(int servoPin);
        void setup();
        void rotate(bool clockwise);
        void stop();

    private:
        int servoPin;
        int stopAngle;
        int clockwiseAngle;
        int counterClockwiseAngle;
        Servo servo;
};
