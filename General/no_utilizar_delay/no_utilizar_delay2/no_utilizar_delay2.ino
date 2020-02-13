int ledPin = 8;
boolean flag = true;
long previousMillis = 0;
long On = 50;             // tiempo que dura encendido, en milisegundos
long Off = 1000;          // tiempo que dura apagado, en milisegundos

void setup(){
 pinMode(ledPin, OUTPUT);
}


void loop(){  
 
 // aquí es donde puede colocarse otro código que necesita ser ejecutado continuamente

 if (millis() < (previousMillis + On + Off)){
   flag = true; 
 }
 else {
  flag = false; 
  previousMillis = millis();
 }
 if (flag == true){
  if (millis() > (previousMillis + On)){
  digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, HIGH); 
  }
 }
}
