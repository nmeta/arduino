int button = 12;
int motor = 8;
int pressed;

void setup(){
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(motor,OUTPUT);
  digitalWrite(motor,LOW);
}

void loop(){
  pressed = digitalRead(button);
  //if (digitalRead(button) == HIGH){
  if (pressed == 1){
      power();
  } else {
      unpower();
  }
}

void power(){
  Serial.print("powering motor on pin ");
  Serial.print(motor);
  Serial.println("...");
  digitalWrite(motor,HIGH);
}

void unpower(){
  Serial.println("idling...");
  digitalWrite(motor,LOW);
}
