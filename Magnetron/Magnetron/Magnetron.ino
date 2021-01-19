int knopminuut = 0;
int knopminuut_indruk = 0;
int knopstart = 0;
int knopstart_indruk = 0;
int AAN = 0;
int aantalminuten = 0;
int tijd = 0;
int reset = 0;
int resetVAR = 0;

void setup() {
  // relais determineren, één relais nodig voor twee verbindingen
  pinMode(pin RELAIS, OUTPUT);

  //Knoppen determineren
  pinMode(pin KM, INPUT);
  pinMode(pin KS, INPUT);
  pinMode(pin RS, INPUT);
  
  //Knopppen op HIGH zetten; sluit deze aan op Ground
  digitalWrite(pin KM, HIGH);
  digitalWrite(pin KS, HIGH);
  digitalWrite(pin RS, HIGH);

  //SD-reader
  
}

void loop() {
  // put your main code here, to run repeatedly:
knopminuut = digitalRead(pin KM);
knopstart = digitalRead(pin KS);
reset = digitalRead(pin RS);

if (reset == LOW){
  resetVAR = 1;
  delay(1000);
  if (resetVAR == 1 && reset == LOW){
    resetVAR = 0;
  }
}

if (resetVAR == 0){
//Instellen van minuut
if (knopminuut == LOW && knopminuut_indruk == 0){
  knopminuut_indruk = 1;
  aantalminuten = +1 ;
  delay(100);
}

//Aanzetten van systeem
if (knopstart == LOW && knopstart_indruk == 0){
  knopminuut_indruk = 1;
  AAN == 1;
}

if (AAN == 1){
  digitalWrite(pin RELAIS, HIGH);
  tijd = aantalminuten*60000;
  delay(tijd);
  aantalminuten = 0;
  tijd = 0;
  knopminuut_indruk = 0;
  knopstart_indruk = 0;
  AAN = 0;  
}

}
}
