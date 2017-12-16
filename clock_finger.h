#ifndef clock_finger_h
#define clock_finger_h

#include <Arduino.h>

class ClockFinger
{
  private:
    int _onOffPin;
    int _directionPin;
    
    int _lastDirection;
    
    int _powerStatus;


    void powerOn();
    void powerOff();  

  public:
    ClockFinger(int onOffPin, int directionPin);

    void moveForward();
    void rest();
    
  
};


#endif
