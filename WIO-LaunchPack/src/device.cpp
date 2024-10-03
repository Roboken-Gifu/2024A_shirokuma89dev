#include "device.h"

// CONSTANNT
const int Period = 10;

// SENSOR
// Adafruit_BNO055 bno055 = Adafruit_BNO055(55, 0x28, &Wire1);
// GYRO gyro(&bno055);

// ACTUATOR
MOTOR motor[2] = {MOTOR(BCM11, BCM27), MOTOR(BCM13, BCM26)};  // 右左
SUB_MCU sub_mcu(&Serial1);

// FUNCTION
void initUART(void) {
    Serial.begin(115200);

    sub_mcu.enableUart();
}

void initI2C(void) {
    Wire1.setClock(100000);
    Wire1.begin();
}

void initDevice(void) {
    initI2C();
    initUART();

    // gyro.init();
    // gyro.setOffset();
}