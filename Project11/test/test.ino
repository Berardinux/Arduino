#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;

int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(switchPin, INPUT);
    lcd.print("Hello");
    lcd.setCursor(0, 1);
    lcd.print("Berardinux!");
}

void loop() {
    switchState = digitalRead(switchPin);
    if (switchState != prevSwitchState) {
        if (switchState == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Don't flip me");
            lcd.setCursor(0, 1);
            lcd.print("Berardinux");
        }
    }
    prevSwitchState = switchState;
    Serial.print("Switch State: ");
    Serial.println(digitalRead(switchPin));
}