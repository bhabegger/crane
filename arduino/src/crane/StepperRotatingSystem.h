#include "RotatingSystem.h"
#include <AccelStepper.h>

class StepperRotatingSystem: public RotatingSystem {
    public:
        StepperRotatingSystem(int pin1, int pin2, int pin3, int pin4);
        void setup();
        void startRotatingClockwise();
        void startRotatingCounterClockwise();
        void stop();
        void loop();
    private:
      AccelStepper* stepper;
      int counterClockwiseExtreme;
      int clockwiseExtreme;
};
