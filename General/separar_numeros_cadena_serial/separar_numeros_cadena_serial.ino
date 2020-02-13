
/*---------------------------------------------------
   Monitor serial
   --------------------------------------------------
   Consiste en encender un led que està conectado al pin 9, con la intensidad
   y el tiempo que me llegaran por el monitor serial de la sig. forma:
   "brillo,duracion"
   Utilizo de la funcion Serial.parseInt()
*/

//-----------------------------------------------------
//Declarar puertos de entrada y salida, variables, etc.
//-----------------------------------------------------

int led = 9;          //declaro que el led estarà conectado al pin 9


//------------------------------------
//Funciòn principal o de configuraciòn
//------------------------------------

void setup()
{
  Serial.begin (9600);        //inicializo la comunicaciòn serial a 9600 baudios
  pinMode (led, OUTPUT);      //inicializo el pin led=13 como salida
  Serial.println("Hola!: Escribe los valores de 'brillo y duracion' separados por una coma");
}

//--------------------
//Funciòn cìclica
//--------------------

void loop()
{
  if (Serial.available())            // si hay algun dato en el monitor serial
  {
    int brillo = Serial.parseInt();  // guardo en "brillo" el primer valor (intensidad 0-255)
    int duracion = Serial.parseInt();// guardo en "duraciòn" el segundo valor (tiempo en mSeg)
    analogWrite(led, brillo);        // ahora enciendo el led con intensidad = brillo
    delay(duracion);                 // por un tiempo = duraciòn
    analogWrite(led, 0);             // y apago
  }
}

// Fin del programa
