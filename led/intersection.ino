int red = 10;
int yellow = 9;
int green = 8;
int button = 12;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button,INPUT);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
}

void loop(){
    if (digitalRead(button) == HIGH){
        delay(15); //soft debounce
        if (digitalRead(button) == HIGH) {
          changeLights();
        }
    }
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
    delay(8000);
}