// Programa utilizado para testar a ponte H
// Data da última modificação: 15/08/2015

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, HIGH);  
  delay(2000);              // wait for a second
  digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, HIGH);  
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, HIGH);    // turn the LED off by making the voltage LOW
  delay(2000);              // wait for a second
}
