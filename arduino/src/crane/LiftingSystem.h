class LiftingSystem {
    public:
        virtual void setup();
        virtual void startRaising();
        virtual void startLowering(); 
        virtual void stop();
        virtual void loop();
};
