#include "TranslatingSystem.h"
#include "ContinuousServo.h"

class ServoTranslatingSystem: public TranslatingSystem {
    public:
        ServoTranslatingSystem(int pin);
        void setup();
        void startMovingForward();
        void startMovingBackward();
        void stop();
        void loop();

  private:
    int servoPin;
    int state;
    ContinuousServo* servo;
};
