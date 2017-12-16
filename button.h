#ifndef button_h
#define button_h

#include <Arduino.h>

typedef bool (*t_click)(bool);

class Button
{
  private:
    int _pin;
    t_click _handler;
  public:
    Button(int pin, t_click handler);
    
  
};

#endif

