#include "motor_pulse.h"

MOTOR_PULSE::MOTOR_PULSE(int pin) {
    this->pin = pin;
    this->motor_device.attach(pin);
}

void MOTOR_PULSE::write(float value) {
    int sig = (MOTOR_PULSE_SIG_MAX - MOTOR_PULSE_SIG_MIN) * value +
              MOTOR_PULSE_SIG_MIN;
    this->motor_device.writeMicroseconds(sig);

    // Serial.println(sig);
}

float MOTOR_PULSE::operator=(float value) {
    this->write(value);
    return value;
}

void MOTOR_PULSE::init(MOTOR_PULSE* esc_arr, int esc_num) {
    delay(3000);

    for (int i = 0; i < esc_num; i++) {
        esc_arr[i] = 1.0;
    }
    delay(3000);

    for (int i = 0; i < esc_num; i++) {
        esc_arr[i] = 0.0;
    }
    delay(1000);
}

void MOTOR_PULSE::ballPush(bool isPush) {
    if (!isPush) {
        this->write(0.5);
    } else {
        this->write(0.1);
    }
}