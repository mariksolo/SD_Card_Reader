#ifndef FRAME_COMMANDER
#define FRAME_COMMANDER
class Frame_Commander {
    public:
        unsigned char r_type;
        unsigned char response;
        unsigned char cmd;
        unsigned char args;
        unsigned char crc;
        
        void send_data(unsigned char data, int n);
};

#endif
