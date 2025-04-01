int lastValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int currentValue = analogRead(A0) >> 3;

  if (lastValue != currentValue) {
    Serial.println(currentValue);
    lastValue = currentValue;
  }

  delay(10);
}
