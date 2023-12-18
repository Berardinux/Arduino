const int switchPin = 2;
const int motorPin = 9;

int switchState = 0;
int motorState = 0;

void setup() {
    Serial.begin(9600);
    pinMode(motorPin, OUTPUT);
    pinMode(switchPin, INPUT);
}
void loop() {
    switchState = digitalRead(switchPin);
    motorState = analogRead(motorPin);

    if (switchState == HIGH) {
        digitalWrite(motorPin, HIGH);
    } else {
        digitalWrite(motorPin, LOW);
    }
    Serial.print("Pin 2: ");
    Serial.print(switchState);
    Serial.print(", Pin 9: ");
    Serial.println("motorState");
}