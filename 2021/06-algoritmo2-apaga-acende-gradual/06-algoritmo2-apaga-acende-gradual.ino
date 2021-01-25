// https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm

int pingPin = 2; // mapeamento do pino trigger
int echoPin = 3;  // mapeamento do pino echo

float duration; // tamanho da onda
float distance; // distancia percorrida

// valor escolhido observando variação no sensor de distãncia
// EM CENTÍMETROS
int maxDist = 20; 

// são 10 leds a acender
// divide um intervalo de máximo de polegadas em 10 partes
// *** em centímetros ***
int   salto = maxDist / 10;


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

   // verifica distância proporcional ao máximo
   if (cm >= salto * 10) {  // > 20?
      acionar_leds(10);
   } else if (cm >= salto * 9) { // > 18?
      acionar_leds(9);
   } else if (cm >= salto * 8) {  // > 16?
      acionar_leds(8);
   } else if (cm >= salto * 7) {
      acionar_leds(7);
   } else if (cm >= salto * 6) {
      acionar_leds(6);
   } else if (cm >= salto * 5) {
      acionar_leds(5);
   } else if (cm >= salto * 4) {
      acionar_leds(4);
   } else if (cm >= salto * 3) {
      acionar_leds(3);
   } else if (cm >= salto * 2) { // > 4?
      acionar_leds(2); // acende 2 leds
   } else if (cm >= salto) { // > 2?
      acionar_leds(1); // acende 1 led
   } else {
      acionar_leds(0); // não acende nenhum led
   } 

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

// aciona os leds até o n-ésimo led
void acionar_leds(int n) {

  // apaga todos os leds
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, LOW);
  }

  // acende os leds até o desejado
  for (int i = 4; i <= 4+n-1; i++) {
    digitalWrite(i, HIGH);
  }

}
