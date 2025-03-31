void setup() {
  Serial.begin(9600);
}

void loop() {
  int currentValue = analogRead(A0);
  Serial.println(currentValue >> 3);
  delay(10);
}
