#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>

class PWM_MOTOR {
   private:
    int pin1;
    int pin2;

   public:
    PWM_MOTOR(int pin1, int pin2);
    void drive(int speed);

    int operator=(int spped);
};

#endif