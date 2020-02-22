#include <Servo.h>
  
int gronn = 13;
int rod = 5;
int speaker = 2;
int servoPin = 10;
Servo servo;

int a = 6;
int b = 7;
int c = 11;
int d = 12;
int submit = 8;

String kode = "";
String svar = "ACCBDA";
int counter = 0;

void setup() {
  for (int x = 6; x <= 12; x++) {
    pinMode(x, INPUT);
  }
  pinMode(rod, OUTPUT);
  pinMode(gronn, OUTPUT);
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
  servo.attach(servoPin);
  servo.write(62);
}

void gronnPaa(){
  digitalWrite(gronn, HIGH);
  delay(340);
  tone(speaker, 500, 350); delay(450); tone(speaker, 750, 350); delay(450), tone(speaker, 1000, 350);
  delay(540);
  digitalWrite(gronn, LOW);
}

void rodPaa(){
  digitalWrite(rod, HIGH);
  delay(340);
  tone(speaker, 1000, 350); delay(450); tone(speaker, 500, 350);
  delay(540);
  digitalWrite(rod, LOW);
}

void timeOut(){
  digitalWrite(rod, HIGH);
  tone(speaker, 1000, 500); 
  delay(600);
  tone(speaker, 1000, 500);
  Serial.println("--[ TIMEOUT I 1 MINUTT ]--");

  // teller ned fra 60
  for (int x = 60; x != 0; x--) { 
    Serial.print("Sekunder: ");
    Serial.println(x); 
    tone(speaker, 800, 140); 
    delay(1000); 
  }
  tone(speaker, 1500, 200); delay(1300);
  digitalWrite(rod, LOW);
  counter=0;
}

void loop() {
  if (digitalRead(a)==0){
    kode.concat("A"); delay(350);}

  if (digitalRead(b)==0){
    kode.concat("B"); delay(350);}

  if (digitalRead(c)==0){
    kode.concat("C"); delay(350);}

  if (digitalRead(d)==0){
    kode.concat("D"); delay(350); }

  if (digitalRead(submit)==0){

    if (counter >= 3) { timeOut(); }
    
    // om koden er tom - gi feil
    if (kode == ""){ 
      counter++;
      Serial.println("Feil kode"); 
      Serial.print("Antall forsøk: ");
      Serial.println(counter); 
      rodPaa(); 
      delay(400);
      servo.write(62); }

    // om koden er riktig
    else if (kode == svar){ 
      Serial.println("RIKTIG!"); 
      kode=""; 
      gronnPaa();
      servo.write(157);
      delay(400);
      counter=0; }

    // om koden hverken er riktig eller tom 
    else {
      counter++;
      Serial.println("Feil kode");
      Serial.print("Antall forsøk: ");
      Serial.println(counter);
      rodPaa();
      kode="";
      delay(400);
      servo.write(62); }
  }
}
