

#include <SoftwareSerial.h>
#include <Nextion.h>

#define RxD 10
#define TxD 11
#define nextion Serial2
SoftwareSerial nextion(RxD, TxD);
Nextion myNextion(nextion, 9600);

const int potenciometro = A0;
const int ledSatatus = 13;
float lecturaPotenciometro;
int leerPosPotenciometro;


void setup() {
  Serial.begin(9600);
  myNextion.init();
  delay(5000);
  myNextion.sendCommand("page 2");

}

void loop() {
  leerPosPotenciometro = analogRead(potenciometro);
  lecturaPotenciometro = leerPosPotenciometro * 5.00/1024.00;
  

}

void imprimeNextionGrados() {

  int lecturaAnalogicaNextion=map(leerPosPotenciometro,0,1024,0,270);
  String datoLecturaString = String(lecturaPotenciometro);

  if (lecturaAnalogicaNextion < 45){
    lecturaAnalogicaNextion+=325;
  }
  else{
    lecturaAnalogicaNextion -= 46;
  }
  if ((lecturaAnalogicaNextion < 215) && (lecturaAnalogicaNextion < 325)) lecturaAnalogicaNextion=215;
  myNextion.setComponentValue("page2.z0",lecturaAnalogicaNextion);
  myNextion.setComponentText("page2.t0",datoLecturaString);

  Serial.println (lecturaAnalogicaNextion);
}

