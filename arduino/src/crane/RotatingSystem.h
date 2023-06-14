class RotatingSystem {
    public:
        virtual void setup();
        virtual void startRotatingClockwise();
        virtual void startRotatingCounterClockwise(); 
        virtual void stop();
        virtual void loop();
};
