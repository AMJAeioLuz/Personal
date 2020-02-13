//Monitorización PE aeioLuz

//Medidor de Consumo eléctrico, temperatura y humedad para automatización de seguimiento en PE

//Periféficos:

//Medir caudal de agua.
//Envío datos por SMS con GPRS.
//Sistema de detección inyección a red.

//Ya completado:

//Sistema de división de tensión necesario para poder leer con los puertos anológicos de Arduino.
//Sistema para pasar la señal alterna de la pinza amperimétrica a contínua para poder leerla.
//Código para la interpretación de las lecturas de corriente + calibración.
//Integración + Código del sensor DHT22 Temperatura y Humedad.
//Integración + Código de bluetooth HC-06


//Falta aún por realizar:

//Sistema mediante código para tener una media de lecturas más estable en todas las mediciones.
//Sistema mediante código para descartar los primeros 30s (o lo que sea necesario) para no registrar las priemras lecturas.
//Definir alimentación para sensores 5V y 3.3V.
//Desarrollo de la APP con APP Inventor 2 (Es la mejor de las que he probado, pero puede ser otra) + Implantación en código.
//Integración + código del sistema WIFI, conectar a red, envío de datos a un servidor...
//Integración + código des sistema GPRS + envío de SMS + recepción de la información.
//Integración + código del reloj + menú en app para poder ponerlo en hora (esto no se si es posible realizar).
//Integración + código de botón reset.
//Sistema para almacenar la información obtenida para su análisis.
//Envío de datos desde el Wifi del móvil del usuario (no se si es posible).
//Diseño de PCB.
//Diseño carcasa.

/*ESQUEMA DE CONEXION
                                     +-----+
        +----[PWR]-------------------| USB |--+
        |                            +-----+  |
        |         GND/RST2  [ ][ ]            |
        |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |
        |          5V/MISO2 [ ][ ]  A4/SDA[ ] |
        |                             AREF[ ] |
        |                              GND[ ] |
        | [ ]N/C                    SCK/13[ ] |
        | [ ]IOREF                 MISO/12[ ] |
        | [ ]RST                   MOSI/11[ ]~|
        | [ ]3V3    +---+               10[ ]~|
        | [ ]5v    -| A |-               9[ ]~|
        | [ ]GND   -| R |-               8[ ] |
        | [ ]GND   -| D |-                    |
        | [ ]Vin   -| U |-               7[ ] |
        |          -| I |-               6[ ]~|
        | [ ]A0    -| N |-               5[ ]~|
        | [ ]A1    -| O |-               4[ ] |
        | [ ]A2     +---+           INT1/3[ ]~|
        | [ ]A3                     INT0/2[ ] |
        | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |
        | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |
        |            [ ] [ ] [ ]              |
        |  UNO_R3    GND MOSI 5V  ____________/
         \_______________________/

*/
#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

const int DHTPin = 5;     // what digital pin we're connected to
DHT dht(DHTPin, DHTTYPE);

// Include Emon Library
#include "EmonLib.h"
// Crear una instancia EnergyMonitor
EnergyMonitor energyMonitor;
// Voltaje de nuestra red eléctrica
float voltajeRed = 235.0;
void setup()
{
  dht.begin();
  Serial.begin(9600);
  // Iniciamos la clase indicando
  // Número de pin: donde tenemos conectado el SCT-013
  // Valor de calibración: valor obtenido de la calibración teórica
  energyMonitor.current(5, 13.24);

  delay(200);
  Serial.println("Cargando...");
  delay(500);
  Serial.println("Carga completada");
  delay(200);
  Serial.println("Medidor de consumo aeioLuz 0.5");  
  delay(500);
  Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"); 

  pinMode(13, OUTPUT); //Establecer el pin 13 como salida  

}

void printMeasure(String prefix, float value, String postfix)
{
   Serial.print(prefix);
   Serial.print(value, 3);
   Serial.println(postfix);

}

void loop()
{
// Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();
   float t = dht.readTemperature();
 
   /*if (isnan(h) || isnan(t)) {
      Serial.println("Fallo sensor Temp/Humed.");
      return;
   }*/




  
  // Obtenemos el valor de la corriente eficaz
  // Pasamos el número de muestras que queremos tomar
  double Irms = energyMonitor.calcIrms(14840000);
  Irms = Irms - 0.038;
  // Calculamos la potencia aparente
  double potencia =  Irms * voltajeRed;
  // Mostramos la información por el monitor serie
  Serial.print("Potencia = ");
  Serial.print(potencia);
  Serial.print("    Irms = ");
  Serial.println(Irms);
  Serial.println(t);





  if(Serial.available()>=1)
   {
      char entrada = Serial.read(); //Leer un caracter
 
      if(entrada == 'h' or entrada == 'H') //Si es 'H', encender el LED
      {
         digitalWrite(13, HIGH);
         Serial.println("LED encendido");
      }
 
      else if(entrada == 'l' or entrada == 'L') //Si es 'L', apagar el LED
      {
         digitalWrite(13, LOW);
         Serial.println("LED apagado");
      }
 
      else if(entrada == 'i' or entrada == 'I') //Si es 'I', mostrar un mensaje de ayuda
      {
         Serial.println("Comandos:n (i) - abrir esta listan (h)- encender ledn (l) - apagar ledn");
      }
   }
}
