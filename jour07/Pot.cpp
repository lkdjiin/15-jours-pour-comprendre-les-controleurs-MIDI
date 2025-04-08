#include "Pot.hpp"

Pot::Pot() {}

Pot::Pot(int pin, int cc) {
  this->pin = pin;
  this->cc = cc;
  last = analogRead(pin) >> 3;
  penultimate = last;
}

int Pot::update() {
  int current = analogRead(pin) >> 3;

  if (last != current) {
    if (penultimate + last != last + current) {
      penultimate = last;
      last = current;
      return current;
    }
  }

  return 128;
}
