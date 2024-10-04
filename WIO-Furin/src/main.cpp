#include <Arduino.h>

#include "device.h"

void setup() {
    Serial.begin(115200);
    Serial.println("[INFO] LaunchPack - Start");

    initDevice();
}

void loop() {
    int deg = gyro.read();

    if (deg > 180) {
        deg -= 360;
    }

    deg *= 0.3;
    Serial.println(deg);

    bldc.speed[0] = -deg;
    bldc.speed[1] = -deg;

    bldc.speed[0] -= 60;
    bldc.speed[1] += 60;

    // bldc.speed[0] = -50;
    // bldc.speed[1] = 50;
    bldc.write();
    // Serial.println("[INFO] Set Motor Speed");
    // delay(5000);

    // bldc.speed[0] = 0;
    // bldc.speed[1] = 0;
    // bldc.write();
    // Serial.println("[INFO] Stopped Motor");
    // delay(10000);
}