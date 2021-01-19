void Teamkeuze(){ //Teamkleuren corresponderen met de kleuren van de knoppen op de afstandsbediening
  if (Team == 0){
if (results.value == 553627727 && TO == 0){ // Je wordt team groen
  Team = 1;
  digitalWrite(groenLED, LOW);
  irrecv.resume(); // Receive the next value
}
  if (results.value == 553644047 && TO == 0){ // Je wordt team blauw
  Team = 2;
  digitalWrite(blauwLED, LOW);
    irrecv.resume(); // Receive the next value
}
  if (results.value == 553635887 && TO == 0){ // Je wordt team rood
  Team = 3;
  digitalWrite(roodLED, LOW);
    irrecv.resume(); // Receive the next value
}
   if (results.value == 553611407 && TO == 0){ // Je wordt team geel
  Team = 4;
  digitalWrite(roodLED, LOW);
  digitalWrite(groenLED, LOW);
    irrecv.resume(); // Receive the next value
}
  }
   if (Team == 1){
    digitalWrite(groenLED, LOW);
  }
   if (Team == 2){
    digitalWrite(blauwLED, LOW);
  }
  if (Team == 3){
    digitalWrite(roodLED, LOW);
  }
  if (Team == 4){
  digitalWrite(roodLED, LOW);
  digitalWrite(groenLED, LOW);
  }
}

