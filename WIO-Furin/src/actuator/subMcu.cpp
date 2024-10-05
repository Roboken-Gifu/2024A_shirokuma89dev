#include "subMcu.h"

SUB_MCU::SUB_MCU(TwoWire *i2c) {
    this->i2c = i2c;
}

void SUB_MCU::enableI2cBus(void) {

    delay(5000);
    i2c->begin();

    // i2cデバイス検索
    Serial.println("I2C device scan...");
    byte error, address;
    int nDevices;

    nDevices = 0;

    for (address = 1; address < 127; address++) {
        i2c->beginTransmission(address);
        error = i2c->endTransmission();

        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16) {
                Serial.print("0");
            }
            Serial.println(address, HEX);

            nDevices++;
        } else if (error == 4) {
            Serial.print("Unknown error at address 0x");
            if (address < 16) {
                Serial.print("0");
            }
            Serial.println(address, HEX);
        }
    }
}

void SUB_MCU::setBoxhold(bool shouldBoxhold) {
    char data = shouldBoxhold ? 'H' : 'h';
    i2c->beginTransmission(0x08);
    i2c->write(data);
    i2c->endTransmission();
}

void SUB_MCU::setLock(bool shouldLock) {
    char data = shouldLock ? 'L' : 'l';
    i2c->beginTransmission(0x08);
    i2c->write(data);
    i2c->endTransmission();
}

void SUB_MCU::setPumpOn(bool shouldPumpOn) {
    char data = shouldPumpOn ? 'P' : 'p';
    i2c->beginTransmission(0x08);
    i2c->write(data);
    i2c->endTransmission();
}