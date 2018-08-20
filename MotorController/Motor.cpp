#include "Motor.h"
#include <Arduino.h>


Motor::Motor()
{

}


Motor::Motor(const int pinList[])
{
	WireXH = pinList[0];
	WireXL = pinList[1];
	WireYH = pinList[2];
	WireYL = pinList[3];
	WireZH = pinList[4];
	WireZL = pinList[5];

}


int Motor::getPosition()
{
	return 0;
}

void Motor::stepCW()
{	// the time between steps is 120ms - 320ms.
	// steps 1 and 2 seem to take longer then the rest.

	/*	0:  120
		1 : 320
		2 : 320
		3 : 124
		4 : 124
		5 : 124
		0 : 120
		1 : 316
		2 : 320
		3 : 124
		4 : 124
		5 : 124
		0 : 120
		1 : 312
		2 : 312
		3 : -23220
		4 : 124
		5 : 120
		0 : 120
		1 : 320
		2 : 312
		3 : 124
		4 : 124
		5 : 120
		0 : 120
		1 : 312
		2 : 320
		3 : 124
		4 : 124
		5 : 120
		0 : 120
		1 : 312
		2 : 312
		3 : 124
		4 : 124
		5 : 124
		0 : 120
		1 : 316
		2 : -23048 // debugger output delay
		3 : 124
		4 : 124
		5 : 124
		0 : 120
		1 : 324
		2 : 312
		3 : 124
		4 : 124
		5 : 124
		0 : 120
		1 : 316
		2 : 320
		3 : 116
		4 : 124
		5 : 120
		0 : 120
		1 : 312
		2 : 312
		3 : 124
		4 : 11*/
	if (currentStep < 5)
	{
		currentStep++;
	}
	else
	{
		currentStep = 0;
	}
	/*int time = micros() - oldTime;

	Serial.print(currentStep);
	Serial.print(":  ");
	Serial.println(time);
	setMotorStep(currentStep);

	oldTime = micros();*/

}

void Motor::setMotorStep(int inStep)
{

	switch (inStep)
	{
	case 0:

		setAllLow();

		digitalWrite(WireZH, HIGH);
		digitalWrite(WireYL, HIGH);

		break;

	case 1: 

		setAllLow();

		digitalWrite(WireXH, HIGH);
		digitalWrite(WireYL, HIGH);
		break;

	case 2:

		setAllLow();

		digitalWrite(WireXH, HIGH);
		digitalWrite(WireZL, HIGH);

		break;
	case 3:

		setAllLow();

		digitalWrite(WireYH, HIGH);
		digitalWrite(WireZL, HIGH);

		break;
	case 4:

		setAllLow();

		digitalWrite(WireYH, HIGH);
		digitalWrite(WireXL, HIGH);

		break;
	case 5:

		setAllLow();

		digitalWrite(WireZH, HIGH);
		digitalWrite(WireXL, HIGH);

		break;
	}


}

void Motor::setAllLow()
{

	digitalWrite(WireXH, LOW);
	digitalWrite(WireXL, LOW);
	digitalWrite(WireYH, LOW);
	digitalWrite(WireYL, LOW);
	digitalWrite(WireZH, LOW);
	digitalWrite(WireZL, LOW);

	delayMicroseconds(OFF_TIME_BUFFER);
}