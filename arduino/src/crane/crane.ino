#include<Servo.h>
#include "Button.h"
#include "RemoteControl.h"
#include "LiftingSystem.h"

LiftingSystem liftingSystem(9);
Button btnLiftUp(4);
Button btnLiftDown(5);
RemoteControl remoteControl(2);

void setup() {
    Serial.begin(115200);
    Serial.println("Setting up...");
    Serial.print("File: ");
    Serial.println(__FILE__ );
    Serial.print("Date: ");
    Serial.println(__DATE__);

    liftingSystem.setup();

    btnLiftUp.setup();
    btnLiftUp.onPress([&](){ liftingSystem.startRaising(); });
    btnLiftUp.onRelease([&](){ liftingSystem.stopRaising(); });

    btnLiftDown.setup();
    btnLiftDown.onPress([&](){ liftingSystem.startLowering(); });
    btnLiftDown.onRelease([&](){ liftingSystem.stopLowering(); });

    remoteControl.onCommand(REMOTE_UP, [&](){ liftingSystem.startRaising(); });
    remoteControl.onCommand(REMOTE_OK, [&](){ liftingSystem.stopLowering(); });
    remoteControl.onCommand(REMOTE_DOWN, [&](){ liftingSystem.startLowering(); });
    remoteControl.setup();

    Serial.println("Done.");
}

void loop() {
    btnLiftUp.loop();
    btnLiftDown.loop();
    remoteControl.loop();
    liftingSystem.loop();
}
