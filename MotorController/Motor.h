// Motor.h
#pragma once



class Motor
{
    public:

    	Motor();
    	Motor(const int pinList[]); // WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;

    	void run(int delayTime, int dutyCycle);

    private:

    	int WireXH;
    	int WireXL;
    	int WireYH;
    	int WireYL;
    	int WireZH;
    	int WireZL;
};
