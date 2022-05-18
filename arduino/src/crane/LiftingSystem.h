#include "ContinuousServo.h"

class LiftingSystem {
    public:
        LiftingSystem(int raiseButtonPin, int lowerButtonPin, int servoPin);
        void setup();
        void cycle();

    private:
        int raiseButtonPin;
        int lowerButtonPin;
        int servoPin;
        int stopAngle;
        int raiseAngle;
        int lowerAngle;
        ContinuousServo* servo;
};