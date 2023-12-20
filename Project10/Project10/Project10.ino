const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
    Serial.begin(9600);
    pinMode(directionSwitchPin, INPUT);
    pinMode(onOffSwitchStateSwitchPin, INPUT);
    pinMode(controlPin1, OUTPUT);
    pinMode(controlPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW);
}

void loop() {
    onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
    delay(1);
    directionSwitchState = digitalRead(directionSwitchPin);
    motorSpeed = analogRead(potPin) / 4;

    if (onOffSwitchState != previousOnOffSwitchState) {
        if (onOffSwitchState == HIGH) {
            motorEnabled = !motorEnabled;
        }
    }

    if (directionSwitchState != previousDirectionSwitchState) {
        if (directionSwitchState == HIGH) {
            motorDirection = !motorDirection;
        }
    }

    if (motorDirection == 1) {
        digitalWrite(controlPin1, HIGH);
        digitalWrite(controlPin2, LOW);
    } else {
        digitalWrite(controlPin1, LOW);
        digitalWrite(controlPin2, HIGH);
    }

    if (motorEnabled == 1) {
        analogWrite(enablePin, motorSpeed);
    } else {
        analogWrite(enablePin, 0);
    }
    Serial.print("Pin 2: ");
    Serial.print(digitalRead(controlPin1));
    Serial.print(", Pin 3: ");
    Serial.print(digitalRead(controlPin2));
    Serial.print(", Pin 9: ");
    Serial.print(analogRead(enablePin));
    Serial.print(", Switch State: ");
    Serial.print(onOffSwitchState);
    Serial.print(", Previous Switch State: ");
    Serial.println(previousOnOffSwitchState);
    //Serial.println(digitalRead(onOffSwitchStateSwitchPin));
}