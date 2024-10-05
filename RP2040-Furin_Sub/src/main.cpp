#include <Arduino.h>
#include <Wire.h>

#define PIN_PUMP 13

#include "./servo_util/servo_util.h"
#define PIN_LOCK 10
#define PIN_BOX_HOLDER 11
#define pin_servo3 14
ServoUtil servoUtil(PIN_LOCK, PIN_BOX_HOLDER);

bool shouldPumpOn = false;
bool shouldLock = true;
bool shouldHold = true;

void receiveEvent(int howMany) {
    char data = 0;

    while (Wire.available() > 0) {
        data = Wire.read();

        if (data == 'P') {
            shouldPumpOn = true;
        } else if (data == 'p') {
            shouldPumpOn = false;
        } else if (data == 'L') {
            shouldLock = true;
        } else if (data == 'l') {
            shouldLock = false;
        } else if (data == 'H') {
            shouldHold = true;
        } else if (data == 'h') {
            shouldHold = false;
        }
    }
}

void setup() {
    Wire.begin(0x08);
    Wire.onReceive(receiveEvent);
}

void loop() {
    if (shouldPumpOn) {
        digitalWrite(PIN_PUMP, HIGH);
    } else {
        digitalWrite(PIN_PUMP, LOW);
    }

    servoUtil.setLock(shouldLock);
    servoUtil.setBoxHolder(shouldHold);

    // 動作確認用
    // unsigned long timer = millis();
    // while (millis() - timer < 6000) {
    //     digitalWrite(PIN_PUMP, HIGH);
    //     servoUtil.setLock(false);
    //     servoUtil.setBoxHolder(false);
    // }

    // timer = millis();
    // while (millis() - timer < 5000) {
    //     servoUtil.setLock(true);
    //     servoUtil.setBoxHolder(true);
    // }
}