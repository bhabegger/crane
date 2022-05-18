class LiftingSystem {
    public:
        LiftingSystem(int clockwiseButtonPin, int counterClockwiseButtonPin, int servoPin);
        void setup();
        void cycle();

    private:
        int clockwiseButtonPin;
        int counterClockwiseButtonPin;
        int servoPin;
};