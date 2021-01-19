int Knop1 = 1; //Knop 1 input
//int Knop2 = 2; //Knop 2 input
int Knop3 = 3; //Knop 3 input
int Knop4 = 4; //Knop 4 input
int Knop5 = 5; //Knop 5 input
int Knop6 = 6; //Knop 6 input
int Relais1 = 2; //Relais 1 LED knop output
int Relais2 = 8; //Relais 2 LED knop output
int Relais3 = 9; //Relais 3 LED knop output
int Relais4 = 10; //Relais 4 LED knop output
int Relais5 = 11; //Relais 5 LED knop output
//int Relais6 = 12; //Relais 6 LED knop output

int Reset = 12; //Systeem reset met deze knop

int Antwoord; //variabele om de juiste relais te bereiken
int Vast; // Systeem reageert niet meer op andere knoppen behalve Reset. '0' is niet erg. '1' blokkeert verdere invoer.

void setup() {
  // put your setup code here, to run once:
pinMode(Knop1, INPUT);
//pinMode(Knop2, INPUT);
pinMode(Knop3, INPUT);
pinMode(Knop4, INPUT);
pinMode(Knop5, INPUT);
pinMode(Knop6, INPUT);
pinMode(Relais1, OUTPUT);
digitalWrite(Relais1, LOW);
pinMode(Relais2, OUTPUT);
//Relais2 = LOW;
pinMode(Relais3, OUTPUT);
//Relais3 = LOW;
pinMode(Relais4, OUTPUT);
//Relais4 = LOW;
pinMode(Relais5, OUTPUT);
//Relais5 = LOW;
//pinMode(Relais6, OUTPUT);
//Relais6 = LOW;
Antwoord = 0;
Vast = 0;
pinMode(Reset, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(Knop1) == HIGH && Vast == 0){ //Knop invoer, antwoordvariabele past zich aan.
  digitalWrite(Relais1, LOW);
  Antwoord = 1;
  Vast = 1;
}
//if (Knop2 == HIGH && Vast == 0){ //Knop invoer, antwoordvariabele past zich aan
  Antwoord = 2;
  Vast = 1;
//}
if (Knop3 == HIGH && Vast == 0){ //Knop invoer, antwoordvariabele past zich aan
  Antwoord = 3;
  Vast = 1;
}
if (Knop4 == HIGH && Vast ==0){ //Knop invoer, antwoordvariabele past zich aan
  Antwoord = 4;
  Vast = 1;
}
if (Knop5 == HIGH && Vast == 0){ //Knop invoer, antwoordvariabele past zich aan
  Antwoord = 5;
  Vast = 1;
}
if (Knop6 == HIGH && Vast == 0){ //Knop invoer, antwoordvariabele past zich aan
  Antwoord = 6;
  Vast = 1;
}
//if (Antwoord == 1){ //Relais van desbetreffende knop gaat aan, LED gaat aan
//  digitalWrite(Relais1, HIGH);
//}
if (Antwoord == 2){ //Relais van desbetreffende knop gaat aan, LED gaat aan
  Relais2 = HIGH;
}
if (Antwoord == 3){ //Relais van desbetreffende knop gaat aan, LED gaat aan
  Relais3 = HIGH;
}
if (Antwoord == 4){ //Relais van desbetreffende knop gaat aan, LED gaat aan
  Relais4 = HIGH;
}
if (Antwoord == 5){ //Relais van desbetreffende knop gaat aan, LED gaat aan
  Relais5 = HIGH;
}
if (Antwoord == 6){ //Relais van desbetreffende knop gaat aan, LED gaat aan
  //Relais6 = HIGH;
}
if (digitalRead(Reset) == HIGH){
  digitalWrite(Relais1, LOW);
  Relais2 = LOW;
  Relais3 = LOW;
  Relais4 = LOW;
  Relais5 = LOW;
//  Relais6 = LOW;
  Antwoord = 0;
  Vast = 0;
}


}
