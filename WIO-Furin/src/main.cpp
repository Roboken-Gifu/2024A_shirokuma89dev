#include <Arduino.h>

#include "device.h"

void setup() {
    Serial.begin(115200);
    Serial.println("[INFO] LaunchPack - Start");

    initDevice();
}

void loop() {
    const int DashSpeed = 60;
    
    bldc.speed[0] -= DashSpeed;
    bldc.speed[1] += DashSpeed;
    bldc.write();

    subMcu.setPumpOn(true);
    const int Period = 2000;

    subMcu.setBoxhold(true);
    delay(Period);
    subMcu.setBoxhold(false);
    delay(Period);
    subMcu.setLock(true);
    delay(Period);
    subMcu.setLock(false);
    delay(Period);
}