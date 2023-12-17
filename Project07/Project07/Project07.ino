const int Piezo_Pin = 8;
int notes[] = { 262, 294, 330, 349 };

void setup() {
  Serial.begin(9600);
}

void loop() {
    int keyVal = analogRead(A0);
    Serial.print(" A0 intput: ");
    Serial.println(keyVal);
    if (keyVal == 1023){
        tone (Piezo_Pin, notes[0]);
    } else if (keyVal >= 990 && keyVal <= 1010) {
        tone(Piezo_Pin, notes[1]);
    } else if (keyVal >= 505 && keyVal <= 515) {
        tone(Piezo_Pin, notes[2]);
    } else if (keyVal >= 5 && keyVal <= 10) {
        tone(Piezo_Pin, notes[3]);
    } else {
        noTone(Piezo_Pin);
    }

}