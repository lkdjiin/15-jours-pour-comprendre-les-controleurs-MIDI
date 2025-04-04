#include <MIDI.h>

const int FILTER_CUTOFF = 74;

int penultimate = 0;
int last = 0;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  int current = analogRead(A0) >> 3;

  if (last != current) {
    if (penultimate + last != last + current) {
      MIDI.sendControlChange(FILTER_CUTOFF, current, 2);
      penultimate = last;
      last = current;
    }
  }

  delay(10);
}
