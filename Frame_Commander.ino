#include "Clock_Manager.h"
#include "Frame_Commander.h"
#include "common.h"

void Frame_Commander::send_data(unsigned char data, int n) {
    Clock_Manager clock_manager;
    clock_manager.CLOCK_TIME = FAST_CLOCK;
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
