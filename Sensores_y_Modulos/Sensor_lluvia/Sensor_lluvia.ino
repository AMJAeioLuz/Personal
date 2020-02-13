const int Sensorlluvia = 10;

int InSensorLluvia = A3;
 
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(InSensorLluvia, INPUT);  //definir pin como entrada
}
 
void loop(){
  int value = 0;
  value = digitalRead(Sensorlluvia );  //lectura digital de pin
 
  if (value == LOW) {
      Serial.println("Detectada lluvia");
  }
  delay(1000);
}
