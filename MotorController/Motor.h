#pragma once



class Motor
{
public:
	Motor();
	// pinList: WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;
	Motor(const int pinList[]); 
	

	int getPosition();
	void stepCW(int delay, float dutyCycle);

	void setMotorStep(int inStep, int delay, float dutyCycle);
	int currentStep = 0;
private:

	const int OFF_TIME_BUFFER = 2;
	const int DUTY_CYCLE_FREQ = 100; // microSeconds
	
	void setAllLow();
	void pwm(int wire, int numLoops, int dutyCycle);

	int WireXH;
	int WireXL;
	int WireYH;
	int WireYL;
	int WireZH;
	int WireZL;

	
};


