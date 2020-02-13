#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

const int DHTPin = 5;     // what digital pin we're connected to
DHT dht(DHTPin, DHTTYPE);

const float FACTOR = 36; //30A/1V
 
const float VMIN = 1.08;
const float VMAX = 3.92;
 
const float ADCV = 5.0;  //Para Vcc
//const float ADCV = 1.1; //Para referencia interna  

double kilos = 0;
int peakPower = 0;
 
void setup()
{
   Serial.begin(9600);
   //analogReference(INTERNAL);
   
  Serial.begin(9600);            //Start serial communication
  delay(200);
  Serial.println("Cargando...");
  delay(500);
  Serial.println("Carga completada");
  delay(200);
  Serial.println("Medidor de consumo aeioLuz 0.5");  
  delay(500);
  dht.begin();
  Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"); 
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
 
   if (isnan(h) || isnan(t)) {
      Serial.println("Fallo sensor Temp/Humed.");
      return;
   }


   
   float currentRMS = getCorriente();
   float power = 233.0 * currentRMS;
  
  int maxCurrent = 0;
  int minCurrent = 1000;
  for (int i=0 ; i<=200 ; i++)  //Monitors and logs the current input for 200 cycles to determine max and min current
  {
    if(currentRMS >= maxCurrent)
      maxCurrent = currentRMS;
    else if(currentRMS <= minCurrent)
      minCurrent = currentRMS;
  }
  if (power > peakPower)
  {
    peakPower = power;
  }
  kilos = kilos + (power * (2.05/60/60/1000));    //Calculate kilowatt hours used




 
   printMeasure("Corriente: ", currentRMS, "A ,");
   printMeasure("Potencia: ", power, "W");
   printMeasure("Maximetro: ", peakPower, "Kw");
   printMeasure("Acumulado: ", kilos, "Kwh");

   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.println(" %\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.println(" *C ");
   
   Serial.println("___________________________________________");
    delay(1000);
     }

     float getCorriente()
{
   float voltage;
   float corriente;
   float sum = 0;
   long tiempo = millis();
   int counter = 0;
 
   while (millis() - tiempo < 500)
   {
      voltage = analogRead(A0) * ADCV / 1023.0;
      corriente = fmap(voltage, VMIN, VMAX, -FACTOR, FACTOR);
 
      sum += sq(corriente);
      counter = counter + 1;
      delay(1);
   }
 
   corriente = sqrt(sum / counter);
   return(corriente);

   
}
 
// cambio de escala entre floats
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
