void setup() {
    Serial.begin(9600);
}

void loop() {
    int keyVal = analogRead(A0);
    Serial.print(" Input A0: ");
    Serial.println(keyVal);
    //tone(8, 400);
}