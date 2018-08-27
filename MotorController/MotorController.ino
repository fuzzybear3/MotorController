// MotorController.ino
#include "Motor.h"
#include <Arduino.h>



enum direction { forword, backword, regen, coast };
void Drive(enum direction, int power);
						//    0      1        2       3       4      5
						// WireXH, WireXL, WireYH, WireYL, WireZH, WireZL,
const int MOTOR_PIN_LIST[6] = { A2,6,A1,5,A0,4 };
const int POT = A7;
const int DELAY_MUTIPLIER = 16;

Motor Motor1(MOTOR_PIN_LIST);

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
	pinMode(POT, INPUT);
	pinMode(13, OUTPUT);
	pinMode(MOTOR_PIN_LIST[0], OUTPUT);
	pinMode(MOTOR_PIN_LIST[1], OUTPUT);
	pinMode(MOTOR_PIN_LIST[2], OUTPUT);
	pinMode(MOTOR_PIN_LIST[3], OUTPUT);
	pinMode(MOTOR_PIN_LIST[4], OUTPUT);
	pinMode(MOTOR_PIN_LIST[5], OUTPUT);
	pinMode(2, OUTPUT);

	digitalWrite(4, HIGH);

	Motor1.setMotorStep(0);
}

// the loop function runs over and over again until power down or reset
void loop() {

	int input = analogRead(POT);
	//input *= DELAY_MUTIPLIER;

	map(input, 0, 1023, 10000, 1000000);

	//Serial.print("  analogRead: ");
	//Serial.println(input);




	Motor1.stepCW();
	//Motor1.setMotorStep(input);
	delayMicroseconds(input);


}

void Drive(enum direction, int power)
{
	int pos = Motor1.getPosition();

	//*make table for angles and steps*
	//use switch statment maybe??





}
