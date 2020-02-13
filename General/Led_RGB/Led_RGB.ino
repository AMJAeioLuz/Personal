/* Control Básico De Un LED RGB De Ánodo Común */
/* www.educachip.com */

//Se definen las variables que se van a utilizar para establecer los
//colores. Éstas deben estar asociadas a pines digitales PWM e irán
//unidas a los cátodos de cada uno de los colores.
int Rojo = 2;
int Azul = 3;

void setup() {

  Serial.begin(115200);
  Serial.println("");
  Serial.println("SSSSSSSSSSSSSSSSSSSSS");
  //Se establecen los pines definidos como salidas para poder
  //la diferencia de voltaje con respecto a la alimentación común.
  pinMode(Rojo, OUTPUT);

  pinMode(Azul, OUTPUT);

}

//Se crea un módulo auxiliar que facilitará la tarea de establecer
//los voltajes asociados a cada color.
//El valor de las variables R, G y B debe ser un entero entre 0 y 255
//siendo 255 el valor relativo a la máxima luminosidad de cada color.
//Debe tenerse en cuenta que hasta que no se supere el voltaje umbral
//de cada color este no se presentará en el LED RGB.
void EstablecerColor(int R, int G, int B) {

  //Se utiliza la expresión 255-X para “naturalizar los valores”. Dado
  //que el mayor brillo está asociado a la mayor diferencia de voltaje
  //entre la alimentación y las salidas PWM (lo que implica una salida
  //de 0V por el pin PWM, esto es, analogWrite(X, 0);).
  analogWrite(Rojo, 255 - R);

  analogWrite(Azul, 255 - B);

}

void loop() {

  //Se representan colores pseudoaleatorios en el LED RGB mediante el
  //uso de la instrución random(min,max);.
  //EstablecerColor(random(127, 255), random(127, 255), random(127, 255));

  analogWrite(Rojo, 255);

  analogWrite(Azul, 100);  

  //Se utiliza un delay para que de tiempo algo observador a apreciar
  //los colores.
  delay(1000);

}
