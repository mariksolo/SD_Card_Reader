#include "Frame_Commander.h"
#include "Clock_Manager.h"
#include "common.h"
#include "commands.h"

Initializer::Initializer (double clock_time) {
    clock_manager.CLOCK_TIME = clock_time;
}

void Initializer::init_card() {
    pinMode(MISO, INPUT);
    pinMode(CS, OUTPUT);
    pinMode(SCLK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    
    digitalWrite(CS, HIGH);

    unsigned char dummy = 0xFF;

    frame_commander.clock_manager.CLOCK_TIME = FAST_CLOCK;
    frame_commander.r_type = 1;
    frame_commander.cmd = CMD0;
    frame_commander.arg1 = 0x00; 
    frame_commander.arg2 = 0x00; 
    frame_commander.arg3 = 0x00; 
    frame_commander.arg4 = 0x00;
    frame_commander.crc = INIT_CRC;

    /*
     *A binary number of 80 1's is too large to store in an unsigned char.
     */
    for (int i = 0; i < 10; i++) {
        frame_commander.send_data(dummy, 8);
    }
    
    /*digitalWrite(CS, LOW);*/
    
    /*
     *Sets to SPI mode
     */
    frame_commander.send_command_frame();

    /*Serial.println(frame_commander.recieved_data, HEX);*/

    frame_commander.r_type = 3;
    frame_commander.cmd = CMD8;
    frame_commander.arg1 = 0x00; 
    frame_commander.arg2 = 0x00; 
    frame_commander.arg3 = 0x01; 
    frame_commander.arg4 = 0xAA;

    frame_commander.crc = CMD8_CRC;

    frame_commander.send_command_frame();
    /*Serial.println(frame_commander.recieved_data, HEX);*/


    /*
     *Initializes card 
     */
    frame_commander.r_type = 1;
    frame_commander.arg1 = 0x00; 
    frame_commander.arg2 = 0x00; 
    frame_commander.arg3 = 0x00; 
    frame_commander.arg4 = 0x00;

    while (frame_commander.recieved_data != 0) {
        frame_commander.cmd = CMD55;
        frame_commander.crc = CMD55_CRC;
        frame_commander.arg1 = 0x00;
        frame_commander.send_command_frame();
        /*Serial.println(frame_commander.recieved_data, HEX);*/

        frame_commander.cmd = ACMD41;
        frame_commander.crc = ACMD41_CRC;
        frame_commander.arg1 = 0x60;
        frame_commander.send_command_frame();
        /*Serial.println(frame_commander.recieved_data, HEX);*/
    }

    Serial.println(frame_commander.recieved_data, BIN);

    frame_commander.cmd = CMD58;
    frame_commander.r_type = 3;
    frame_commander.send_command_frame();

    Serial.println(frame_commander.recieved_data);
    Serial.println("got here");
    /*for (int i = 0; i < 144; i++) {*/
        /*frame_commander.clock_manager.send_bit(1);*/
        /*Serial.println(digitalRead(MISO));*/
    /*}*/

}
