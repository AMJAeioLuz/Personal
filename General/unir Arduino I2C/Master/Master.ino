/*
  Programarfacil https://programarfacil.com
  Autor: Luis del Valle @ldelvalleh
  ComunicaciÃ³n I2C entre dos Arduinos, maestro
*/

#include <Wire.h>

void setup() {

  // Unimos este dispositivo al bus I2C
  Wire.begin();
    Serial.begin(9600);
}

byte pin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
byte estado = 0;

void loop() {
  for (int i = 0; i < 12; i++)
  {
    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(1);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(pin[i]);
    Serial.println(pin[i]);

    // Enviamos un byte, L pondrÃ¡ en estado bajo y H en estado alto
    Wire.write(estado);
    Serial.println(estado);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(500);
  }

  // Cambiamos el estado
  if (estado == 0)
  {
    estado = 1;
  }
  else
  {
    estado = 0;
  }
}
