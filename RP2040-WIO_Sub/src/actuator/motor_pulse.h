#ifndef _MOTOR_PULSEOR_PULSE_H_
#define _MOTOR_PULSEOR_PULSE_H_

#include <Arduino.h>
#include <Servo.h>

#define MOTOR_PULSE_SIG_MAX 2000
#define MOTOR_PULSE_SIG_MIN 1000

class MOTOR_PULSE {
   private:
    int pin;
    Servo motor_device;

   public:
    MOTOR_PULSE(int pin);
    void write(float value);  // 0.0 ~ 1.0
    float operator=(float value);
    void ballPush(bool isPush);

    static void init(MOTOR_PULSE* esc_arr, int esc_num = 2);
};

#endif