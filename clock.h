#ifndef clock_h
#define clock_h

#include "Arduino.h"
#include "src/DS3231/DS3231.h"

const int maxIndicatorPosision = (60 * 24) - 1;

typedef int (*t_void)(Time);

class Clock
{
  private:
    DS3231  *_rtc;
    int _indicatorPosition;
    t_void _moveIndicatorAction;
    t_void _noIndicatorAction;

    void moveIndicatorForward(Time time);

      
  public:
    Clock(uint8_t data_pin, uint8_t sclk_pin, t_void moveIndicatorAction, t_void noIndicatorAction);

    void begin();
    void run();
    
  
  
};






#endif
