const int ledPin =  2;    // se define el pin de salida(LED)
float sensorValue = 0;   // variable que almacena el valor del sensor infrarrojo

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);     

}

void loop(){
      sensorValue = analogRead(A0); // se lee el valor del sensor
float voltaje = sensorValue * (5.0 / 1023.0);  // se escala a un rango de 0-5V

Serial.println(voltaje);

 // analiza si el laser se encuentra proyectado sobre el LDR
  if (voltaje > 3.5) {         
   // Este valor(3.5) es referencial, dado que puede cambiar segun la distancia del laser al sensor LDR,
   // se recomienda usar varia el valor, segun los datos del serial monitor
    digitalWrite(ledPin, LOW);  // de serlo asi se mantiene apagado el LED
  }
  else {
    digitalWrite(ledPin, HIGH); // de lo contrario se prende el LED
  }
}
