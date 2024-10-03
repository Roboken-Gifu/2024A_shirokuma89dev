#include "motor.h"

MOTOR::MOTOR(int pin1, int pin2) {
    this->pin1 = pin1;
    this->pin2 = pin2;

    pinMode(this->pin1, OUTPUT);
    pinMode(this->pin2, OUTPUT);
}

void MOTOR::drive(int speed) {
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

int MOTOR::operator=(int speed) {
    this->drive(speed);

    return speed;
}