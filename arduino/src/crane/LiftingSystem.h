#include "ContinuousServo.h"

class LiftingSystem {
    public:
        LiftingSystem(int servoPin);
        void setup();
        void startRaising();
        void stopRaising();
        void startLowering();
        void stopLowering();
        void loop();

    private:
        int servoPin;
        int state;
        ContinuousServo* servo;
};
