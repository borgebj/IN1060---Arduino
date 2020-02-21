int gronn = 13;
int rod = 5;
int speaker = 2;

int a = 6;
int b = 7;
int c = 11;
int d = 12;
int submit = 8;

String kode = "";

void setup() {
  for (int x = 6; x <= 12; x++) {
    pinMode(x, INPUT);
  }
  pinMode(rod, OUTPUT);
  pinMode(gronn, OUTPUT);
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
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

void loop() {
  if (digitalRead(a)==0){
    kode.concat("A"); delay(400);}

  if (digitalRead(b)==0){
    kode.concat("B"); delay(400);}

  if (digitalRead(c)==0){
    kode.concat("C"); delay(400);}

  if (digitalRead(d)==0){
    kode.concat("D"); delay(400); }

  if (digitalRead(submit)==0){

    // om koden er tom - gi feil
    if (kode==""){ Serial.println("Feil kode"); rodPaa(); delay(400); }

    // om koden er riktig
    else if (kode=="ACBD"){ 
      Serial.println("RIKTIG!"); 
      kode=""; 
      gronnPaa();
      delay(400); }

    // om koden hverken er riktig eller tom 
    else {
      rodPaa();
      kode="";
      delay(400);}
  }
}
