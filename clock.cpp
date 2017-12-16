#include "clock.h"


Clock::Clock(uint8_t data_pin, uint8_t sclk_pin, t_void moveIndicatorAction, t_void noIndicatorAction)
{
  _moveIndicatorAction = moveIndicatorAction;
  _noIndicatorAction = noIndicatorAction;
  
  _rtc = new DS3231(SDA, SCL);
  

  _indicatorPosition = 0;    
};

void Clock::begin()
{
  _rtc->begin();  
}

void Clock::moveIndicatorForward(Time time)
{
  if (_indicatorPosition == maxIndicatorPosision)
    _indicatorPosition = 0;
  else
    _indicatorPosition++;

  // call actual function to physically move teh indicator forward
  _moveIndicatorAction(time);
  
};



void Clock::run()
{
  Time t = _rtc->getTime();

  int desiredIndicatorPosition = t.hour * 24 + t.min;

  if (_indicatorPosition != desiredIndicatorPosition) {
    moveIndicatorForward(t);  
  }
  else {
    _noIndicatorAction(t);
  }
  
};

