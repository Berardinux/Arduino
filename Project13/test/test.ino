#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold[] = { 500, 1000, 1500, 2000};
int ledPin[] = { 10, 11, 12, 13};

void setup() {
  Serial.begin(9600);
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  if (sensorValue > threshold[0]) {
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], LOW);
    if (sensorValue > threshold[1]) {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[2], LOW);
      digitalWrite(ledPin[3], LOW); 
      if (sensorValue > threshold[2]) {
        digitalWrite(ledPin[0], HIGH);
        digitalWrite(ledPin[1], LOW);
        digitalWrite(ledPin[2], LOW);
        digitalWrite(ledPin[3], LOW);
        if (sensorValue > threshold[3]) {
          digitalWrite(ledPin[0], LOW);
          digitalWrite(ledPin[1], LOW);
          digitalWrite(ledPin[2], LOW);
          digitalWrite(ledPin[3], LOW);
        }
      }
    }
  } else {
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
  }
  delay(10);

  Serial.print("[0]: ");
  Serial.print(threshold[0]);
  Serial.print(", [1]: ");
  Serial.print(threshold[1]);
  Serial.print(", [2]: ");
  Serial.print(threshold[2]);
  Serial.print(", [3]: ");
  Serial.print(threshold[3]);
  Serial.print(", The Sensor Value: ");
  Serial.println(sensorValue);
}