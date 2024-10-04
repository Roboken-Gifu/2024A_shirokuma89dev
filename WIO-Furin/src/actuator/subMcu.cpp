// #include "subMcu.h"

// SUB_MCU::SUB_MCU(Uart *serial) {
//     this->serial = serial;
//     this->sendData = 0;
//     this->shouldBldcEnable = false;
//     this->shouldPushBall = false;
// }

// void SUB_MCU::enableUart(void) {
//     this->serial->begin(this->baudrate);
// }

// void SUB_MCU::send(void) {
//     sendData = (shouldBldcEnable << 1) | shouldPushBall;
//     this->serial->write(this->sendData);

//     this->shouldPushBall = false;
// }

// void SUB_MCU::setBldcRotation(bool enable) {
//     this->shouldBldcEnable = enable;
//     this->send();
// }

// void SUB_MCU::pushBall(void) {
//     this->shouldPushBall = true;
//     this->send();
// }