#ifndef _SUB_MCU_H
#define _SUB_MCU_H

#include <Arduino.h>

class SUB_MCU {
   private:
    HardwareSerial *serial;
    char sendData;
    bool shouldBldcEnable;
    bool shouldPushBall;

   public:
    SUB_MCU(HardwareSerial *serial);

    void send(void);
    void enableBldc(bool enable);
    void pushBall(bool push);
};

#endif