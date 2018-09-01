#include <Arduino.h>
#include "Motor.h"





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

void Motor::spinCW(int speed, float torque)
{	
	Motor1.clacPhaseTriggers();
	
	while (1)
	{


	}



}

void Motor::setMotorStep(int inStep, int delay, float dutyCycle)
{

	delay *= 1000;

	int numLoops = delay / DUTY_CYCLE_FREQ;


	switch (inStep)
	{
	case 0:
	
		setAllLow();

		digitalWrite(WireZH, HIGH);

		pwm(WireYL, numLoops, dutyCycle);
		//digitalWrite(WireYL, HIGH);
	
		break;

	case 1: 

		setAllLow();

		digitalWrite(WireXH, HIGH);
		pwm(WireYL, numLoops, dutyCycle);
		//digitalWrite(WireYL, HIGH);
		break;

	case 2:

		setAllLow();

		digitalWrite(WireXH, HIGH);
		pwm(WireZL, numLoops, dutyCycle);
		//digitalWrite(WireZL, HIGH);

		break;
	case 3:

		setAllLow();

		digitalWrite(WireYH, HIGH);
		pwm(WireZL, numLoops, dutyCycle);
		//digitalWrite(WireZL, HIGH);

		break;
	case 4:

		setAllLow();

		digitalWrite(WireYH, HIGH);
		pwm(WireXL, numLoops, dutyCycle);
		//digitalWrite(WireXL, HIGH);

		break;
	case 5:

		setAllLow();

		digitalWrite(WireZH, HIGH);
		pwm(WireXL, numLoops, dutyCycle);
		//digitalWrite(WireXL, HIGH);

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






void Motor::pwm(int wire, int numLoops, int dutyCycle)
{


	for (int i = 0; i < numLoops; i++)
	{
		digitalWrite(wire, HIGH);

		delayMicroseconds(DUTY_CYCLE_FREQ * dutyCycle);

		digitalWrite(wire, LOW);

		delayMicroseconds(DUTY_CYCLE_FREQ * (1 - dutyCycle));

	}





}


bool Motor::clacPhaseState(int phase, int freq )
{
	int time = micros() % INTERVAL;
	
	int dutyCycle = torque * (sin((freq * time) + (2 * PI)));

	return ((double(time) / INTERVAL) < dutyCycle);
}