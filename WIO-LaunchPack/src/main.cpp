#include <Arduino.h>

#include "device.h"


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial1.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}