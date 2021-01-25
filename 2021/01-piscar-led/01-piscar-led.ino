void setup() { // código executado somente uma vez
  pinMode(13, OUTPUT); // pino 13, saída
}

void loop() { // código executado repetidamente
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
