#include "LiftingSystem.h"
#include "ContinuousServo.h"

class ServoLiftingSystem: public LiftingSystem {
  public:
    ServoLiftingSystem(int servoPin);
    void setup();
    void startRaising();
    void startLowering(); 
    void stop();
    void loop();

  private:
    int servoPin;
    int state;
    ContinuousServo* servo;
};
