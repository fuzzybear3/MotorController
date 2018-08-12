#include "Motor.h"



int Motor::getPosition()
{
	return 0;
}

void Motor::stepCW()
{



}

void Motor::setMotorStep(step inStep)
{

	switch (inStep)
	{
	case Motor::step1:   // whu Mottor:: ?
		
		
		digitalWrite(WireXH, HIGH);
		digitalWrite(WireXL, LOW);
		digitalWrite(WireYH, HIGH);
		digitalWrite(WireYL, LOW);
		digitalWrite(WireZH, LOW);
		digitalWrite(WireZL, LOW);  //finish this...
		
		break;
	case Motor::step2:
		break;
	case Motor::step3:
		break;
	case Motor::step4:
		break;
	case Motor::step5:
		break;
	case Motor::step6:
		break;
	default:
		break;
	}


}