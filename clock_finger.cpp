
#include "clock_finger.h"

ClockFinger::ClockFinger(int onOffPin, int directionPin)
{
  _lastDirection = LOW;
  _onOffPin = onOffPin;
  _directionPin = directionPin;
  
  


  pinMode(_onOffPin, OUTPUT);
  pinMode(_directionPin, OUTPUT);

  _powerStatus = LOW;
  digitalWrite(_onOffPin, _powerStatus);
  digitalWrite(_directionPin, LOW);
}

void ClockFinger::powerOn()
{
  _powerStatus = HIGH; 
  digitalWrite(_onOffPin, _powerStatus);   
}


void ClockFinger::powerOff()
{
  _powerStatus = LOW; 
  digitalWrite(_onOffPin, _powerStatus);      
}

void ClockFinger::moveForward() {
  _lastDirection = !_lastDirection;

  
  digitalWrite(_directionPin, _lastDirection);
  

  // if power is not on, turn on
  if (_powerStatus != HIGH) {
    delay(50); // wait for direction relay to finished movement
        
    powerOn();
  } 

  delay(50);  
}

void ClockFinger::rest()
{
  powerOff();
  
  digitalWrite(_directionPin, LOW);
}

