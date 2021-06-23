#include "common.h"
#include "Clock_Manager.h"
#include "Frame_Commander.h"
#include "Initializer.h"

void setup() {
    delay(1500);
    Initializer initializer(FAST_CLOCK);
    initializer.init_card();
}

void loop(void) {}

