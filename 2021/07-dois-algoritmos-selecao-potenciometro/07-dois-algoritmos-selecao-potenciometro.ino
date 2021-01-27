int pingPin = 2; // mapeamento do pino trigger
int echoPin = 3;  // mapeamento do pino echo

float duration; // tamanho da onda
float inches; // polegadas
float cm; // centímetros

// valor escolhido observando variação no sensor de distância em centímetros
int maxDist = 20; 

// são 10 leds a acender
// divide um intervalo de máximo de polegadas em 10 partes, em centímetros
int   salto = maxDist / 10;

// valor a ser lido do potenciômetro
int potenciometro = 0;

void setup() { // código executado somente uma vez
  // inicialização do canal serial de comunicação
  Serial.begin(9600);

  // configurar pinos de saída (leds)
  for (int i = 4; i <= 13; i++) { // 10 leds
    pinMode(i, OUTPUT);
  }
  
  // configurar pinos do sensor de distância
  pinMode(pingPin, OUTPUT); // pino trigger (envia onda)
  pinMode(echoPin, INPUT); // pino echo (recebe informação)
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

void algoritmo1(int cm) {
   if (cm >= 10) { // está longe?
      acionar_leds(0); // apaga os leds
   } else { // senão (está próximo)...
      acionar_leds(10); // acende os leds!
   }
}

void algoritmo2(int cm) {  
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

void loop() { // código executado repetidamente

   // emissão de sinais do sensor de distância
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   // cálculos de distância
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   // exibição de informações
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
 
   delay(100);

   // leitura do valor do potenciômetro
   // é lido um valor de 0 a 1023
   potenciometro = analogRead(A0); 

   // verificação da lógica
   // considera-se aproximadamente o meio do potenciômetro
   if (potenciometro <= 511) { 
      algoritmo1(cm);
   } else {
      algoritmo2(cm);
   }
}
// https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm
