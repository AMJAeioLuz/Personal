
const int led = 3;      //Led conectado al pin 3
const int pot = A0;      //pot conectado al pin A=

int brillo;

void setup() {
  pinMode(led, OUTPUT); //declaramos el LED como salida
    //los pins analógicos se declaran como entrada automáticamente
  
}

void loop() {
  brillo = analogRead(pot) / 4; // leemos el valor del potenciometro y lo dividimos entre 4
    analogWrite(led, brillo);   //para usarlo en analogWrite
  
  
}
