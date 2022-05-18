class TrackingSystem {
    public:
        TrackingSystem(int forwardButtonPin, int backwardButtonPin, int servoPin);
        void setup();
        void cycle();

    private:
        int forwardButtonPin;
        int backwardButtonPin;
        int servoPin;
};