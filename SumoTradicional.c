// Código utilizado na competição de 2015
// Data da última mofificação: 15/08

#include <Ultrasonic.h>

#define SOM_FRENTE_ECHO 12
#define SOM_FRENTE_TRIG 13
#define SOM_DIREITA_ECHO 11
#define SOM_DIREITA_TRIG 10

#define MOTOR_E_F 3
#define MOTOR_E_T 2
#define MOTOR_D_F 4
#define MOTOR_D_T 5

Ultrasonic sensorSomFrente(SOM_FRENTE_TRIG, SOM_FRENTE_ECHO);   
Ultrasonic sensorSomDireita(SOM_DIREITA_TRIG, SOM_DIREITA_ECHO);  

boolean somFrente, somDireito;

void giraHorario() { 

  /* Motor esquerdo pra frente*/ 
  digitalWrite(MOTOR_E_F, HIGH);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito pra tras */
  digitalWrite(MOTOR_D_T, HIGH);  
  digitalWrite(MOTOR_D_F, LOW);
  
}

void giraAntiHorario() {

  /* Motor esquerdo pra tras */
  digitalWrite(MOTOR_E_T, HIGH);
  digitalWrite(MOTOR_E_F, LOW);

  /* Motor direito pra frente */
  digitalWrite(MOTOR_D_F, HIGH); 
  digitalWrite(MOTOR_D_T, LOW);  

}

void avanca() {

 /* Motor esquerdo pra frente */
  digitalWrite(MOTOR_E_F, HIGH);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito pra frente */
  digitalWrite(MOTOR_D_F, HIGH);
  digitalWrite(MOTOR_D_T, LOW);    
  
  delay(200);
}

void volta() {

   /* Motor esquerdo pra tras */
  digitalWrite(MOTOR_E_F, LOW);
  digitalWrite(MOTOR_E_T, HIGH);

  /* Motor direito tras */
  digitalWrite(MOTOR_D_F, LOW);
  digitalWrite(MOTOR_D_T, HIGH);  

}

boolean testaSomDireito() {

  boolean retorno = false;
  int dist = sensorSomDireita.Ranging(CM);
  /* Valor analogico do pino do sensor*/;
 
  if(dist <= 60) {
    
    while(!testaSomFrente())
      giraHorario();    
      
    delay(10);
    
    retorno = true;
 
  }  

  return retorno;
}

boolean testaSomFrente() {

  boolean retorno = false;
  int dist = sensorSomFrente.Ranging(CM);
  /* Valor analogico do pino do sensor*/;

  if(dist <= 60) {
    retorno = true;
  }
  return retorno;
}




void setup() {
  
  pinMode(MOTOR_D_F, OUTPUT);
  pinMode(MOTOR_D_T, OUTPUT);
  pinMode(MOTOR_E_F, OUTPUT);
  pinMode(MOTOR_E_T, OUTPUT);
  
  pinMode(SOM_FRENTE_ECHO, INPUT);
  pinMode(SOM_FRENTE_TRIG, OUTPUT);
  pinMode(SOM_DIREITA_ECHO, INPUT);
  pinMode(SOM_DIREITA_TRIG, OUTPUT);
  
}

void loop() {  
  
    somFrente = testaSomFrente();
    
    if(somFrente) {
      avanca();
      delay(10);
    }

    else {
     somDireito = testaSomDireito();
     if(!somDireito)    
       giraAntiHorario();
    }
}
