// Programa utilizado para testar os sensores de luz, já utilizando funções de calibração
// Data da última modificação: 09/10/2015

#include <QTRSensors.h>
int limiar;

QTRSensorsRC esquerda((unsigned char[]) {14,15}, 2);

//QTRSensorsRC direita((unsigned char[]) {16,17}, 2);
//QTRSensorsRC frente((unsigned char[]) {18,19}, 2);

void setup(){
  Serial.begin(9600);
  int min, max, times;
  times = 150;
  Serial.println("Calibrando:");
  for (int i = 0; i < times; i++){
    if(i%7 == 0){
      Serial.print("(");
      Serial.print((int) (i*100)/times);
      Serial.println(" %)");
    }
    esquerda.calibrate();
    delay(20);
  }
  Serial.print("(100 %)");
  Serial.println();
  max = *esquerda.calibratedMaximumOn;
  min = *esquerda.calibratedMinimumOn;
  Serial.println("maximo: ");
  Serial.println(max);
  //Serial.println(*esquerda.calibratedMaximumOff);


  Serial.println("minimo: ");
  Serial.println(min);
  //Serial.println(*esquerda.calibratedMinimumOff);
  
  int dif = max - min;
  limiar = dif * 0.5 + min;
}
void loop(){
  unsigned int readings[2];
  esquerda.read(readings);
  //esquerda.emittersOn();
  Serial.print ("sensor1  ");
  if(readings[0] >= limiar)
    Serial.print("PRETO (");
  else 
    Serial.print("BRANCO (");
  Serial.print(readings[0]);
  Serial.println(")");  
  
  Serial.print ("sensor2  ");
  if(readings[1] >= limiar)
    Serial.print("PRETO (");
  else 
    Serial.print("BRANCO ("); 
  Serial.print(readings[1]);
  Serial.println(")"); 
  
  Serial.println();
 
  delay(500);
}
