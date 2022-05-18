#include<Servo.h>
#include "LiftingSystem.h"

LiftingSystem liftingSystem(
    4, // Raise pin
    5, // Lower pin
    9  // Servo pin
);

void setup() {
    liftingSystem.setup();
}

void loop() {
    liftingSystem.cycle();
}