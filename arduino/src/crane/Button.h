#include "Action.h"

class Button {
    public:
        Button(int pin);
        void setup();
        void loop();
        void onPress(ActionPtr);
        void onRelease(ActionPtr);

    private:
        int pin;
        int state;
        ActionPtr onPressCallback;
        ActionPtr onReleaseCallback;
};
