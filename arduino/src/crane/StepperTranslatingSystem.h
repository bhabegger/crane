#include "TranslatingSystem.h"
#include <AccelStepper.h>

class StepperTranslatingSystem: public TranslatingSystem {
    public:
        StepperTranslatingSystem(int pin1, int pin2, int pin3, int pin4);
        void setup();
        void startMovingForward();
        void startMovingBackward();
        void stop();
        void loop();
    private:
      AccelStepper* stepper;
      int rear;
      int front;
};
