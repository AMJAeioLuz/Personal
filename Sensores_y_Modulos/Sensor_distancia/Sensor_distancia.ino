/*Practica 8 - Uso del Sensor ultrasonico*/
// Se importa la libreria NewPing
#include <NewPing.h>

const int trig = 4;    //Pin trig en pin 4
const int echo = 3;    //Pin Echo en pin 3
const int zumbador = 5;  //zumbador en pin 5
const int led = 8;      //LED en pin 8

int distancia;  //Guardamos la distancia que detecte el sensor
int pausa;      //Guarda el tiempo de espera entre parpadeo

// Se crea un objeto con la libreria NewPing llamado sonar
NewPing sonar(trig, echo, 200); // Each sensor's trigger pin, echo pin, and max distance to ping.

void setup(){
  pinMode(zumbador,OUTPUT); //Declaramos el zumbador como salida
  pinMode(led, OUTPUT);   //Declaramos el LED como salida
}

void loop(){

  // en la variable distancia guardamos la distancia en centimetros que detecta el sonar respecto al objetivo
  distancia = sonar.ping_cm(); 

  if (distancia < 100){ //restringir el alcance a 1m (100cm)
    pausa = distancia * 10; //guardamos el tiempo de pausa
    digitalWrite(zumbador, HIGH); //encendemos el zumbador
    digitalWrite(led,HIGH); //Encendemos el LED
    delay(pausa); //Agregamos un delay que sea igual al tiempo de pausa
  }
  
else{ //restringir el alcance a 1m (100cm)
    
    digitalWrite(zumbador, LOW); //encendemos el zumbador
    digitalWrite(led,LOW); //Encendemos el LED
    delay(pausa); //Agregamos un delay que sea igual al tiempo de pausa
}

  digitalWrite(zumbador, LOW); //apagamos el zumbador
  digitalWrite(led, LOW);   //apagamos el LED
  delay(pausa);  // esperamos el tiempo de pausa
}
