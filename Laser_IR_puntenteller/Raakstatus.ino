void Raakstatus(){
  if (Team == 1){ //Team groen
  if (results.value == 854656239 && TO == 0){ // Geraakt door team blauw
  Raak = 1;
  digitalWrite(groenLED, HIGH);
  digitalWrite(blauwLED, LOW);
}
  if (results.value == 2001751733 && TO == 0){ // Geraakt door team geel
  Raak = 1;
  digitalWrite(roodLED, LOW);
  digitalWrite(groenLED, LOW);
}
  if (results.value == 543851703 && TO == 0){ // Geraakt door team rood
  Raak = 1;
  digitalWrite(groenLED, HIGH);
  digitalWrite(roodLED, LOW);
}
  }
  if (Team == 2){ //Team blauw
  if (results.value == 3915437507 && TO == 0){ // Geraakt door team groen
  Raak = 1;
  digitalWrite(blauwLED, HIGH);
  digitalWrite(groenLED, LOW);
}
  if (results.value == 2001751733 && TO == 0){ // Geraakt door team geel
  Raak = 1;
  digitalWrite(blauwLED, HIGH);
  digitalWrite(groenLED, LOW);
  digitalWrite(roodLED, LOW);
}
  if (results.value == 543851703 && TO == 0){ // Geraakt door team rood
  Raak = 1;
  digitalWrite(blauwLED, HIGH);
  digitalWrite(roodLED, LOW);
}
  }
  if (Team == 3){ //Team rood
  if (results.value == 3915437507 && TO == 0){ // Geraakt door team groen
  Raak = 1;
  digitalWrite(roodLED, HIGH);
  digitalWrite(groenLED, LOW);
}
  if (results.value == 2001751733 && TO == 0){ // Geraakt door team geel
  Raak = 1;
  digitalWrite(groenLED, LOW);
}
  if (results.value == 854656239 && TO == 0){ // Geraakt door team blauw
  Raak = 1;
  digitalWrite(roodLED, HIGH);
  digitalWrite(blauwLED, LOW);
}
  }
  if (Team == 4){ //Team geel
  if (results.value == 3915437507 && TO == 0){ // Geraakt door team groen
  Raak = 1;
  digitalWrite(roodLED, HIGH);
}
  if (results.value == 543851703 && TO == 0){ // Geraakt door team rood
  Raak = 1;
  digitalWrite(groenLED, HIGH);
}
  if (results.value == 854656239 && TO == 0){ // Geraakt door team blauw
  Raak = 1;
  digitalWrite(roodLED, HIGH);
  digitalWrite(groenLED, HIGH);
  digitalWrite(blauwLED, LOW);
}
  }
}
