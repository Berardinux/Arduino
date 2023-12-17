const int Piezo_Pin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(Piezo_Pin, OUTPUT);
}

void loop() {
  for (int i=0; i <= 1000; i+=100) {
    tone(Piezo_Pin, i);
    delay (500);
    Serial.print(" Pin 8 output: ");
    Serial.println(i);
  }
}
