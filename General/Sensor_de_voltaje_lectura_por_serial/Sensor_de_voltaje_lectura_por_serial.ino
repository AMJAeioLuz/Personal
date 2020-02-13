const int sensorPin = A0;   // seleccionar la entrada para el sensor
int sensorValue;         // variable que almacena el valor raw (0 a 1023)
float value;            // variable que almacena el voltaje (0.0 a 25.0)
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
   sensorValue = analogRead(sensorPin);          // realizar la lectura
   value = fmap(sensorValue, 0, 1023, 0.0, 25.0);   // cambiar escala a 0.0 - 25.0
   value = (value - 0.08);                          //resto los voltios para calibrar la lectura mostrada
 
   Serial.println(value);                     // mostrar el valor por serial, 
   delay(1000);
}
 
// cambio de escala entre floats
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
