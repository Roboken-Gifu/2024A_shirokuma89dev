#include "pwmMotor.h"

PWM_MOTOR::PWM_MOTOR(int pin1, int pin2) {
    this->pin1 = pin1;
    this->pin2 = pin2;

    pinMode(this->pin1, OUTPUT);
    pinMode(this->pin2, OUTPUT);
}

void PWM_MOTOR::drive(int speed) {
    if (speed == 0) {
        analogWrite(this->pin1, 0);
        analogWrite(this->pin2, 0);

        return;
    }

    if (speed > 0) {
        analogWrite(this->pin1, 0);
        analogWrite(this->pin2, speed);
    } else {
        analogWrite(this->pin2, 0);
        analogWrite(this->pin1, -speed);
    }
}

int PWM_MOTOR::operator=(int speed) {
    this->drive(speed);

    return speed;
}