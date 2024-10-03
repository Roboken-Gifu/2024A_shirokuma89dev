#include "gyro.h"

GYRO::GYRO(Adafruit_BNO055 *p) {
    sensorPtr = p;
}

void GYRO::init(void) {
    const bool debug = true;

    // センサーの初期化
    if (!sensorPtr->begin(OPERATION_MODE_IMUPLUS)) {
        if (debug) {
            Serial.println("Failed to initialize BNO055!");
        }
        while (1);
    }

    sensor_t sensor;

    sensorPtr->getSensor(&sensor);

    uint8_t system_status, self_test_results, system_error;
    system_status = self_test_results = system_error = 0;
    sensorPtr->getSystemStatus(&system_status, &self_test_results,
                               &system_error);

    if (debug) {
        Serial.print("System Status: ");
        Serial.println(system_status);
        Serial.print("Self Test Results: ");
        Serial.println(self_test_results);
        Serial.print("System Error: ");
        Serial.println(system_error);

        switch (system_error) {
            case 0:
                Serial.println("No error");
                break;
            case 1:
                Serial.println("Peripheral initialization error");
                break;
            case 2:
                Serial.println("System initialization error");
                break;
            case 3:
                Serial.println("Self test result failed");
                break;
            case 4:
                Serial.println("Register map value out of range");
                break;
            case 5:
                Serial.println("Register map address out of range");
                break;
            case 6:
                Serial.println("Register map write error");
                break;
            case 7:
                Serial.println(
                    "BNO low power mode not available for selected operation "
                    "mode");
                break;
            case 8:
                Serial.println("Accelerometer power mode not available");
                break;
            case 9:
                Serial.println("Fusion algorithm configuration error");
                break;
            case 10:
                Serial.println("Sensor configuration error");
                break;
            default:
                Serial.println("Unknown error");
                break;
        }
    }

    sensorPtr->setExtCrystalUse(true);

    if (debug) {
        Serial.println("External crystal use set.");
    }
}

int GYRO::read(void) {
    sensors_event_t event;
    sensorPtr->getEvent(&event);

    deg = (int)(event.orientation.x - offset + 360) % 360;

    return deg;
}

void GYRO::setOffset(void) {
    sensors_event_t event;
    sensorPtr->getEvent(&event);
    offset = event.orientation.x;
}