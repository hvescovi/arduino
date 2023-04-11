void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(300);
}