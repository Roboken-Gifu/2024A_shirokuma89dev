#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>

class MOTOR {
   private:
    int pin1;
    int pin2;

   public:
    MOTOR(int pin1, int pin2);
    void drive(int speed);

    int operator=(int spped);
};

#endif