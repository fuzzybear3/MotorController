#pragma once

struct phase {
	int onTime;
	int offTime;
};

class Motor
{
public:
	Motor();
	// pinList: WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;
	Motor(const int pinList[]); 
	
	bool clacPhaseState(int phase, int freq);
	int getPosition();
	void spinCW(int speed, float torque);

	void setMotorStep(int inStep, int delay, float dutyCycle);
	int currentStep = 0;
private:

	const int OFF_TIME_BUFFER = 2;
	const int DUTY_CYCLE_FREQ = 100; // microSeconds
	const int INTERVAL = 200; // microSeconds
	
	double torque = 1;

	void setAllLow();
	
	void pwm(int wire, int numLoops, int dutyCycle);

	int WireXH;
	int WireXL;
	int WireYH;
	int WireYL;
	int WireZH;
	int WireZL;



	//unsigned int time = 0;

	
	

};


