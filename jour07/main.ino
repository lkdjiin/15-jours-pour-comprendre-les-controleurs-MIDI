#include <MIDI.h>
#include "Pot.hpp"

const int total_pots = 6;
const int filter_reso = 71;
const int filter_cutoff = 74;
const int amp_attack = 81;
const int amp_release = 84;
const int filter_attack = 85;
const int filter_release = 88;

MIDI_CREATE_DEFAULT_INSTANCE();

Pot pots[total_pots];
int pin[] = {A0, A1, A2, A3, A4, A5};
int CC[] = {filter_cutoff,
            filter_reso,
            filter_attack,
            filter_release,
            amp_attack,
            amp_release};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
  for (int i = 0; i < total_pots; i++) {
    pots[i] = Pot(pin[i], CC[i]);
  }
}

void loop() {
  for (int i = 0; i < total_pots; i++) {
    int newValue = pots[i].update();
    if (newValue < 128) {
      MIDI.sendControlChange(pots[i].cc, newValue, 2);
      delay(5);
    }
  }
}
