/*
 Name:		MotorController.ino
 Created:	8/10/2018 12:01:06 AM
 Author:	steve
*/
#include "Motor.h"

enum direction { forword, backword, regen, coast };
void Drive(enum direction, int power);

const int MOTOR_PIN_LIST[6] = { 0,0,0,0,0,0 };
condt int pot = 0;
Motor Motor1(MOTOR_PIN_LIST);

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(MOTOR_PIN_LIST[0], OUTPUT);
	pinMode(MOTOR_PIN_LIST[1], OUTPUT);
	pinMode(MOTOR_PIN_LIST[2], OUTPUT);
	pinMode(MOTOR_PIN_LIST[3], OUTPUT);
	pinMode(MOTOR_PIN_LIST[4], OUTPUT);
	pinMode(MOTOR_PIN_LIST[5], OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {
  
	int input = analogRead(Pot);
	input *= 5;

	Motor1.stepCW();
	delayMicroseconds(input);

}

void Drive(enum direction, int power)
{
	int pos = Motor1.getPosition();

	//*make table for angles and steps*
	//use switch statment maybe??

	



}

