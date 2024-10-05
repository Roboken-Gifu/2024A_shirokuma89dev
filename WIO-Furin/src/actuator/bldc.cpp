#include "bldc.h"

BLDC::BLDC(Uart *serial) {
    this->serial = serial;
}

void BLDC::enableUart(void) {
    this->serial->begin(this->baudrate);
}

void BLDC::write() {
    speed[0] = constrain(speed[0], -100, 100);
    speed[1] = constrain(speed[1], -100, 100);

    char sendDataA = ((uint8_t)this->speed[0] >> 1) & 0B01111111;
    char sendDataB = ((uint8_t)this->speed[1] >> 1) | 0B10000000;

    this->serial->write(0B11111111);
    this->serial->write(0B11111111);
    this->serial->write(sendDataA);
    this->serial->write(sendDataB);
}