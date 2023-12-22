const int potPin = A0;
const int optoPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(optoPin, OUTPUT);
}

void loop() {
  int potMeter = analogRead(potPin);
  int optoOne = analogRead(A1);
  int optoTwo = analogRead(A2);
  Serial.print("A0: ");
  Serial.print(potMeter);
  Serial.print(", A1: ");
  Serial.print(optoOne);
  Serial.print(", A2: ");
  Serial.println(optoTwo);

  if (potMeter > 1000) {
    digitalWrite(optoPin, HIGH);
  } else if (potMeter > 900) {
    digitalWrite(optoPin, LOW);
  } else if (potMeter > 800) {
    digitalWrite(optoPin, HIGH);
  } else if (potMeter > 700) {
    digitalWrite(optoPin, LOW);
  } else if (potMeter > 600) {
    digitalWrite(optoPin, HIGH);
  } else if (potMeter > 500) {
    digitalWrite(optoPin, LOW);
  } else if (potMeter > 400) {
    digitalWrite(optoPin, HIGH);
  } else if (potMeter > 300) {
    digitalWrite(optoPin, LOW);
  } else if (potMeter > 200) {
    digitalWrite(optoPin, HIGH);
  } else if (potMeter > 100) {
    digitalWrite(optoPin, LOW);
  } else {
    digitalWrite(optoPin, HIGH);
  }
  delay(10);
}