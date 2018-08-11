#pragma once




class Motor
{
public:
	Motor();

	enum wireX { high, low, off };
	enum wireY { high, low, off };
	enum wireZ { high, low, off };

	int getPosition();
		
private:

	
};

Motor::Motor()
{
}
