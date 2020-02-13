

#include <SoftwareSerial.h>
#include <Nextion.h>

#define RxD 10
#define TxD 11

SoftwareSerial nextion(RxD, TxD);
Nextion myNextion(nextion, 9600);

const int potenciometro = A5;
const int ledStatus = 13;
float lecturaPotenciometro;
int leerPosPotenciometro;


void setup() {
  Serial.begin(9600);
  myNextion.init();
  delay(5000);
    pinMode(ledStatus, OUTPUT);
digitalWrite(ledStatus, LOW);
  myNextion.sendCommand("page 1");   

}

void loop() {
  leerPosPotenciometro = analogRead(A5);
  lecturaPotenciometro = leerPosPotenciometro * 5.00/1024.00;
  Serial.println (leerPosPotenciometro);



  int lecturaAnalogicaNextion=map(leerPosPotenciometro,0,1024,0,290);
  String datoLecturaString = String(lecturaPotenciometro);

  if (lecturaAnalogicaNextion < 65){
    lecturaAnalogicaNextion+=315;
  }
  else{
    lecturaAnalogicaNextion -= 65;
  }

  myNextion.setComponentValue("page2.z0",lecturaAnalogicaNextion);
  myNextion.setComponentText("page2.t0",datoLecturaString);


boolean IndicadorUnionBat=myNextion.getComponentValue("page2.bt1");
  if (IndicadorUnionBat == true ) digitalWrite(ledStatus, HIGH); else digitalWrite(ledStatus, LOW);
  
}

