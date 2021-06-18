#include "common.h"
#include "Clock_Manager.h"
#include "Frame_Commander.h"

unsigned char CMD0 = 0x40;
unsigned char CRC = 0x95;
unsigned char dummy = 0x1FFFFFFFFFFFFFFFFFFF;

void setup() {
    pinMode(MISO, INPUT);
    pinMode(CS, OUTPUT);
    pinMode(SCLK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    
    delay(1500);
    
    digitalWrite(CS, HIGH);
    
    Clock_Manager clock_manager;
    clock_manager.CLOCK_TIME = FAST_CLOCK;
    
    Frame_Commander frame_commander;
    
    frame_commander.send_data(dummy, 75);
    
    digitalWrite(CS, LOW);
    
    frame_commander.send_data(CMD0, 8);
    frame_commander.send_data(0x00000000, 32);
    frame_commander.send_data(CRC, 8);
   
    clock_manager.CLOCK_TIME = SLOW_CLOCK;
    for (int i = 0; i < 72; i++) {
        Serial.print(digitalRead(MISO));
        clock_manager.send_bit(1);
    }
    clock_manager.CLOCK_TIME = FAST_CLOCK;
}

void loop(void) {}

