#ifndef INITIALIZER
#define INITIALIZER

class Initializer {
    public:
        Clock_Manager clock_manager;
        Frame_Commander frame_commander; 

        Initializer(double clock_time);

        void init_card();
};
#endif
