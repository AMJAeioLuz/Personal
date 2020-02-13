#include <ESP8266WiFi.h>
#include "FS.h" 


//Declaracion de variables
char inChar;
String string="";

//Configuracion de puerto serial y reservacion de variable string
void setup() {
  Serial.begin(115200);
  Serial.println("");
  string.reserve(200);
  SPIFFS.begin();  

  int linea;
}

void loop(){




  
  if (Serial.available()){
//Lectura de caracteres   
   inChar = Serial.read();
//Suma de caracteres en variable string
   string+=inChar;
   
//Imprime la variable con los caracteres acumulados hasta la ","   
   if (inChar==','){
    Serial.print("Lectura: ");
    Serial.println(string);
//Borra la variable string para almacenar nuevos datos
    string=""; 
   }
  }

  
}
