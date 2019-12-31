#include <Arduino.h>
float dudtyCycle = 0.0;
const int PERIOD = 25000; //micro sec
const int DIV = 100; // 10%
float divNum = PERIOD / DIV;
float step = 1 / divNum;

long time_;
long oldTime;
bool up = true;


#define pin 13
void setup() {
  pinMode(pin, OUTPUT);
  time_ = oldTime = micros();
}

void loop() {
  time_ = micros();
  long deltaTime = time_ - oldTime;

  if (deltaTime > (DIV * dudtyCycle)) 
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    digitalWrite(pin, LOW);
  }
  
  if (deltaTime > DIV)
  {
    oldTime = time_;

    if (up)
    {
      dudtyCycle += step;
    }
    else
    {
      dudtyCycle -= step;
    }

    if (dudtyCycle > 0.99)
    {
     up = false;
     //dudtyCycle = 1;
    }

    if (dudtyCycle < 0.01)
    {
      up = true;
    //  dudtyCycle = 0;
    }
    
  }
  
  // delay(50);
  // digitalWrite(pin, HIGH);
  // delay(50);
  // digitalWrite(pin, LOW);
}