// Programa utilizado para testar os sensores de luz, já utilizando funções de calibração
// Data da última modificação: 09/10/2015

#include <QTRSensors.h>
int limiar;

QTRSensorsRC esquerda((unsigned char[]) {14,15}, 2);

void setup(){
  Serial.begin(9600);
  int min, max, times;
  times = 150; //numero de vezes que chamara a funcao de calibracao
  Serial.println("Calibrando:");
  for (int i = 0; i < times; i++){
    if(i%7 == 0){
      Serial.print("(");
      Serial.print((int) (i*100)/times);
      Serial.println(" %)");
    }
    esquerda.calibrate();
    delay(20); //intervalo de tempo entre calibracoes
  }
  Serial.println("(100 %)");
  
  max = *esquerda.calibratedMaximumOn; //guardando valores maximo
  min = *esquerda.calibratedMinimumOn; //e minimo das leituras
  
  Serial.println("Máximo: ");
  Serial.println(max);
  Serial.println("Mínimo: ");
  Serial.println(min);
  
  int dif = max - min;
  limiar = dif * 0.5 + min; //definicao do limiar entre preto e branco
}
void loop(){
  unsigned int readings[2];
  esquerda.read(readings);
  
  Serial.print ("Sensor 1: ");
  if(readings[0] >= limiar){
    Serial.print("PRETO (");
  }
  else{
    Serial.print("BRANCO (");
  }
  Serial.print(readings[0]);
  Serial.println(")");  
  
  Serial.print ("Sensor 2: ");
  if(readings[1] >= limiar){
    Serial.print("PRETO (");
  }
  else{
    Serial.print("BRANCO ("); 
  }
  Serial.print(readings[1]);
  Serial.println(")"); 
  
  Serial.println();
 
  delay(500);
}
