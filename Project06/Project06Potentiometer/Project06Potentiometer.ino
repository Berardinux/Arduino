const int ledPin = 13;
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    while (millis() < 5000) {
        sensorValue = analogRead(A0);
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;
        }
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;
        }
    }
    digitalWrite(ledPin, LOW);
}

void loop() {
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);

    Serial.print(" A0 value: ");
    Serial.println(sensorValue);
    delay(10);
}