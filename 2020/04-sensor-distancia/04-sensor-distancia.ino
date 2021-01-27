// https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm

int pingPin = 2; // mapeamento do pino trigger
int echoPin = 3;  // mapeamento do pino echo

float duration; // tamanho da onda
float distance; // distancia percorrida

void setup() { // código executado somente uma vez
  // inicialização do canal serial de informação/comunicação
  Serial.begin(9600);
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
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
