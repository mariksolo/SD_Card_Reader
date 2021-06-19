#ifndef FRAME_COMMANDER
#define FRAME_COMMANDER
class Frame_Commander {
    public:
        Frame_Commander(unsigned char init_r_type, unsigned char init_cmd, unsigned char init_args);
        unsigned char r_type;
        unsigned char response;
        unsigned char cmd;
        unsigned char args;
        unsigned char crc;

        Clock_Manager clock_manager;
        
        void send_data(unsigned char data, int n);
        void send_command_frame();
};

#endif
