/*Presionamos un Botón para encender el LED,
  lo volvemos a presionar para apagarlo */

int estadobotonluces = 0;        //Guarda el estado del Botón
int estadoAnteriorbotonluces = 0; //Garda estado anterior del botón
int salidabotonluces = 0;        //0 = LED apagado, 1 = LED encendido

void setup() {

  pinMode(32, INPUT);    //Declaramos el botón como entrada
  pinMode(11, OUTPUT);   //Declaramos el LED como salida
Serial.begin(9600);                                                       //iniciar puerto serie

}

void loop() {


Serial.println(estadobotonluces);                                   //Imprimimos por serial Detectada lluvia
      delay(200);

  estadobotonluces = digitalRead(32);    //Leer el estado del botón

  if((estadobotonluces == HIGH) && (estadoAnteriorbotonluces == LOW)){
    salidabotonluces = 1 - salidabotonluces;
    delay(20);
  }
    estadoAnteriorbotonluces = estadobotonluces;

  if (salidabotonluces == 1) {          //Si el estado esta en HIGH
    digitalWrite(11, HIGH);    //encendemos el LED
  }
  else {                      //apagamos el LED
    digitalWrite(11, LOW);
  }

}
