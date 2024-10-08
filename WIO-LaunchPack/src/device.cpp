#include "device.h"

// SENSOR
// Adafruit_BNO055 bno055 = Adafruit_BNO055(55, 0x28, &Wire1);
// GYRO gyro(&bno055);

// ACTUATOR
PWM_MOTOR wheelMotor[2] = {PWM_MOTOR(BCM11, BCM27),
                           PWM_MOTOR(BCM13, BCM26)};  // 右左
SUB_MCU subMcu(&Serial1);

// FUNCTION
void initUART(void) {
    Serial.begin(115200);

    subMcu.enableUart();
}

// depricated
void initI2C(void) {
    Wire1.setClock(100000);
    Wire1.begin();
}

void initDevice(void) {
    // initI2C();
    initUART();

    // gyro.init();
    // gyro.setOffset();
}