int entrada = 2;

void setup() {
  pinMode(entrada, INPUT);
  Serial.begin(9600);
  Serial.println("Inicio...");
}

void loop() {
  bool leitura = digitalRead(entrada);

  if(leitura == HIGH){
    Serial.println("Ligado");
  }
  
  else{
    Serial.println("Desligado");
  }
  
  delay(3000);
}
