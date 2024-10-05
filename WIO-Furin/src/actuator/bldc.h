#ifndef _BLDC_H_
#define _BLDC_H_

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