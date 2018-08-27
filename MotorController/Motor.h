// Motor.h
#pragma once



class Motor
{
public:

	Motor();
	// pinList: WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;
	Motor(const int pinList[]);

	int getPosition();
	void stepCW();

	void setMotorStep(int inStep);

private:

	const int OFF_TIME_BUFFER = 2;

	void Motor::setAllLow();

	int WireXH;
	int WireXL;
	int WireYH;
	int WireYL;
	int WireZH;
	int WireZL;

	int currentStep = 0;
};
