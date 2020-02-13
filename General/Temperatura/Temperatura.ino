/* Cambia el color de un LED RGB de azul a rojo
dependiendo de la temperatura*/

const int sensor = A5;    //entrada del sensor LM35
const int ledRojo = 5;    //pin del LED rojo
const int ledAzul =6;   //pin del LED azul

long miliVolts;
long temperatura;

int brillo;

void setup() {
  Serial.begin(9600);   //Iniciamos la comunicación serial
pinMode(ledRojo, OUTPUT);
pinMode(ledAzul, OUTPUT);
  
 }


void loop() {
  miliVolts = (analogRead(sensor) *5000L) / 1023;   //calculamos los mV en la entrada
  temperatura = miliVolts / 10;             //calculamos la temperatura del sensor

  brillo = map(temperatura, 10, 40, 0, 255);    //ajustamos la escala de temperatura para poder usar analogWrite
  brillo = constrain(brillo, 0, 255);           //Limitamos el rango de brillo a 0 y 255

  analogWrite(ledRojo, brillo);                 //Ajustamos el color del LED
  analogWrite(ledAzul, 255 - brillo);
 Serial.print("Temperatura: ");            //Mandamos la temeratura por
  Serial.print(temperatura);                //serial
  Serial.println(" grados");
  delay(500);                               //esperamos para no saturar el monitor
}
