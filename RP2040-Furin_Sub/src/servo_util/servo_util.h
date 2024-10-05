#ifndef _SERVO_UTIL_H_
#define _SERVO_UTIL_H_

#include <Arduino.h>
#include <Servo.h>

class ServoUtil {
   private:
    Servo lockServo;
    Servo boxHolderServo;

   public:
    ServoUtil(int lockServoPin, int boxHolderServoPin);

    void setLock(bool shouldLock);
    void setBoxHolder(bool shouldHold);
};

#endif  // _SERVO_UTIL_H_