#ifndef _SUB_MCU_H
#define _SUB_MCU_H

#include <Arduino.h>

class BLDC {
   private:
    Uart *serial;
    const int baudrate = 230400;

   public:
    BLDC(Uart *serial);

    void enableUart(void);

    int8_t speed[2] = {0x00, 0x00};
    void write();
};

#endif