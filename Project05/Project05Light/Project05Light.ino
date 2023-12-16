#include <Servo.h>

Servo myServo;

double const SensorPin = A0;

void setup() {
    myServo.attach(9);
    Serial.begin(9600);
}

void loop() {
    double lightSensorValue = analogRead(SensorPin);
    Serial.print(" Sensor Value: ");
    Serial.print(lightSensorValue);
    int angleOfServo = map(lightSensorValue, 0, 13, 0, 179);
    Serial.print(", Angle of Servo: ");
    Serial.println(angleOfServo);
    if (angleOfServo < 60) {
      angleOfServo = 0;
    } else if (angleOfServo > 61 && angleOfServo < 120) {
      angleOfServo = 90;
    } else {
      angleOfServo = 179;
    }
    myServo.write(angleOfServo);
    delay(250);
}