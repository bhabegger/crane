#include "Arduino.h"
#include "RemoteControl.h"
#include <IRremote.hpp>
#define ENABLE_LED_FEEDBACK true

RemoteControl::RemoteControl(int pin) {
    this->pin = pin;
}

void RemoteControl::setup() {
    pinMode(this->pin, INPUT);

    Serial.print("IRemote version: ");
    Serial.println(VERSION_IRREMOTE);

    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(this->pin, ENABLE_LED_FEEDBACK);
    Serial.print("Ready to receive IR signals of protocols: ");
    printActiveIRProtocols(&Serial);
    Serial.print("at pin ");
    Serial.println(this->pin);
}

void RemoteControl::onCommand(int commandCode, void (*callback)()) {
    Serial.print("Setting onCommand callback on remote control pin ");
    Serial.print(this->pin);
    Serial.print(" for command ");
    Serial.print(commandCode);
    Serial.println(".");
    (this->commandMap)[commandCode] = callback;
}

void RemoteControl::loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();

        if (IrReceiver.decodedIRData.address == 0) {
            Serial.print("Received ");
            Serial.println(IrReceiver.decodedIRData.command);
            arx::map<int,void (*)()>::iterator it = this->commandMap.find(IrReceiver.decodedIRData.command);
            if(it != this->commandMap.end()) {
                Serial.print("Executing command for code ");
                Serial.println(it->first);
                it->second();
            }
        }
    }
}
