#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <Arduino.h>
#include <Wire.h>

#include "./sensor/gyro.h"
#include "./actuator/bldc.h"

void initUART(void);
void initI2C(void);
void initDevice(void);

extern Adafruit_BNO055 bno055;
extern GYRO gyro;

extern Uart Serial1;
extern BLDC bldc;

#endif
