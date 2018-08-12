#pragma once



class Motor
{
public:
	Motor();

	

	int getPosition();
	void stepCW();

	enum step { step1, step2, step3, step4, step5, step6 };
	step currentStep;
private:

	void setMotorStep(step inStep);

	enum wireX { high, low, off };
	enum wireY { high, low, off };
	enum wireZ { high, low, off };

	int WireXH;
	int WireXL;
	int WireYH;
	int WireYL;
	int WireZH;
	int WireZL;

	
};

Motor::Motor()
{
	WireXH = 1
		//finish this

}
