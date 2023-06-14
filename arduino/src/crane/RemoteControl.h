#include "Action.h"
#include "ArxContainer.h"
#define DECODE_NEC

#define REMOTE_1 0x45
#define REMOTE_2 0x46
#define REMOTE_3 0x47
#define REMOTE_4 0x44
#define REMOTE_5 0x40
#define REMOTE_6 0x43
#define REMOTE_7 0x07
#define REMOTE_8 0x15
#define REMOTE_9 0x09
#define REMOTE_0 0x19
#define REMOTE_STAR 0x16
#define REMOTE_HASH 0xD
#define REMOTE_LEFT 0x8
#define REMOTE_UP 0x18
#define REMOTE_RIGHT 0x5A
#define REMOTE_DOWN 0x52
#define REMOTE_OK 0x1C

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