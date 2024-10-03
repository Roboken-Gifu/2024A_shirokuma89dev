#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <Arduino.h>
#include <Wire.h>

#include "./sensor/gyro.h"  
#include "./actuator/motor.h"
#include "./actuator/sub_mcu.h"

void initUART(void);
void initI2C(void);
void initDevice(void);

extern Adafruit_BNO055 bno055;
extern GYRO gyro;

extern MOTOR motor[2];  // 右左

extern SUB_MCU sub_mcu;


#endif
