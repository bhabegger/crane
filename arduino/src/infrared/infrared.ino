#include <Arduino.h>

/*
 * Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols are active.
 * This must be done before the #include <IRremote.hpp>
 */
//#define DECODE_LG
#define DECODE_NEC
// etc. see IRremote.hpp
#include <IRremote.hpp>

#define ENABLE_LED_FEEDBACK true
const int IR_RECEIVE_PIN = 2;

void setup() {
    Serial.begin(115200);
    Serial.print("File: ");
    Serial.println(__FILE__ );
    Serial.print("Date: ");
    Serial.println(__DATE__);
    Serial.print("IRemote version: ");
    Serial.println(VERSION_IRREMOTE);

    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print("Ready to receive IR signals of protocols: ");
    printActiveIRProtocols(&Serial);
    Serial.print("at pin ");
    Serial.println(IR_RECEIVE_PIN);
}

void loop() {
    if (IrReceiver.decode()) {
        // Serial.println();
        // IrReceiver.printIRResultShort(&Serial);
        IrReceiver.resume();

        /*
         * Finally check the received data and perform actions according to the received address and commands
         */
        char character = 'x';
        if (IrReceiver.decodedIRData.address == 0) {
          switch (IrReceiver.decodedIRData.command) {
            case 0x45:
              character = '1';
              break;
            case 0x46:
              character = '2';
              break;
            case 0x47:
              character = '3';
              break;
            case 0x44:
              character = '4';
              break;
            case 0x40:
              character = '5';
              break;
            case 0x43:
              character = '6';
              break;
            case 0x07:
              character = '7';
              break;
            case 0x15:
              character = '8';
              break;
            case 0x09:
              character = '9';
              break;
            case 0x16:
              character = '*';
              break;
            case 0x19:
              character = '0';
              break;
            case 0xD:
              character = '#';
              break;
            case 0x8:
              character = '<';
              break;
            case 0x18:
              character = '^';
              break;
            case 0x5A:
              character = '>';
              break;
            case 0x52:
              character = '_';
              break;
            case 0x1c:
              character = '!';
              break;
          }

          Serial.println(character);
        }
    }
}
