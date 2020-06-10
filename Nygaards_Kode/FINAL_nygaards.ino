
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;

int rightButton = 12;
int leftButton = 13;
int buzzer = 14;
int pressurePad = 15;


void setup() {
  //setter alle ledlysene til output
  for (int led = 0; led < 12; led++){
    pinMode(led, OUTPUT);
  }
  
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(pressurePad, INPUT);
}

//kjoerer metodene som gjoer at lysene blinker til hoyre, venstre og bremselys
void loop(){
    leftTurn();
    rightTurn();
    brakes();
}

//hvis du trykker paa venstre vil denne metoden kalle paa dancingLeftLeds() som gjoer at 
//lysene "glir" mot venstre
void leftTurn(){
  if (digitalRead(leftButton) == HIGH){
      tone(buzzer, 2500, 65);
      dancingLeftLeds();
      delay(100);
      eraseAllLeds();
      delay(50); 
  }else{ 
    eraseAllLeds();
  }
}

//Lysene beveger seg mot venstre med "rullende/glidende" lys
//Kjoeres når leftTurn() kalles / syklisten trykker på blink til venstre knappen
void dancingLeftLeds(){
    for (int i = 6; i > 0; i--){
      digitalWrite(i, HIGH);
      delay(75);
  }
}

//samme som leftTurn(). kaller paa dancingRightLeds() naar syklist trykker paa
//blink mot hoyre
void rightTurn(){
  if (digitalRead(rightButton) == HIGH){
    tone(buzzer, 2500, 65);
    dancingRightLeds();
    delay(100);
    eraseAllLeds();
    delay(50); 
  } else {
    eraseAllLeds();
  }
}

//lysene beveger seg mot hoyre med en "rullende/glidende" bevegelse
//Kjoeres naar bruker trykker paa blink til hoyre og 
//righTurn() kalles paa
void dancingRightLeds(){
    for (int i = 7; i < 13; i++){
      digitalWrite(i, HIGH);
      delay(75);
  }
}

//Kode for pressurepad, vi har ikke komponenten, men lagde kode vi kunne bruke dersom vi hadde hatt den.
//Kaller paa brakeLights() dersom presset paa bremsen gaar over et visst punkt
void brakes(){
  int pressure = analogRead(pressurePad);
  if (pressure > 500) {
    brakeLights();
  }
}

//kalles paa av brakes(), gjoer at lysene i midten av breadbordet lyser (pilene lyser ikke)
void brakeLights(){
    for (int i = 0; i < 13; i++){
    digitalWrite(i, HIGH);
  }
  delay(75);
}

//skrur av alle ledlys
void eraseAllLeds(){
    for (int i = 13; i > 0; i--){
      digitalWrite(i, LOW);
  }
}

}
