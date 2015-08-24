// Programa utilizado para testar os sensores de luz
// Data da última modificação: 14/08/2015

#include <QTRSensors.h>


   QTRSensorsRC esquerda((unsigned char[]) {14,15}, 2);
   QTRSensorsRC direita((unsigned char[]) {16,17}, 2);
   QTRSensorsRC frente((unsigned char[]) {18,19}, 2);

   void setup()
   {
     Serial.begin(9600);
   }

   void loop()
   {
     unsigned int readings[2];
     esquerda.read(readings);
     Serial.print ("ESQUERDA sensor1  ");
     Serial.println(readings[0]);
    // delay(500);
     Serial.print (" ESQUERDA sensor2  ");
     Serial.println(readings[1]);
    delay(500);
    
    direita.read(readings);
    Serial.print ("DIREITA sensor1  ");
     Serial.println(readings[0]);
    // delay(500);
     Serial.print (" DIREITA sensor2  ");
     Serial.println(readings[1]);
      delay(500);

      /*
     frente.read(readings);
     Serial.print ("FRENTE sensor1  ");
     Serial.println(readings[0]);
    // delay(500);
    
     Serial.print (" FRENTE sensor2  ");
     Serial.println(readings[1]);
     //Serial.print (" sensor3  ");
     //Serial.print(readings[2]);
    // delay(500);
    */
     //Serial.print (" sensor4  ");
     //Serial.println(readings[3]);
     delay(1500);
     /*Serial.print ("sensor5  ");
     Serial.println(readings[4]);
     delay(1000);
     Serial.print ("sensor6  ");
     Serial.println(readings[5]);
     delay(1000);
     Serial.print ("sensor7  ");
     Serial.println(readings[6]);
     delay(1000);
     Serial.print ("sensor8  ");
     Serial.println(readings[7]);
     delay(1000);*/
   }
