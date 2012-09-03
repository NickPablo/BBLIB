#include <iostream>
#include "Ping.hpp"
#include "DigitalPin.hpp"




extern "C" {
#include <bbio.h>
//#include <gperf_pinMap.h>
}
using namespace std;

bool isDebugMode() {
    //true  : debug
    //false : run
    const char *pin = "P8_3";
    DigitalPin gate(pin);
    bool value = gate.get();
    return value;
}

int main() {
    DigitalPin pin("P8_3");
    
    pin.on();
    sleep(3);
    pin.off();

    return 0;
}
