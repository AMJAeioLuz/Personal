
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

char auth[] = "6b7daecf30e24b7d87cb1cc65a944087";

char ssid[] = "Home Red";
char pass[] = "@@rontr@b@j@+e_e_g_";

#define DHTPIN 14          // Definimos el pin al que conectaremos el DHT

// definimos que tipo de DHT estamos usando
//#define DHTTYPE DHT11     // DHT 11
#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

void setup()
{
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Configuramos el timer para que se ejecute cada 2 segundos
  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run(); // Iniciamos Blynk
  timer.run(); // Iniciamos SimpleTimer
}

// Esta es la función que enviará los datos a blynk
// en blynk, el tiempo de lectura debe estar definido en PUSH
// ocea, cada vez que la NodeMCU envie datos se nos refresca la pantalla
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // o dht.readTemperature(true) para mostrar la Tº en Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer datos del sensor");
    return;
  }
  // Puedes enviar cualquier datos en cualquier momento
  // pero no envíen más de 10 datos por segundo, sino su app no funcionará.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}
