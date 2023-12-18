int ledPins = 2;

void setup() {
    Serial.begin(9600);
    pinMode(8, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}
void loop() {
    int switchState = digitalRead(8);
    Serial.print("Switch State: ");
    Serial.println(switchState);
    for (int i = 2; i < 8; i++) {
        digitalWrite(i, HIGH);
        delay(1000);
        digitalWrite(i, LOW);
    }
}