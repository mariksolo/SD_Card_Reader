#include "Clock_Manager.h"
#include "Frame_Commander.h"
#include "common.h"
#include "commands.h"

Frame_Commander::Frame_Commander(unsigned char init_r_type, unsigned char init_cmd, unsigned char init_arg1, unsigned char init_arg2, unsigned char init_arg3, unsigned char init_arg4) {
    clock_manager.CLOCK_TIME = FAST_CLOCK;
    r_type = init_r_type;
    cmd = init_cmd;
    arg1 = init_arg1;
    arg2 = init_arg2;
    arg3 = init_arg3;
    arg4 = init_arg4;
    crc = INIT_CRC;
}

Frame_Commander::Frame_Commander() {
    clock_manager.CLOCK_TIME = FAST_CLOCK;
    r_type = 1;
    cmd = CMD0;
    arg1 = 0x00;
    arg2 = 0x00;
    arg3 = 0x00;
    arg4 = 0x00;
    crc = INIT_CRC;
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

void Frame_Commander::recieve_data() {
    int current_bit;
    int expected_bit_count;
    switch (r_type) {
        case 1:
            expected_bit_count = 8;
            break;
        case 3:
            expected_bit_count = 40;
            break;
    }
    recieved_data = 0;
    bool did_recieve_data = false;
    for (int i = 0; i < 72; i++) {
        clock_manager.send_bit(1);
        current_bit = digitalRead(MISO);
        if (current_bit == 0) {
            did_recieve_data = true;
            for (int j = expected_bit_count - 2; j >= 0; j--) {
                clock_manager.send_bit(1);
                current_bit = digitalRead(MISO);        
                /*Serial.print(current_bit);*/
                recieved_data += current_bit * pow(2.0, j);
             }
             break;
        }
    }

    if (!did_recieve_data)
        recieved_data = -1;
}

void Frame_Commander::send_command_frame() {
    digitalWrite(CS, LOW);
    send_data(0xFF, 8);
    /*Serial.println("Current CMD: ");*/
    /*Serial.println(cmd, HEX);*/
    /*Serial.println("Current CRC: ");*/
    /*Serial.println(crc, HEX);*/
    send_data(cmd, 8);
    send_data(arg1, 8);
    send_data(arg2, 8);
    send_data(arg3, 8);
    send_data(arg4, 8);
    send_data(crc, 8);
    recieve_data();
    digitalWrite(CS, HIGH);

}
