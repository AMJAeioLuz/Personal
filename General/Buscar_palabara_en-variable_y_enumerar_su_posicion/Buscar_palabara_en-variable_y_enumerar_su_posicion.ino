#include <ESP8266WiFi.h>
void setup() {
  Serial.begin(9600); 
}

void loop() {
String variable = "este es el contenido de la variable";
int pos=variable.indexOf("la");
if (pos>=0) {
Serial.println("se ha detectado la palabra contenido en la posicion ");
Serial.println(pos);
} 
delay(2000);
variable = "";
}




