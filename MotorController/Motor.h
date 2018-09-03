// Motor.h
#pragma once



class Motor
{
    public:

    	Motor();
    	Motor(const int pinList[]); // WireXH, WireXL, WireYH, WireYL, WireZH, WireZL;

    	void run(int delayTime, int dutyCycle);

    private:

      const int CYCLE = 100;
      const double PI = 3.14159265359;

    	int WireXH;
    	int WireXL;
    	int WireYH;
    	int WireYL;
    	int WireZH;
    	int WireZL;
};
