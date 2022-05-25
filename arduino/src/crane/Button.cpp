#include "Arduino.h"
#include "Button.h"

Button::Button(int pin) {
    this->pin = pin;
}

void Button::setup() {
    pinMode(this->pin, INPUT);
    this->state = digitalRead(this->pin);
    
    Serial.print("Button on pin");
    Serial.print(this->pin);
    Serial.print(" ready with initial state: ");
    Serial.println(this->state);
}

void Button::onPress(void (*callback)()) {
    Serial.print("Setting onPress callback for button pin ");
    Serial.print(this->pin);
    Serial.println(".");
    this->onPressCallback = callback;
}

void Button::onRelease(void (*callback)()) {
    Serial.print("Setting onRelease callback for button pin ");
    Serial.print(this->pin);
    Serial.println(".");
    this->onReleaseCallback = callback;
}

void Button::loop() {
    int newState = digitalRead(this->pin);
    if(newState != this->state) {
        Serial.print("Updating state of button pin ");
        Serial.print(this->pin);
        Serial.print(": ");
        Serial.println(newState);
        this->state = newState;
        if(this->state == HIGH && this->onPressCallback) {
            this->onPressCallback();
        } else if(this->onReleaseCallback) {
            this->onReleaseCallback();
        }
    }
}
