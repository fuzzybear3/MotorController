// Motor.cpp
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
	return currentStep;
}

void Motor::stepCW()
{
	if (currentStep < 5)
	{
		currentStep++;
	}
	else
	{
		currentStep = 0;
	}

	setMotorStep(currentStep);
}

void Motor::setMotorStep(int step)
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
