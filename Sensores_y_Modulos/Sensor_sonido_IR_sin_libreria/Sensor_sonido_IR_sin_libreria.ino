#define trigPin 4
#define echoPin 5

void setup(){ 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){ 
  long duracion, distancia ;
  digitalWrite(trigPin, LOW); // Trigger
  delayMicroseconds(5); // Nos aseguramos Trigger esta LOW
  digitalWrite(trigPin, HIGH); // Activamos el pulso de salida
  delayMicroseconds(10); // Esperamos 10µs. 
  digitalWrite(trigPin, LOW); // Cortamos el pulso
  duracion = pulseIn(echoPin, HIGH) ;
  distancia = duracion / 2 / 29.1  ;
  Serial.println(String(distancia) + " cm.") ;
  delay (500) ; // Limitamos el número de mediciones
}
