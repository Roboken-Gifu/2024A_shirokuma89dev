#include "device.h"

// CONSTANNT
const int Period = 10;

// SENSOR
Adafruit_BNO055 bno055 = Adafruit_BNO055(55, 0x28, &Wire1);
GYRO gyro(&bno055);

// ACTUATOR
BLDC bldc(&Serial1);
SUB_MCU subMcu(&Wire1);

// FUNCTION
void initUART(void) {
    Serial.begin(115200);

    bldc.enableUart();
}

void initI2C(void) {
    Wire1.setClock(100000);
    Wire1.begin();

    subMcu.enableI2cBus();
}

void initDevice(void) {
    initI2C();
    initUART();

    gyro.init();
    gyro.setOffset();
}