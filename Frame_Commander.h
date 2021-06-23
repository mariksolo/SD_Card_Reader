#ifndef FRAME_COMMANDER
#define FRAME_COMMANDER
class Frame_Commander {
    public:
        Frame_Commander(unsigned char init_r_type, unsigned char init_cmd, unsigned char init_arg1, unsigned char init_arg2, unsigned char init_arg3, unsigned char init_arg4);
        Frame_Commander();
        unsigned char r_type;
        unsigned char recieved_data;
        unsigned char cmd;
        unsigned char arg1;
        unsigned char arg2;
        unsigned char arg3;
        unsigned char arg4;
        unsigned char crc;

        Clock_Manager clock_manager;
        
        void send_data(unsigned char data, int n);
        void recieve_data();
        void send_command_frame();
};

#endif
