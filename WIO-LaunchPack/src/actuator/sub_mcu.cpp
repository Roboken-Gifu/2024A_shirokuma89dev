#include "sub_mcu.h"

SUB_MCU::SUB_MCU(HardwareSerial *serial) {
    this->serial = serial;
    this->sendData = 0;
    this->shouldBldcEnable = false;
    this->shouldPushBall = false;

    this->serial->begin(115200);
}

void SUB_MCU::send(void) {
    sendData = (shouldBldcEnable << 1) | shouldPushBall;
    this->serial->write(this->sendData);

    this->shouldPushBall = false;
}

void SUB_MCU::enableBldc(bool enable) {
    this->shouldBldcEnable = enable;
    this->send();
}

void SUB_MCU::pushBall(bool push) {
    this->shouldPushBall = push;
    this->send();
}