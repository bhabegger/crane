class TranslatingSystem {
    public:
        virtual void setup();
        virtual void startMovingForward();
        virtual void startMovingBackward();
        virtual void stop();
        virtual void loop();
};
