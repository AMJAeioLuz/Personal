#include <ESP8266WiFi.h>
void setup() {
  Serial.begin(9600); 
}

void loop() {
  char* variable = "este es el contenido de la variable";
  if (strstr(variable, "contenido")) {
    Serial.print("se ha detectado la palabra contenido");
  } 
}




