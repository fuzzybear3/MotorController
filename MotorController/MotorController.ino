/*
 Name:		MotorController.ino
 Created:	8/10/2018 12:01:06 AM
 Author:	steve
*/
#include "Motor.h"

enum direction { forword, backword, regen, coast };
void Drive(enum direction, int power);

Motor Motor1;

// the setup function runs once when you press reset or power the board
void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {
  
	Motor1.stepCW();


}

void Drive(enum direction, int power)
{
	int pos = Motor1.getPosition();

	//*make table for angles and steps*
	//use switch statment maybe??

	



}

