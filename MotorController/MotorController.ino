/*
 Name:		MotorController.ino
 Created:	8/10/2018 12:01:06 AM
 Author:	steve
*/
#include "Motor.h"
#include <Arduino.h>



enum direction { forward, backward, regen, coast };
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
	
	

}

// the loop function runs over and over again until power down or reset
void loop() {
  
	int speed = analogRead(POT);
	
	//double torque = 1;
	//map(speed, 0, 1023, 50, 500);
	Motor1.spinCW(speed,1);

}

//void Drive(enum direction, int power)
//{
//	int pos = Motor1.getPosition();
//
//	//*make table for angles and steps*
//	//use switch statment maybe??
//
//	
//
//
//
//}

