int penultimate = 0;
int last = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int current = analogRead(A0) >> 3;

  if (last != current) {
    if (penultimate + last != last + current) {
      Serial.println(current);
      penultimate = last;
      last = current;
    }
  }

  delay(10);
}
