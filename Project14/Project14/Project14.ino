void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = (analogRead(A0)/4);
  Serial.write(sensorValue);
  delay(1);
}
