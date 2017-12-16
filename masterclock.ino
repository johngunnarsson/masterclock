// external libraries
#include "src/DS3231/DS3231.h"
#include "src/7seg/Adafruit_LEDBackpack.h"

// internal libraries
#include "clock.h"
#include "clock_finger.h"
#include "time_configurator.h"
#include "button.h"


Adafruit_7segment matrix = Adafruit_7segment();



const int PIN_BUTTON_1 = 5;
const int PIN_BUTTON_2 = 7;
const int PIN_BUTTON_3 = 8;

const int PIN_RELAY_ON_OFF = 4;
const int PIN_RELAY_CURRENT_DIRECTION = 3;

typedef enum Mode {FirstTimeUse, Setup, Normal};

Clock *clock;
ClockFinger *clockFinger;
TimeConfigurator *configurator;

Button *buttons[3];

void moveIndicatorForward(Time time) {
  matrix.print(time.min, DEC);
  matrix.writeDisplay();

  clockFinger->moveForward();

}

void noIndicatorAction(Time time) {

  clockFinger->rest();

}

void setup()
{
  // configure pins
  pinMode(PIN_BUTTON_1, INPUT);
  pinMode(PIN_BUTTON_2, INPUT);
  pinMode(PIN_BUTTON_3, INPUT);


  // Setup Serial connection
  Serial.begin(9600);

  clock = new Clock(SDA, SCL, &moveIndicatorForward, &noIndicatorAction);
  clock->begin();

  clockFinger = new ClockFinger(PIN_RELAY_ON_OFF, PIN_RELAY_CURRENT_DIRECTION);

  configurator = new TimeConfigurator();

  matrix.begin(0x70);


 // buttons[0] = new Button(PIN_BUTTON_1);
  //buttons[1] = new Button(PIN_BUTTON_2);
  //buttons[2] = new Button(PIN_BUTTON_3);

}

void loop()
{

  clock->run();

    // Wait one second before repeating :)
  //delay (200);

  //Serial.println(millis(), DEC);
}
