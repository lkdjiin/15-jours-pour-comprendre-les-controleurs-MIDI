const int total_pots = 2;

void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < total_pots; i++) {
    digitalWrite(8, i);
    int value = analogRead(A0);
    Serial.println("Pot_" + String(i) +  ":" + String(value));
    delay(50);
  }
}
