#ifndef _SUB_MCU_H
#define _SUB_MCU_H

#include <Arduino.h>

class SUB_MCU {
   private:
    Uart *serial;
    char sendData;
    bool shouldBldcEnable;
    bool shouldPushBall;

    const int baudrate = 115200;

   public:
    SUB_MCU(Uart *serial);

    void enableUart(void);

    void send(void);
    void setBldcRotation(bool enable);
    void pushBall(void);
};

#endif