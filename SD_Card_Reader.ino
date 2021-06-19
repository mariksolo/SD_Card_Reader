#include "common.h"
#include "Clock_Manager.h"
#include "Frame_Commander.h"

unsigned char CMD0 = 0x40;
unsigned char CRC = 0x95;
unsigned char dummy = 0xFF;

void setup() {
    pinMode(MISO, INPUT);
    pinMode(CS, OUTPUT);
    pinMode(SCLK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    
    delay(1500);
    
    digitalWrite(CS, HIGH);
    
    Clock_Manager clock_manager;
    clock_manager.CLOCK_TIME = FAST_CLOCK;
    
    Frame_Commander frame_commander(1, CMD0, 0x00000000);
    /*
     *A binary number of 80 1's is too large to store in an unsigned char.
     */
    for (int i = 0; i < 10; i++) {
        frame_commander.send_data(dummy, 8);
    }
    
    digitalWrite(CS, LOW);
    
    frame_commander.send_command_frame();
    frame_commander.recieve_data(); 

    Serial.print(frame_commander.recieved_data, BIN);
}

void loop(void) {}

