#include "LiftingSystem.h"
#include <AccelStepper.h>

class StepperLiftingSystem: public LiftingSystem {
    public:
        StepperLiftingSystem(int pin1, int pin2, int pin3, int pin4);
        void setup();
        void startRaising();
        void startLowering();
        void stop();
        void loop();
    private:
      AccelStepper* stepper;
      int bottom;
      int top;
};
