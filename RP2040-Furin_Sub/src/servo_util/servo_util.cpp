#include "servo_util.h"

ServoUtil::ServoUtil(int lockServoPin, int boxServoPin) {
    this->lockServo.attach(lockServoPin);
    this->boxHolderServo.attach(boxServoPin);
}

void ServoUtil::setLock(bool shouldLock) {
    if (shouldLock) {
        this->lockServo.write(180);
    } else {
        this->lockServo.write(90);
    }
}

void ServoUtil::setBoxHolder(bool shouldHold) {
    static bool _shouldHold = true;

    const int angleShouldHold = 15;
    const int angleShouldNotHold = 163;
    const int slowRange = 60;

    if (shouldHold != _shouldHold) {
        _shouldHold = shouldHold;
    } else {
        if (shouldHold) {
            this->boxHolderServo.write(angleShouldHold);
        } else {
            this->boxHolderServo.write(angleShouldNotHold);
        }
        return;
    }

    if (shouldHold) {
        for (int i = angleShouldNotHold; i > angleShouldNotHold - slowRange;
             i--) {
            this->boxHolderServo.write(i);
            delay(10);
        }
        for (int i = angleShouldNotHold - slowRange; i > angleShouldHold;
             i -= 2) {
            this->boxHolderServo.write(i);
            delay(10);
        }
    } else {
        for (int i = angleShouldHold; i < angleShouldHold + slowRange; i++) {
            this->boxHolderServo.write(i);
            delay(10);
        }
        for (int i = angleShouldHold + slowRange; i < angleShouldNotHold;
             i += 2) {
            this->boxHolderServo.write(i);
            delay(10);
        }
    }

    delay(10);
}