// Código utilizado na competição de 2015
// Data da última mofificação: 15/08

#define MOTOR_E_F 3
#define MOTOR_E_T 2
#define MOTOR_D_F 4
#define MOTOR_D_T 5


void volta() {

   /* Motor esquerdo pra tras */
  digitalWrite(MOTOR_E_F, LOW);
  digitalWrite(MOTOR_E_T, HIGH);

  /* Motor direito tras */
  digitalWrite(MOTOR_D_F, LOW);
  digitalWrite(MOTOR_D_T, HIGH);  

}

void setup() {
  // put your setup code here, to run once:
  
  pinMode(MOTOR_D_F, OUTPUT);
  pinMode(MOTOR_D_T, OUTPUT);
  pinMode(MOTOR_E_F, OUTPUT);
  pinMode(MOTOR_E_T, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  volta();
}
