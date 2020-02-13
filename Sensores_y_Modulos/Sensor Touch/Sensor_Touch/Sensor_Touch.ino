
#define PINSENSOR 12

int F_Estado(int pin){
  return digitalRead(pin);
}

void F_Comunicaicon (int Estado){
  if (Estado){
    Serial.print("Deteccion");
  }
  else
  {
  Serial.print("NO DETECCION");
  }
Serial.println();
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(PINSENSOR, INPUT);
}

void loop()
{

  
  int estadoSensor = F_Estado(PINSENSOR);
  F_Comunicaicon(estadoSensor);
  delay(500);
}
