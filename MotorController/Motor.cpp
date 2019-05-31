#include <Arduino.h>
#include "Motor.h"




Motor::Motor()
{

}


Motor::Motor(const int pinList[])
{


	phaseX.phaseHPin = pinList[0];
	phaseX.phaseLPin = pinList[1];
	phaseY.phaseHPin = pinList[2];
	phaseY.phaseLPin = pinList[3];
	phaseZ.phaseHPin = pinList[4];
	phaseZ.phaseLPin = pinList[5];

}


int Motor::getPosition()
{
	return 0;
}

void Motor::spinCW(int speed, float torque)
{	


		phaseX = clacPhaseState(phaseX, speed);
		phaseY = clacPhaseState(phaseY, speed);
		phaseZ = clacPhaseState(phaseZ, speed);
	
		setPhaseState(phaseX);
		setPhaseState(phaseY);
		setPhaseState(phaseZ);
}






phase Motor::clacPhaseState(phase inPhase, int freq)
{
	int time = micros() % INTERVAL;
	
	double sinWave = sin((freq * micros()) +  ( (inPhase.phaseNum * (2 * PI) )/3) );
	
	double dutyCycle = torque * sinWave;

	if ((double(time) / INTERVAL) > dutyCycle)
	{
		if (sinWave > 0)
		{
			inPhase.nextState = high;
		}
		else
		{
			inPhase.nextState = low;
		}
	}
	else
	{
		inPhase.nextState = off;
	}

	return inPhase;
}



void Motor::setPhaseState(phase &inPhase)
{
	switch (inPhase.nextState)
	{

		case high: {
			digitalWrite(inPhase.phaseLPin, LOW);
			digitalWrite(inPhase.phaseHPin, HIGH);
		}

		case low: {
			digitalWrite(inPhase.phaseHPin, LOW);
			digitalWrite(inPhase.phaseLPin, HIGH);
		}

		case off: {

			digitalWrite(inPhase.phaseHPin, LOW);
			digitalWrite(inPhase.phaseLPin, LOW);
		}

	}
}