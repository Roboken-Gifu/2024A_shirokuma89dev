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

    wheelMotor[0] = 100;
    wheelMotor[1] = 100;
    Serial.println("[INFO] Set Motor Speed");
    delay(3000);

    wheelMotor[0] = 0;
    wheelMotor[1] = 0;
    Serial.println("[INFO] Stopped Motor");
    delay(3000);

    subMcu.setBldcRotation(true);
    Serial.println("[INFO] Enabled BLDC");
    delay(5000);

    subMcu.pushBall();
    Serial.println("[INFO] Pushed Ball");
    delay(3000);

    subMcu.setBldcRotation(false);
    Serial.println("[INFO] Disabled BLDC");
    delay(5000);
}