int LED = 10 ; 
int sensor = 6 ;
bool estado = false ;

void setup()
{

    Serial.begin(9600);    // Iniciamos la puerta serie
  pinMode( LED, OUTPUT) ;
  pinMode( sensor , INPUT_PULLUP) ;
  digitalWrite(LED , LOW) ; // Apagamos el LED al empezar
}
void loop()
{


   int Lectura = analogRead(A5) ;
  Serial.println( Lectura);
  delay(200) ;

  
  bool  valor =  digitalRead(sensor) ; //leemos el botón: false  =  LOW
  if ( valor == true) // Está activada la salida D0 del sensor
  {
    estado = ! estado ; // cambiamos el estado
    digitalWrite(LED, estado) ; // escribimos el nuevo valor
    delay (1000);
  }
}
