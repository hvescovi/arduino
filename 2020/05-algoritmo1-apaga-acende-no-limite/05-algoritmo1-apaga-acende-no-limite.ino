// https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm

int pingPin = 2; // mapeamento do pino trigger
int echoPin = 3;  // mapeamento do pino echo

float duration; // tamanho da onda
float distance; // distancia percorrida

void setup() { // código executado somente uma vez
  // inicialização do canal serial de informação/comunicação
  Serial.begin(9600);

  // configurar pinos de saída (leds)
  for (int i = 4; i <= 13; i++) { // 10 leds
    pinMode(i, OUTPUT);
  }

}

void loop() { // código executado repetidamente

   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

   // o valor 5 foi escolhido ao acaso como um limite
   if (inches > 5) { // se está distante...
      acionar_leds(LOW); // apaga os leds
   } else { // senão (está próximo)...
      acionar_leds(HIGH); // acende os leds!
   }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void acionar_leds(int parametro) {

  // percorre os leds definindo o sinal (alto ou baixo)
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, parametro);
  }

}
