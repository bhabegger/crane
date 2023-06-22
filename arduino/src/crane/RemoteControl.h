#include "Action.h"
#include "ArxContainer.h"
//#define DECODE_NEC
//#define DECODE_RC5
#define DECODE_SAMSUNG
   
#define REMOTE_1 0x4
#define REMOTE_2 0x5
#define REMOTE_3 0x6
#define REMOTE_4 0x8
#define REMOTE_5 0x9
#define REMOTE_6 0xA
#define REMOTE_7 0xC
#define REMOTE_8 0xD
#define REMOTE_9 0xE
#define REMOTE_0 0x11
#define REMOTE_STAR 0x16
#define REMOTE_HASH 0xD
#define REMOTE_LEFT 0x65
#define REMOTE_UP 0x60
#define REMOTE_RIGHT 0x62
#define REMOTE_DOWN 0x61
#define REMOTE_OK 0x68
#define REMOTE_VOL_UP 0x7
#define REMOTE_VOL_DOWN 0xB

class RemoteControl {
    public:
        RemoteControl(int pin);
        void setup();
        void loop();
        void onCommand(int, ActionPtr);

    private:
        int pin;
        arx::map<int, ActionPtr> commandMap;
};
