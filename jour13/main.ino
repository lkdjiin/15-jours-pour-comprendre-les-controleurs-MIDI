const int total_pots = 3;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < total_pots; i++) {
    digitalWrite(8, bitRead(i, 0));
    digitalWrite(9, bitRead(i, 1));
    digitalWrite(10, bitRead(i, 3));
    int value = analogRead(A0);
    Serial.println("Pot_" + String(i) +  ":" + String(value));
    delay(500);
  }
}
