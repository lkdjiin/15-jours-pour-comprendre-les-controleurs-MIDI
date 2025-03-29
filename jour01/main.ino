#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  MIDI.sendNoteOn(60, 127, 2);
  delay(1000);
  MIDI.sendNoteOff(60, 0, 2);
  delay(1000);
}
