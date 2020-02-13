#include <ESP8266WiFi.h>
#include "FS.h"
#include "DHTesp.h"

DHTesp dht;

int dhtPin = 14;

const char* ssid     = "Home Red";
const char* password = "@@rontr@b@j@+e_e_g_";

const char* host = "www.aeioluz.com";

byte NombreBD;
int analog_pin = 0;
float Temperatura;

void setup () {

  Serial.begin(9600);
   SPIFFS.begin();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(5000);
}

void loop() {

  float Humedad = dht.getHumidity();
  float Temperatura = dht.getTemperature();
  float STermica = dht.computeHeatIndex(Temperatura, Humedad);

Serial.print("connecting to ");
Serial.println(host);

// Use WiFiClient class to create TCP connections
WiFiClient client;
const int httpPort = 80;
if (!client.connect(host, httpPort)) {
  Serial.println("connection failed");
  return;
}

  // We now create a URL for the request
  String url = "/medidor/listartablas.php?";
  String key = "pass=1234";
  String dato1 = "Temperatura=";
  String dato2 = "Temperatura";

  Serial.print("Requesting URL: ");
  Serial.println(url);


  client.print(String("GET ") + url + key + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

    while (client.available()) {
    String listabasesdatos = client.readStringUntil('\r');
    Serial.print(listabasesdatos);

    delay(1000);

    if (client.readStringUntil('\r') == ("perro"))
    {
  Serial.println("Tabla BD encontrada");
  delay(1000);
  
    }
  else{
  Serial.println("Tabla BD no encontrada");
  }
delay(3000);
    
    }

}
