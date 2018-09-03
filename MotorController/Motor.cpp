// Motor.cpp
#include "Motor.h"
#include <Arduino.h>

void Motor::run(int torque, int speed)
{
    int t = getMicroseconds();

    int dutyX = CYCLE * torque * sin(speed * t);
    int dutyY = CYCLE * torque * sin(speed * t + 2 * PI / 3);
    int dutyZ = CYCLE * torque * sin(speed * t + 4 * PI / 3);

    digitalWrite(dutyX > 0 ? WireXH : WireXL, HIGH);
    digitalWrite(dutyY > 0 ? WireYH : WireYL, HIGH);
    digitalWrite(dutyZ > 0 ? WireZH : WireZL, HIGH);

    if (dutyX <= dutyY <= dutyZ) {

        delayMicroseconds(dutyX);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(dutyY - dutyX);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(dutyZ - dutyY);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(CYCLE - dutyZ);

    } else if (dutyX <= dutyZ <= dutyY) {

        delayMicroseconds(dutyX);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(dutyZ - dutyX);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(dutyY - dutyZ);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(CYCLE - dutyY);

    } else if (dutyY <= dutyX <= dutyZ) {

        delayMicroseconds(dutyY);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(dutyX - dutyY);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(dutyZ - dutyX);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(CYCLE - dutyZ);

    } else if (dutyY <= dutyZ <= dutyX) {

        delayMicroseconds(dutyY);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(dutyZ - dutyY);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(dutyX - dutyZ);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(CYCLE - dutyX);

    } else if (dutyZ <= dutyX <= dutyY) {

        delayMicroseconds(dutyZ);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(dutyX - dutyZ);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(dutyY - dutyX);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(CYCLE - dutyY);

    } else /*if (dutyZ <= dutyY <= dutyX)*/ {

        delayMicroseconds(dutyZ);
        digitalWrite(dutyZ > 0 ? WireZH : WireZL, LOW);
        delayMicroseconds(dutyY - dutyZ);
        digitalWrite(dutyY > 0 ? WireYH : WireYL, LOW);
        delayMicroseconds(dutyX - dutyY);
        digitalWrite(dutyX > 0 ? WireXH : WireXL, LOW);
        delayMicroseconds(CYCLE - dutyX);
    }
}
