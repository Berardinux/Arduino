#include <Servo.h>

Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
const int quietKnock = 10;
const int loudKnock = 100;

int knockVal;
int switchVal;
int numberOfKnocks = 0;
bool locked = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode (greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("the box is unlocked!");
}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("the box is locked!");
      delay(1000);
    }
  }
  if (locked == true) {
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" More knocks to go");
    }
    if (numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("the box is unlocked!");
      numberOfKnocks = 0;
    }
  }
}

bool checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  } else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}