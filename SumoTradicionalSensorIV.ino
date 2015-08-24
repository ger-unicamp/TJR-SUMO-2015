// Projeto robo sumô com sensor de detecção de linha (luz)
// Data da última mofificação: 14/08/2015
// NÃO utilizado na competição

/* OBS: definir o tempo de delay nas fugas */

#include <Ultrasonic.h>
#include <QTRSensors.h>

#define LIMITE_BRANCO 3500
#define LIMITE_BRANCO_FRENTE 400

#define LUZ_FRENTE_1 18
#define LUZ_FRENTE_2 19
#define LUZ_ESQUERDA_1 16
#define LUZ_ESQUERDA_2 17
#define LUZ_DIREITA_1 14
#define LUZ_DIREITA_2 15

#define SOM_FRENTE_ECHO 12
#define SOM_FRENTE_TRIG 13
#define SOM_DIREITA_ECHO 11
#define SOM_DIREITA_TRIG 10


#define MOTOR_E_F 3
#define MOTOR_E_T 2
#define MOTOR_D_F 4
#define MOTOR_D_T 5

int limiarEsquerda1,limiarEsquerda2, limiarDireita1, limiarDireita2, limiarFrente1, limiarFrente2;

QTRSensorsRC sensorLuzFrente((unsigned char[]) {LUZ_FRENTE_1, LUZ_FRENTE_2}, 2);
QTRSensorsRC sensorLuzDireita((unsigned char[]) {LUZ_DIREITA_1, LUZ_DIREITA_2}, 2);
QTRSensorsRC sensorLuzEsquerda((unsigned char[]) {LUZ_ESQUERDA_1, LUZ_ESQUERDA_2}, 2);

Ultrasonic sensorSomFrente(SOM_FRENTE_TRIG, SOM_FRENTE_ECHO);   
Ultrasonic sensorSomDireita(SOM_DIREITA_TRIG, SOM_DIREITA_ECHO);  

boolean luzEsquerdo, luzDireito, luzFrente; // apenas dizem se detectou algo ou nao
boolean somFrente, somDireito;

/* Vetores que guardam o valor dos sensores de luz */
unsigned int readLuzFrente[2];
unsigned int readLuzEsquerda[2];
unsigned int readLuzDireita[2];

void giraHorario() { 
  
  //Serial.print("-------------Horario\n");

  /* Motor esquerdo pra frente*/ 
  digitalWrite(MOTOR_E_F, HIGH);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito pra tras */
  digitalWrite(MOTOR_D_T, HIGH);  
  digitalWrite(MOTOR_D_F, LOW);
  
  //Perigoso 
  //delay(1000);
}

void giraAntiHorario() {
  
  //Serial.print("-------------AntiHorario\n");

  /* Motor esquerdo pra tras */
  digitalWrite(MOTOR_E_T, HIGH);
  digitalWrite(MOTOR_E_F, LOW);

  /* Motor direito pra frente */
  digitalWrite(MOTOR_D_F, HIGH); 
  digitalWrite(MOTOR_D_T, LOW); 
  
  //Perigoso
 // delay(1000);
  
}

void fugaDireita() {
  
  //Serial.print("-------------FugaDireita\n");

  /* Motor esquerdo parado */
  digitalWrite(MOTOR_E_F, LOW);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito pra frente */
  digitalWrite(MOTOR_D_F, HIGH);
  digitalWrite(MOTOR_D_T, LOW); 
 
  //Perigoso
 //delay(1000); 
}

void fugaEsquerda() {
  
  //Serial.print("------------Fuga Esquerda\n");

  /* Motor esquerdo pra frente */
  digitalWrite(MOTOR_E_F, HIGH);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito parado */
  digitalWrite(MOTOR_D_F, LOW);
  digitalWrite(MOTOR_D_T, LOW);  
  
  //Perigoso
  //delay(1000);
}

void avanca() {
  
  //Serial.print("-------------Avanca\n");

 /* Motor esquerdo pra frente */
  digitalWrite(MOTOR_E_F, HIGH);
  digitalWrite(MOTOR_E_T, LOW);

  /* Motor direito pra frente */
  digitalWrite(MOTOR_D_F, HIGH);
  digitalWrite(MOTOR_D_T, LOW);    
  
  //delay(1000);
}

void volta() {
  
 // Serial.print("--------------Volta\n");

   /* Motor esquerdo pra tras */
  digitalWrite(MOTOR_E_F, LOW);
  digitalWrite(MOTOR_E_T, HIGH);

  /* Motor direito tras */
  digitalWrite(MOTOR_D_F, LOW);
  digitalWrite(MOTOR_D_T, HIGH);  
  
  
  //Perigoso
  //delay(1000);
}

//Explicacao sobre a periculosidade do delay, este delay de 1000 significa que vcs sempre irao se deslocar em intervalos de 1s, o que talvez seja muito para o ajuste que o robo deve fazer


boolean testaLuzEsquerdo() {

  boolean retorno = false;
  
  sensorLuzEsquerda.read(readLuzEsquerda); // atualiza a leitura dos sensores de cor
  
 // Serial.println(readLuzEsquerda[0]); 
 // Serial.println(readLuzEsquerda[1]); 
  
  if(readLuzEsquerda[0] > (float)limiarEsquerda1 * (float)1.5 || readLuzEsquerda[1] > (float)limiarEsquerda2 * (float)1.5) {
    retorno = true;  
   // Serial.print("Preto Esquerda\n"); 
  }
  
   // Serial.print("Branco Esquerda\n");
    
  //delay(1000);

  return retorno;
}

boolean testaLuzDireito() {

  boolean retorno = false;
  sensorLuzDireita.read(readLuzDireita); // atualiza a leitura dos sensores de cor
  
  //Serial.println(readLuzDireita[0]); 
  //Serial.println(readLuzDireita[1]); 

  if(readLuzDireita[0] > (float)limiarDireita1 * (float) 1.5 || readLuzDireita[1] > (float)limiarDireita2 * (float) 1.5) {
    retorno = true;  
    //Serial.print("Preto Direita\n"); 
  }
 // else
    //Serial.print("Branco Direita\n");
    
 // delay(1000);

  return retorno;
}

boolean testaLuzFrente() {

  boolean retorno = false;
  sensorLuzFrente.read(readLuzFrente); // atualiza a leitura dos sensores de cor

//  Serial.println(readLuzFrente[0]); 
//  Serial.println(readLuzFrente[1]); 

  if(readLuzFrente[0] > (float)limiarFrente1* (float) 1.5 || readLuzFrente[1] > (float)limiarFrente2 * (float)1.5) {
    retorno = true;  
   // Serial.print("Preto Frente\n"); 
  }
 // else
   // Serial.print("Branco Frente\n");
    
  //delay(1000);

  return retorno;
}

int testaSomDireito() {

  boolean retorno = false;
  int dist = sensorSomDireita.Ranging(CM);/* Valor analogico do pino do sensor*/;

  if(dist <= 100) {
    retorno = true;
   // Serial.print("achei Direito\n");
  }  
 // else
   // Serial.print("Nao Direito\n");
    
  //delay(1000);

  return retorno;
}

int testaSomFrente() {

  boolean retorno = false;
  int dist = sensorSomFrente.Ranging(CM);/* Valor analogico do pino do sensor*/;

  if(dist <= 10) {
    retorno = true;
   // Serial.println("achei Frente\n" + dist);
  }  
  //else
   // Serial.print("Nao Frente\n");
    
  //delay(1000);

  return retorno;
}




void setup() {
  
  
  Serial.begin(9600);
  
  // put your setup code here, to run once:  
  pinMode(MOTOR_D_F, OUTPUT);
  pinMode(MOTOR_D_T, OUTPUT);
  pinMode(MOTOR_E_F, OUTPUT);
  pinMode(MOTOR_E_T, OUTPUT);
  
  pinMode(LUZ_DIREITA_1, INPUT);   
  pinMode(LUZ_DIREITA_2, INPUT);    
  pinMode(LUZ_ESQUERDA_1, INPUT);
  pinMode(LUZ_ESQUERDA_2, INPUT);
  
  pinMode(LUZ_FRENTE_1, INPUT);
  pinMode(LUZ_FRENTE_2, INPUT);
  
  pinMode(SOM_FRENTE_ECHO, INPUT);
  pinMode(SOM_FRENTE_TRIG, OUTPUT);
  pinMode(SOM_DIREITA_ECHO, INPUT);
  pinMode(SOM_DIREITA_TRIG, OUTPUT);
  
  sensorLuzEsquerda.read(readLuzEsquerda);
  limiarEsquerda1 = readLuzEsquerda[0];
  limiarEsquerda2 = readLuzEsquerda[1];
  
  sensorLuzFrente.read(readLuzFrente);
  limiarFrente1 = readLuzFrente[0];
  limiarFrente2 = readLuzFrente[1];
  
  sensorLuzDireita.read(readLuzDireita);
  limiarDireita1 = readLuzDireita[0];
  limiarDireita2 = readLuzDireita[1];
}

void loop() {

  
  //delay(1000);
     
  /* Testa os sensores de luz pra detectar o chão */
  luzEsquerdo = testaLuzEsquerdo(); 
  luzDireito = testaLuzDireito();
  luzFrente = testaLuzFrente();

 /* Se for detectada alguma luz - MODULO DE FUGA*/
  if(luzEsquerdo || luzDireito || luzFrente) {
    if(luzEsquerdo && !luzDireito)
      fugaEsquerda();
    else if(!luzEsquerdo && luzDireito)
      fugaDireita();
    else if(luzDireito && luzEsquerdo)
      avanca();
    else if(luzFrente)
      volta();
  }
  else { //caso nao detecte nenhuma luz
    /* Procura o inimigo */
    somFrente = testaSomFrente();
    if(somFrente) 
      avanca();
    else {
  
     somDireito = testaSomDireito();
  
     
     if(somDireito) // Talvez colocar um while aqui dentro até quando encontrar o inimigo no sensor da frente 
       giraHorario();
     else // Talvez colocar while ate encontrar algo no sensor da frente ou no sensor lateral
       giraAntiHorario();
      
    }
  }
  
  delay(10);


  

}
