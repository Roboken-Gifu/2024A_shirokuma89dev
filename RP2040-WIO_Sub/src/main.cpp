#include <Arduino.h>

#include "actuator/motor_pulse.h"
MOTOR_PULSE esc[2] = {MOTOR_PULSE(11), MOTOR_PULSE(12)};
MOTOR_PULSE servo = MOTOR_PULSE(13);

bool shouldPush = false;
bool esc_enabled = false;

const float esc_power = 1.0;

void setup() {
    Serial.begin(115200);
    Serial.println("Start");

    Serial1.begin(115200);

    servo.ballPush(false);
    MOTOR_PULSE::init(esc);
}

void loop() {
    if (Serial1.available()) {
        char data = Serial1.read();

        if ((data & 0x01) == 0x01) {
            shouldPush = true;
        } else {
            shouldPush = false;
        }

        if ((data & 0x02) == 0x02) {
            esc_enabled = true;
        } else {
            esc_enabled = false;
        }
        Serial.println(data);

        while (Serial1.available()) {
            Serial1.read();
        }
    }

    if (esc_enabled) {
        esc[0] = esc[1] = esc_power;
    } else {
        esc[0] = esc[1] = 0.0;
    }

    if (shouldPush) {
        servo.ballPush(true);
        delay(500);
        shouldPush = false;
    } else {
        servo.ballPush(false);
    }
}