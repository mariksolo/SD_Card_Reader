#include "Clock_Manager.h"
#include "Frame_Commander.h"
#include "common.h"

Frame_Commander::Frame_Commander(unsigned char init_r_type, unsigned char init_cmd, unsigned char init_args) {
    clock_manager.CLOCK_TIME = FAST_CLOCK;
    r_type = init_r_type;
    cmd = init_cmd;
    args = init_args;
    crc = 0x95;
}

void Frame_Commander::send_data(unsigned char data, int n) {
    for (int i = 0; i < n; i++) {
        /*
         *Checks if first bit in byte is a 1, sends it if it is, then shifts to
         move on to next bit.
         */
        if (data >= pow(2.0, n - 1.0)) {
            clock_manager.send_bit(1);
        } else {
            clock_manager.send_bit(0);
        }
        data = data << 1;
    }
}

void Frame_Commander::send_command_frame() {
    switch (r_type) {
        case 1:
            send_data(cmd, 8);
            send_data(args, 32);
            send_data(crc, 8);
            break;

    }

}
