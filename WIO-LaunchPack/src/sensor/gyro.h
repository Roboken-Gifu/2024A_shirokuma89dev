/** gyro.h
 */

#ifndef _GYRO_H_
#define _GYRO_H_

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>

class GYRO {
   public:
    const bool isGyroDisabled = false;

    GYRO(Adafruit_BNO055 *p);

    void init(void);
    void setOffset(void);
    int read(void);

    Adafruit_BNO055 *sensorPtr;

    int deg = 0;
    int offset = 0;

   private:
};

#endif  