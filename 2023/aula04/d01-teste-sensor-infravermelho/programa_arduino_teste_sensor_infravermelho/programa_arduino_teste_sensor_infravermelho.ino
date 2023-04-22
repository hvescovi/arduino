int pinSensor = 4;
int pinLED = 13;

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int y = digitalRead(pinSensor);
  if (y == LOW) {
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }
  if (y == LOW) {
    Serial.write("0");
  } else {
    Serial.write("1");
  }
  delay(100);
}
