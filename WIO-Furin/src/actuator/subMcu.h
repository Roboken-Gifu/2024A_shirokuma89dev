#ifndef _SUB_MCU_H_
#define _SUB_MCU_H_

#include <Arduino.h>
#include <Wire.h>

#define SERVO_NUM 2
#define GPIO_NUM 2

class SUB_MCU {
   private:
    TwoWire *i2c;

   public:
    SUB_MCU(TwoWire *i2c);

    void enableI2cBus(void);

    void setLock(bool shouldLock);
    void setPumpOn(bool shouldPumpOn);
    void setBoxhold(bool shouldBoxhold);
};

#endif