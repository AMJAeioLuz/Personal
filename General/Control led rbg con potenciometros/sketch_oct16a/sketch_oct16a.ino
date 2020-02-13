/*
--------------------------------------------- 
  LED RGB + Potenciómetro
 ---------------------------------------------
 
  Programa que varia el color del LED según
  el valor obtenido por unos potenciómetros.
 
*/
 
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int ledRojo = 41; //Declara Pin LED Rojo
int ledVerde = 39; //Declara Pin LED Verde
int ledAzul = 37;  //Declara Pin LED Azul
 
int pinPot0 = A4;  //Declara Pin Potenciometro Rojo
int pinPot2 = A5;  //Declara Pin Potenciometro Azul
int pinPot5 = A9;  //Declara Pin Potenciometro Verde
 
int valorsensor0 = 0;  //Valores analogicos de la salida del potenciometro
int valorsensor2 = 0;  //   ||        ||            ||            ||
int valorsensor5 = 0;  //   ||        ||            ||            ||
 
float divisionR; 
float divisionV;
float divisionA;
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{ 
  pinMode(ledRojo,OUTPUT);  //El LED Rojo como una salida
  pinMode(ledVerde,OUTPUT); //El LED Verde como una salida
  pinMode(ledAzul,OUTPUT);  //El LED Azul como una salida
  pinMode(pinPot2,INPUT);
  Serial.begin(9600);
 
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() {
 
   // Llamada a la función Color que recibe
   // 1er posicion: Intensidad Rojo
   // 2da posición: Intensidad Verde
   // 3ra posición: Intensidad Azul
 
   float Constante = (float) 255 / 1023;  //Divide el máximo valor de color entre el máximo valor del potenciómetro
 
   valorsensor0 = analogRead(pinPot0);
   valorsensor2 = analogRead(pinPot2);
   valorsensor5 = analogRead(pinPot5);
 
   divisionR = Constante * valorsensor0;    
   divisionV = Constante * valorsensor5;
   divisionA = Constante * valorsensor2;
 
color(divisionR,divisionV,divisionA);     // Carga un valor para (ROJO,VERDE,AZUL)
                                             //segun el valor de tres potenciómetros.


/* Serial.print("Potencimoetro1 ");                                          //Imprime Texto Bateria principal: por Serial
  Serial.print(pinPot0);                                                  //Imprime el valor de floatvoltios1 por Serial
  Serial.println(" ");                                                         //Imprime Texto V por Serial
  delay(500);
  Serial.print("Potencimoetro2 ");                                          //Imprime Texto Bateria principal: por Serial
  Serial.print(pinPot2);                                                  //Imprime el valor de floatvoltios1 por Serial
  Serial.println(" ");                                                         //Imprime Texto V por Serial
  delay(500);
  Serial.print("Potencimoetro3 ");                                          //Imprime Texto Bateria principal: por Serial
  Serial.print(pinPot5);                                                  //Imprime el valor de floatvoltios1 por Serial
  Serial.println(" ");                                                         //Imprime Texto V por Serial
  delay(500);
}*/
 
//------------------------------------
//Funcion color
//------------------------------------
 
void color(int rojo, int verde, int azul){
 
    //ROJO. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledRojo, 255-rojo);
 
    //VERDE. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledVerde, 255-verde);
 
    //AZUL. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledAzul, 255-azul);
}
