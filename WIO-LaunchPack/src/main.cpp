#include <Arduino.h>

#include "device.h"

void setup() {
    Serial.begin(115200);
    Serial.println("[INFO] LaunchPack - Start");

    initDevice();
}

void loop() {
    int deg = gyro.read();
    Serial.println(deg);

    motor[0] = 100;
    motor[1] = 100;
    Serial.println("[INFO] Set Motor Speed");
    delay(3000);

    motor[0] = 0;
    motor[1] = 0;
    Serial.println("[INFO] Stop Motor");
    delay(3000);

    sub_mcu.enableBldc(true);
    Serial.println("[INFO] Enabled BLDC");
    delay(5000);

    sub_mcu.pushBall(true);
    Serial.println("[INFO] Pushed Ball");
    delay(3000);

    sub_mcu.enableBldc(false);
    Serial.println("[INFO] Disabled BLDC");
    delay(5000);
}