#include <Nextion.h>

#define nextion Serial1
Nextion myNextion(nextion, 9600);
int ledStatus = 13;



void setup() {
      Serial.begin(9600); 
 myNextion.init();
  delay(5000);
  myNextion.sendCommand("page 0");
  pinMode(ledStatus, OUTPUT);
digitalWrite(ledStatus, LOW);
myNextion.setComponentText("page0.t0" , "13:56 h");
  
}

void loop() {
boolean botonpantalla=myNextion.getComponentValue("page0.bt0");
  if (botonpantalla == true ) digitalWrite(ledStatus, HIGH); else digitalWrite(ledStatus, LOW);
  

 Serial.print (botonpantalla);
  
}
