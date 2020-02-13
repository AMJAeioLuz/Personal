//Una clase no es necesariamente una funcion que se ejecute en cuanto se topa en el
//codigo, de hecho no se puede utilizar de manera directa 
//se tienen que usar "clones" para poder acceder a las variables

//Para este ejemplo no requieres nada mas que tu Altair
class Flasher
{
  //Dentro de una clase van variables y funciones. Asi como un constructor y un destructor
  //En una clase no se pueden inicializar las variables de manera directa, solo se les da nombre y tipo
  //Es ahi donde entra el constructor. Mas adelante veras como funciona.
  int ledPin; // el numero del PIN que se usara
  long OnTime; // milisegundos del tiempo encendido
  long OffTime; // millisegundos del tiempo apagado
  
  int ledState; //Se usara para escribir con digitalWrite en ledPin
  unsigned long previousMillis; // Variable que registra en que ms fue la ultima vez que hubo un cambio
  
  
  public: //public, private y protected, eso es parte de la estructura de una clase. Te lo dejo de tarea.
    Flasher(int pin, long on, long off) //Esto es un constructor (es lo que define la plantilla que se usara 
    //a la hora de "clonar" la clase para poder emplearla). Tambien nos dice que va a necesitar 3 parametros cuando se usen sus "clones".
    {
      ledPin = pin; //Y aqui es donde podemos inicilizar los valores predeterminados que tendran los clones de la clase
      pinMode(ledPin, OUTPUT);
      OnTime = on;
      OffTime = off;
      ledState = LOW;
      previousMillis = 0;
    }
    
    void Update() //Sin problemas, dentro de la clase se puede crear una funcion
    {
      // Checa si ya es momento de cambiar el estado del led
      unsigned long currentMillis = millis();
      if((ledState == LOW) && (currentMillis - previousMillis >= OnTime)) //Si el led esta encendido y han pasado N milisegundos desde la ultima vez que se encendio, entonces
      {
        ledState = HIGH; // .. entonces cambia la variable
        previousMillis = currentMillis; // "La ultima vez que se hizo el cambio fue AHORA!"
        digitalWrite(ledPin, ledState); // Actualiza el estado del LED respecto a LEDSTATE
      }
      else if ((ledState == HIGH) && (currentMillis - previousMillis >= OffTime)) //Si el led esta apagado y han pasado N milisegundos desde la ultima vez que se apago, entonces
      {
      ledState = LOW;  // .. entonces cambia la variable
      previousMillis = currentMillis; // "La ultima vez que se hizo el cambio fue AHORA!"
      digitalWrite(ledPin, ledState); // Actualiza el estado del LED respecto a LEDSTATE
      }
    }
};
//Ok ya tienes toda tu clase bien hecha y lista para comenzar a clonar, no olvides que segun la tecleaste, deberas darle 3 parametros.

//Esta es la forma en que luce un clon de la clase, es tal como creas una variable, salvo que esta es de tipo *nombre_de_clase*

Flasher led1(2, 100, 5000); // Led 1 es un Flasher; usara el pin 14, estara prendido 100 ms y apagado por 400 ms (LED VERDE)
Flasher led2(4, 400, 350); // Led 2 es un Flasher; usara el pin 15, estara prendido 350 ms y apagado por 350 ms (LED AZUL)
Flasher led3(7000, 25, 25); // Led 2 es un Flasher; usara el pin 15, estara prendido 350 ms y apagado por 350 ms (LED AZUL)



void setup()
{
 //Woah, te preguntabas donde estaba la funcion setup. Aunque este vacia, es necesaria para poder compilar y ejecutar el codigo, asi que deberas teclearla de igual forma. 
}
void loop() //Ahora, el codigo que se ejecuta infinitas veces..
{
  led1.Update(); //Recuerdas que creaste un clon de la clase flasher? Bueno, ahora tienes acceso a las variables de la clase flasher que se llama led1
  led2.Update(); //La nomeclatura de esto es parte de las clases de POO, revisa en internet como funciona esto
  led3.Update();
}
