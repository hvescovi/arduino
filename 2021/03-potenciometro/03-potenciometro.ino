// declaração de variáveis

int potenciometro = 0; // valor do potenciômetro, a ser lido

void setup() { // código executado somente uma vez
  // inicialização do canal serial de informação/comunicação
  Serial.begin(9600);
}

void loop() { // código executado repetidamente

  // fazer a leitura do valor do potenciômetro
  potenciometro = analogRead(A0); // é lido um valor de 0 a 1023

  // exibir
  Serial.println(potenciometro);

  delay(200);
}
