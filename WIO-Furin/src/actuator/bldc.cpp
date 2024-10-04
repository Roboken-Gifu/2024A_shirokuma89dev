#ifndef _BLDC_H_
#define _BLDC_H_

#include "bldc.h"

BLDC::BLDC(Uart *serial) {
    this->serial = serial;
}

void BLDC::enableUart(void) {
    this->serial->begin(this->baudrate);
}

void BLDC::write() {
    char sendDataA = ((uint8_t)this->speed[0] >> 1) & 0B01111111;
    char sendDataB = ((uint8_t)this->speed[1] >> 1) | 0B10000000;

    // Serial.println(sendData[2], BIN);

    this->serial->write(0B11111111);
    // delayMicroseconds(500);
    this->serial->write(0B11111111);
    // delayMicroseconds(500);
    this->serial->write(sendDataA);
    // delayMicroseconds(500);
    this->serial->write(sendDataB);
    // delayMicroseconds(500);
}

#endif