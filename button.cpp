#include "button.h"



Button::Button(int pin, t_click handler)
{  
  _pin = pin;
  _handler = handler;

  // config pin
  pinMode(_pin, INPUT);  
}

