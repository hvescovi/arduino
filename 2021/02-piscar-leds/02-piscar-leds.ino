void setup() { // código executado somente uma vez


  // configurar pinos de saída (leds)
  for (int i = 4; i <= 13; i++) { // 10 leds
    pinMode(i, OUTPUT);
  }
  
}

void loop() { // código executado repetidamente

  // acender os leds
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, HIGH);
  }
  
  delay(1000); // esperar 1 segundo
  
  // apagar os leds
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }

  delay(1000); // esperar 1 segundo
  
}
