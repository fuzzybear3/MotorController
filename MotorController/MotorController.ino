// MotorController.ino
#include "Motor.h"
#include <Arduino.h>



//    0      1        2       3       4      5
// WireXH, WireXL, WireYH, WireYL, WireZH, WireZL,
const int MOTOR_PIN_LIST[6] = { A2, 6, A1, 5, A0, 4 };
const int TORQUE_PIN = A7;
const int SPEED_PIN = A8;
const int CYCLE = 100;
const double PI = 3.14159265359;

Motor Motor1(MOTOR_PIN_LIST);

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(TORQUE_PIN, INPUT);
	pinMode(SPEED_PIN, OUTPUT);
	pinMode(MOTOR_PIN_LIST[0], OUTPUT);
	pinMode(MOTOR_PIN_LIST[1], OUTPUT);
	pinMode(MOTOR_PIN_LIST[2], OUTPUT);
	pinMode(MOTOR_PIN_LIST[3], OUTPUT);
	pinMode(MOTOR_PIN_LIST[4], OUTPUT);
	pinMode(MOTOR_PIN_LIST[5], OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop()
{
    // 0-1023
	int torqueInput = analogRead(TORQUE_PIN);
    int speedInput = analogRead(SPEED_PIN);

    // 0.0-1.0
    double torque = torqueInput / 1023.0;
    double speed = speedInput / 1023.0;

	motor.run(torque, speed);
}
