#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <TM74HC595Display.h>

int RECV_PIN = 11; //IR
int SCLK = 8; //Tube module
int RCLK = 7; //Tube module
int DIO = 6; //Tube module
int Raak = 0; //Tube module

int roodLED = 2; //RGBLED - rood
int groenLED = 4; //RGBLED - groen
int blauwLED = 5; //RGBLED - blauw

int Getal = 0;
int Tiental = 0;
int TO = 0;
int Team = 0;
int programma = 0;

//IR
IRrecv irrecv(RECV_PIN);
//IR
decode_results results;

TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char LED_0F[10];

void setup() {
Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
Raak = 0;
pinMode(roodLED, OUTPUT);
pinMode(groenLED, OUTPUT);
pinMode(blauwLED, OUTPUT);
pinMode(3, OUTPUT);
digitalWrite(roodLED, HIGH);
digitalWrite(groenLED, HIGH);
digitalWrite(blauwLED, HIGH);
digitalWrite(3, HIGH);
Getal = 0;
Tiental = 0;
TO = 0;
Team = 0;
programma = 0;

LED_0F[0] = 0x00; //ALL
LED_0F[1] = 0xFF; //NONE
LED_0F[2] = 0x7F; //1
LED_0F[3] = 0xBF; //2
LED_0F[4] = 0xDF; //3
LED_0F[5] = 0xEF; //4
LED_0F[6] = 0xF7; //5
LED_0F[7] = 0xFB; //6
LED_0F[8] = 0xFD; //7
LED_0F[9] = 0xFE; //8

}

void loop() {

  if (Getal == 0){
//Getal 0
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[5], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}
  if (Tiental == 0){
//Getal 0
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[5], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}

if (TO == 1){
  delay(5000);
  TO = 0;
  Raak = 0;
  digitalWrite(roodLED, HIGH);
  digitalWrite(groenLED, HIGH);
  digitalWrite(blauwLED, HIGH);
  delay(50);
  Teamkeuze ();
  irrecv.resume(); // Receive the next value
}

 if ((Raak == 1) && (TO == 0)){ //Tel op
    TO = 1;
    Getal = Getal + 1;
    delay(500);
    if (Getal == 10){
      Getal = 0;
      Tiental = Tiental + 1;
    }
 }
if (Getal == 1){
//Getal 1
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[7], 0b0001);
}

if (Getal == 2){
//Getal 2
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[5], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Getal == 3){
//Getal 3
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Getal == 4){
//Getal 4
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[7], 0b0001);
}

if (Getal == 5){
//Getal 5
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Getal == 6){
//Getal 6
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[5], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Getal == 7){
//Getal 7
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[7], 0b0001);
}

if (Getal == 8){
//Getal 8
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[5], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Getal == 9){
//Getal 9
disp.send(LED_0F[9], 0b0001);
disp.send(LED_0F[4], 0b0001);
disp.send(LED_0F[8], 0b0001);
disp.send(LED_0F[3], 0b0001);
disp.send(LED_0F[7], 0b0001);
disp.send(LED_0F[6], 0b0001);
}

if (Tiental == 1){
//Getal 1
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[7], 0b0010);
}
if (Tiental == 2){
//Getal 2
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[5], 0b0010);
disp.send(LED_0F[6], 0b0010);
}
if (Tiental == 3){
//Getal 3
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}
if (Tiental == 4){
//Getal 4
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[7], 0b0010);
}

if (Tiental == 5){
//Getal 5
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}

if (Tiental == 6){
//Getal 6
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[5], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}

if (Tiental == 7){
//Getal 7
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[7], 0b0010);
}

if (Tiental == 8){
//Getal 8
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[5], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}

if (Tiental == 9){
//Getal 9
disp.send(LED_0F[9], 0b0010);
disp.send(LED_0F[4], 0b0010);
disp.send(LED_0F[8], 0b0010);
disp.send(LED_0F[3], 0b0010);
disp.send(LED_0F[7], 0b0010);
disp.send(LED_0F[6], 0b0010);
}
if (irrecv.decode(&results) && TO == 0) {
    Serial.println(results.value);
    Raakstatus();
    irrecv.resume(); // Receive the next value
    if (Team == 0){
    Teamkeuze();
    }
}
if (results.value == 553601207 || programma == 2){ //Oude programma draaien met behulp van knop 2 op de afstandsbediening
  programma = 2;
  Getal = 10;
  Tiental = 10;
  disp.send(LED_0F[3], 0b0001);
  disp.send(LED_0F[3], 0b0010);
  Oude_programma();
}
  if (results.value == 553603247){ //Reset alles met behulp van de AAN/UIT-knop van de afstandsbediening
    Raak = 0;
    pinMode(roodLED, OUTPUT);
    pinMode(groenLED, OUTPUT);
    pinMode(blauwLED, OUTPUT);
    digitalWrite(roodLED, HIGH);
    digitalWrite(groenLED, HIGH);
    digitalWrite(blauwLED, HIGH);
    Getal = 0;
    Tiental = 0;
    TO = 0;
    Team = 0;
    programma = 0;
    Teamkeuze();
 }
}

