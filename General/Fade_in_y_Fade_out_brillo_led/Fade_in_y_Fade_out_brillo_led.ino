
const int led = 3;      //Led conectado al pin 3

int brillo;

void setup() {
  pinMode(led, OUTPUT); //declaramos el LED como salida
    //los pins analógicos se declaran como entrada automáticamente
  
}

void loop() {
  for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led, brillo);
    delay(10);
  }
  
  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led, brillo);
    delay(10);
  }
}
