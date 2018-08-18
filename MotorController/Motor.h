#pragma once



class Motor
{
public:
	Motor();
	// pinList: WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;
	Motor(const int pinList[]); 
	

	int getPosition();
	void stepCW();

	//enum step { step0, step1, step2, step3, step4, step5 };
	//step currentStep = step0;
	int currentStep = 0;
private:

	const int OFF_TIME_BUFFER = 1;
	void setMotorStep(int inStep);
	void Motor::setAllLow();

	//enum wireX { high, low, off };
	//enum wireY { high, low, off };
	//enum wireZ { high, low, off };

	int WireXH;
	int WireXL;
	int WireYH;
	int WireYL;
	int WireZH;
	int WireZL;

	
};


