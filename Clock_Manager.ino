#include "common.h"
#include "Clock_Manager.h"

void Clock_Manager::send_bit(int bit) {
    digitalWrite(MOSI, HIGH  * bit);
    digitalWrite(SCLK, HIGH);
    delay(CLOCK_TIME / 2.0);
    digitalWrite(SCLK, LOW);
    delay(CLOCK_TIME / 2.0);
}
