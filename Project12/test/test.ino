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
int lock;
int Value;
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
}

void loop() {
  int Switch = digitalRead(switchPin);
  if (Switch == 0) {
    if (Value == 0) {
      Value++;
    }
  } else if (Switch == 1) {
    if (Value == 1) {
      Value--;
    }
  }
  if (Value == 0) {
    lock = 0;
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
  } else if (Value == 1) {
    lock = 90;
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);

  }


  myServo.write(lock);

  Serial.print("Pin 2 ");
  Serial.print(digitalRead(switchPin));
  Serial.print(", Pin 3 ");
  Serial.print(digitalRead(yellowLed));
  Serial.print(", Pin 4 ");
  Serial.print(digitalRead(greenLed));
  Serial.print(", Value ");
  Serial.print(Value);
  Serial.print(", lock: ");
  Serial.println(lock);
}