#ifndef Pot_hpp
#define Pot_hpp

#include <Arduino.h>

class Pot {
  public:
    int last;
    int penultimate;
    int pin;
    int cc;
    Pot();
    Pot(int pin, int cc);
    int update();
};

#endif
