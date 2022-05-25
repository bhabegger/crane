class Button {
    public:
        Button(int pin);
        void setup();
        void loop();
        void onPress(void (*)());
        void onRelease(void (*)());

    private:
        int pin;
        int state;
        void (*onPressCallback)();
        void (*onReleaseCallback)();
};