#include<Servo.h>
#include "Button.h"
#include "LiftingSystem.h"

LiftingSystem liftingSystem(9);
Button btnLiftUp(4);
Button btnLiftDown(5);

void setup() {
    Serial.begin(115200);
    Serial.println("Setting up...");
    liftingSystem.setup();

    btnLiftUp.setup();
    btnLiftUp.onPress([&](){ liftingSystem.startRaising(); });
    btnLiftUp.onRelease([&](){ liftingSystem.stopRaising(); });

    btnLiftDown.setup();
    btnLiftDown.onPress([&](){ liftingSystem.startLowering(); });
    btnLiftDown.onRelease([&](){ liftingSystem.stopLowering(); });
    
    Serial.println("Done.");
}

void loop() {
    btnLiftUp.loop();
    btnLiftDown.loop();
    liftingSystem.loop();
}
