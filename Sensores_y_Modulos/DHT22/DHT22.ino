#include <Wire.h>
#include <ESP8266WiFi.h>                                                  //Librería necesaria para usar ESP con IDE Arduino.

#include "DHTesp.h"   

 
DHTesp dht;                                                               //Iniciamos el sensor DHT

int dhtPin = D6;  
 
void setup() {
  
   Serial.begin(115200);
   Serial.println("DHTxx test!");
dht.setup(dhtPin, DHTesp::DHT22);

}
 
void loop() {
  delay(dht.getMinimumSamplingPeriod());

  float Humedad = dht.getHumidity();
  float Temperatura = dht.getTemperature();
 
   Serial.print("Humidity: ");
   Serial.print(Humedad);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.print(Temperatura);
   Serial.println(" *C ");
}
