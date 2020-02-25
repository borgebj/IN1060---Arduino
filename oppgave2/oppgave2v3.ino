#include <Servo.h>

// output-pins og annet
int gronn = 13;
int rod = 5;
int speaker = 2;
int servoPin = 10;
int andreMotor = 9;
Servo servo;
Servo andre;

// input-pins
int a = 6;
int b = 7;
int c = 11;
int d = 12;
int submit = 8;

// variabler som skal sammenlignes
String kode = "";
String svar = "ACCBDA";
int counter = 0;

 
void setup() {

  // alle ports fra 6 til 12 blir satt som input
  for (int x = 6; x <= 12; x++) {
    pinMode(x, INPUT);
  }
  pinMode(rod, OUTPUT);
  pinMode(gronn, OUTPUT);
  pinMode(speaker, OUTPUT);

  // setter servo-pin til objektene deres
  servo.attach(servoPin);
  andre.attach(andreMotor);

  // startposisjon for de to servoene
  servo.write(145); 
  andre.write(120); 

}

//skrur paa gront lys og lager lyd
void gronnPaa(){
  digitalWrite(gronn, HIGH);
  delay(340);
  tone(speaker, 500, 350); delay(450); tone(speaker, 750, 350); delay(450), tone(speaker, 1000, 350);
  delay(540);
  digitalWrite(gronn, LOW);
}

// skrur paa rodt lys og lager lyd
void rodPaa(){
  digitalWrite(rod, HIGH);
  delay(340);
  tone(speaker, 1000, 350); delay(450); tone(speaker, 500, 350);
  delay(540);
  digitalWrite(rod, LOW);
}

// kode som kjores naar anall feil forsok er 3
void timeOut(){
  digitalWrite(rod, HIGH);
  tone(speaker, 1000, 500); 
  delay(600);
  tone(speaker, 1000, 500);

  // teller ned fra 60
  for (int x = 60; x != 0; x--) { 
    tone(speaker, 800, 140); 
    delay(1000); 
  }
  tone(speaker, 1500, 200); delay(1300);
  digitalWrite(rod, LOW);
  counter=0;
}

// kode som kjores naar kombinasjon er riktig
void riktigKode(){
  kode=""; 
  gronnPaa();
  servo.write(40);
  andre.write(20);
  delay(400);
  counter=0; 
}

// kode som kjores naar kombinasjon er feil
void feilKode() {
  counter++;
  rodPaa();
  kode="";
  delay(400);
  servo.write(145); 
  andre.write(120); 
}


// loop bestaar av if-setninger som sjekker hvilke metoder som skal kalles
void loop() {

// if-setning for hver knapp - legger til tilsvarende bokstav i kodesjekk-variabelen
  if (digitalRead(a)==0){
    kode.concat("A"); delay(300);}

  if (digitalRead(b)==0){
    kode.concat("B"); delay(300);}

  if (digitalRead(c)==0){
    kode.concat("C"); delay(300);}

  if (digitalRead(d)==0){
    kode.concat("D"); delay(300); }
        
// if-setning for submit-knappen - sjekker kombinasjonen av knappetrykk
  if (digitalRead(submit)==0){

    // sjekker forst om antall feil er 3 eller over - altsaa timeout
    if (counter >= 3) { timeOut(); }
    
    // om koden er tom - gi feil
    else if (kode == ""){ feilKode(); }

    // om koden er riktig
    else if (kode == svar){ riktigKode(); }

    // om koden hverken er riktig eller tom - gi feil
    else { feilKode(); }
  }
}
