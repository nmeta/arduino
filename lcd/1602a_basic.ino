//www.diyusthad.com
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, led = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int red = 10;
int yellow = 9;
int green = 8;
int button = 12;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button,INPUT);
    pinMode(led,OUTPUT);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
}

void loop(){
    writeToLcd("     hello","     world!",750);
    if (digitalRead(button) == HIGH){
        delay(15); //soft debounce
        if (digitalRead(button) == HIGH) {
          changeLights();
        }
    }
}

void pulse(){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
}

void writeToLcd(char *line1, char *line2, int delayS){
    lcd.begin(16, 2);
    lcd.print(line1);
    lcd.setCursor(0,1);
    lcd.print(line2);
    delay(delayS);
}

void changeLights(){
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(4000);
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
    delay(4000);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
}