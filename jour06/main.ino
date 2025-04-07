#include <MIDI.h>

const int total_pots = 6;
const int channel = 2;
const int filter_reso = 71;
const int filter_cutoff = 74;
const int amp_attack = 81;
const int amp_release = 84;
const int filter_attack = 85;
const int filter_release = 88;

int last[] = {0, 0, 0, 0, 0, 0};
int penultimate[] = {0, 0, 0, 0, 0, 0};
int pin[] = {A0, A1, A2, A3, A4, A5};
int CC[] = {filter_reso,
            filter_cutoff,
            filter_attack,
            filter_release,
            amp_attack,
            amp_release};

MIDI_CREATE_DEFAULT_INSTANCE();

void update(int index) {
  int current = analogRead(pin[index]) >> 3;

  if (last[index] != current) {
    if (penultimate[index] + last[index] != last[index] + current) {
      MIDI.sendControlChange(CC[index], current, channel);
      penultimate[index] = last[index];
      last[index] = current;
    }
  }
}

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  for (int i = 0; i < total_pots; i++) {
    update(i);
    delay(10);
  }
}
