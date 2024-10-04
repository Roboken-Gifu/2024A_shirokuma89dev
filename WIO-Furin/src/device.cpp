#include "device.h"

// CONSTANNT
const int Period = 10;

// SENSOR
Adafruit_BNO055 bno055 = Adafruit_BNO055(55, 0x28, &Wire1);
GYRO gyro(&bno055);

// ACTUATOR
// PWM_MOTOR wheelMotor[2] = {PWM_MOTOR(BCM11, BCM27), PWM_MOTOR(BCM13, BCM26)};  // 右左
// SUB_MCU subMcu(&Serial1);

BLDC bldc(&Serial1);

// FUNCTION
void initUART(void) {
    Serial.begin(115200);

    bldc.enableUart();
}

void initI2C(void) {
    Wire1.setClock(100000);
    Wire1.begin();
}

void initDevice(void) {
    initI2C();
    initUART();

    gyro.init();
    gyro.setOffset();
}