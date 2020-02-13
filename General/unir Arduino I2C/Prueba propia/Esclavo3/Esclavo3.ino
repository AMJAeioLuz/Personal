#include <Wire.h>

int estado = 0;
const int led_verde = 3;    //Led conectado al pin 3
const int led_amarillo = 5;
const int led_rojo = 6;
int pinOut = 0;
int brillo;
long Rondas_cargando_Bateria = 0;
long Rondas_descargando_Bateria = 0;

// Función que se ejecuta siempre que se reciben datos del master
// siempre que en el master se ejecute la sentencia endTransmission
// recibirá toda la información que hayamos pasado a través de la sentencia Wire.write

void Recibir(){

  Serial.println("Función recibir!");

  pinOut = Wire.read();

  Serial.println(pinOut);

  delay(100);

  if (pinOut == 1) {

    estado = 1;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 2) {

    estado = 2;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 3) {

    estado = 3;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 4) {

    estado = 4;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}
}

void leer_entrada_i2c() {

    if (estado == 1) {

    Cargando_Bateria();
    
  }else{

    if (estado == 2) {

        Descargando_Bateria();
        
    }else{

      //estado = 0;
    }
  }

    if (estado == 3) {

      Apagar_Bateria();
      
    }

    if (estado == 4) {

      Mantener_Bateria_Cargada();
      
    }
}

void Cargando_Bateria() {

    Serial.println("Función Cargando_Bateria ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    delay(100);

    Rondas_cargando_Bateria++;

if (Rondas_cargando_Bateria <= 20) {

    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_rojo, brillo);
    delay(10);
  }

  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_rojo, brillo);
    delay(10);
  }  
}

if (Rondas_cargando_Bateria >= 21) {

  if (Rondas_cargando_Bateria <= 35) {

    digitalWrite(led_rojo, HIGH);
    delay(200);
    digitalWrite(led_rojo, LOW);
    
  }
}

if (Rondas_cargando_Bateria >= 36) {

  if (Rondas_cargando_Bateria <= 50) {

    digitalWrite(led_rojo, HIGH);
    delay(75);
    digitalWrite(led_rojo, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 51) {

  if (Rondas_cargando_Bateria <= 69) {

    digitalWrite(led_rojo, HIGH);
    delay(20);
    digitalWrite(led_rojo, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 70) {

digitalWrite(led_rojo, HIGH);
  
}

if (Rondas_cargando_Bateria >= 71) {

    if (Rondas_cargando_Bateria <= 91) {

    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_amarillo, brillo);
    delay(10);
  }

  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_amarillo, brillo);
    delay(10);
  }
    }
}

if (Rondas_cargando_Bateria >= 92) {

  if (Rondas_cargando_Bateria <= 105) {

    digitalWrite(led_amarillo, HIGH);
    delay(200);
    digitalWrite(led_amarillo, LOW);
    
  }
}

if (Rondas_cargando_Bateria >= 106) {

  if (Rondas_cargando_Bateria <= 121) {

    digitalWrite(led_amarillo, HIGH);
    delay(75);
    digitalWrite(led_amarillo, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 122) {

  if (Rondas_cargando_Bateria <= 137) {

    digitalWrite(led_amarillo, HIGH);
    delay(20);
    digitalWrite(led_amarillo, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 137) {

digitalWrite(led_amarillo, HIGH);
  
}

if (Rondas_cargando_Bateria >= 138) {

    if (Rondas_cargando_Bateria <= 158) {

    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_verde, brillo);
    delay(10);
  }

  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_verde, brillo);
    delay(10);
  }
    }
}

if (Rondas_cargando_Bateria >= 159) {

  if (Rondas_cargando_Bateria <= 174) {

    digitalWrite(led_verde, HIGH);
    delay(200);
    digitalWrite(led_verde, LOW);
    
  }
}

if (Rondas_cargando_Bateria >= 175) {

  if (Rondas_cargando_Bateria <= 190) {

    digitalWrite(led_verde, HIGH);
    delay(75);
    digitalWrite(led_verde, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 191) {

  if (Rondas_cargando_Bateria <= 204) {

    digitalWrite(led_verde, HIGH);
    delay(20);
    digitalWrite(led_verde, LOW);   
  }
}

if (Rondas_cargando_Bateria >= 205) {

digitalWrite(led_verde, HIGH);
  
}

Serial.print("Nº de Rondas cargando bateria = ");
Serial.println(Rondas_cargando_Bateria);
  
}

void Mantener_Bateria_Cargada() {

    Serial.println("Función Mantener_Bateria_Cargada ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    delay(100);

  for(brillo = 15; brillo >= 0; brillo--){

    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_rojo, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
    delay(100);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_rojo, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);

  }

    leer_entrada_i2c();
   
  for(brillo = 15; brillo >= 0; brillo--){

    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
    delay(100);
    digitalWrite(led_rojo, HIGH);
    delay(100);
    digitalWrite(led_amarillo, HIGH);
    delay(100);
    digitalWrite(led_verde, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    delay(100);
    digitalWrite(led_verde, HIGH);
    delay(200);
    digitalWrite(led_verde, LOW);
    
  }
}

void Apagar_Bateria() {

    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
}

void Descargando_Bateria() {

    Serial.println("Función Descargando_Bateria ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    //delay(100);

    Rondas_descargando_Bateria++;

if (Rondas_descargando_Bateria <= 20) {

    for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_verde, brillo);
    delay(10);
  }  

    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_verde, brillo);
    delay(10);
  }
}

if (Rondas_descargando_Bateria >= 21) {

  if (Rondas_descargando_Bateria <= 35) {

    digitalWrite(led_verde, HIGH);
    delay(20);
    digitalWrite(led_verde, LOW);
    
  }
}

if (Rondas_descargando_Bateria >= 36) {

  if (Rondas_descargando_Bateria <= 50) {

    digitalWrite(led_verde, HIGH);
    delay(75);
    digitalWrite(led_verde, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 51) {

  if (Rondas_descargando_Bateria <= 69) {

    digitalWrite(led_verde, HIGH);
    delay(200);
    digitalWrite(led_verde, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 70) {

digitalWrite(led_verde, LOW);
  
}

if (Rondas_descargando_Bateria >= 71) {

    if (Rondas_descargando_Bateria <= 91) {

  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_amarillo, brillo);
    delay(10);
  }

    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_amarillo, brillo);
    delay(10);
  }
 }
}

if (Rondas_descargando_Bateria >= 92) {

  if (Rondas_descargando_Bateria <= 105) {

    digitalWrite(led_amarillo, HIGH);
    delay(20);
    digitalWrite(led_amarillo, LOW);
    
  }
}

if (Rondas_descargando_Bateria >= 106) {

  if (Rondas_descargando_Bateria <= 121) {

    digitalWrite(led_amarillo, HIGH);
    delay(75);
    digitalWrite(led_amarillo, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 122) {

  if (Rondas_descargando_Bateria <= 137) {

    digitalWrite(led_amarillo, HIGH);
    delay(200);
    digitalWrite(led_amarillo, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 137) {

digitalWrite(led_amarillo, LOW);
digitalWrite(led_verde, LOW);
  
}

if (Rondas_descargando_Bateria >= 138) {

    if (Rondas_descargando_Bateria <= 158) {

  for(brillo = 255; brillo >= 0; brillo--){   //Fade out al brillo de LED
    analogWrite(led_rojo, brillo);
    delay(10);
  }
  
    for(brillo = 0; brillo < 256; brillo++){    //Fade in al brillo de LED
    analogWrite(led_rojo, brillo);
    delay(10);
  }
 }
}

if (Rondas_descargando_Bateria >= 159) {

  if (Rondas_descargando_Bateria <= 174) {

    digitalWrite(led_rojo, HIGH);
    delay(200);
    digitalWrite(led_rojo, LOW);
    
  }
}

if (Rondas_descargando_Bateria >= 175) {

  if (Rondas_descargando_Bateria <= 190) {

    digitalWrite(led_rojo, HIGH);
    delay(75);
    digitalWrite(led_rojo, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 191) {

  if (Rondas_descargando_Bateria <= 204) {

    digitalWrite(led_rojo, HIGH);
    delay(20);
    digitalWrite(led_rojo, LOW);   
  }
}

if (Rondas_descargando_Bateria >= 205) {

digitalWrite(led_rojo, LOW);
delay(100);
digitalWrite(led_rojo, HIGH);
delay(100);
digitalWrite(led_rojo, LOW);
delay(100);
digitalWrite(led_rojo, HIGH);
delay(100);
digitalWrite(led_rojo, LOW);
digitalWrite(led_amarillo, LOW);
digitalWrite(led_verde, LOW);

}

Serial.print("Nº de Rondas descargando bateria = ");
Serial.println(Rondas_descargando_Bateria);
leer_entrada_i2c();
  
}

void setup() {

  pinMode(3, OUTPUT);     //Verde
  pinMode(5, OUTPUT);     //Amarillo
  pinMode(6, OUTPUT);     //Rojo

  // Unimos este dispositivo al bus I2C con dirección 1
  Wire.begin(3);

    // Registramos el evento al recibir datos
  Wire.onReceive(Recibir);

    // Iniciamos el monitor serie para monitorear la comunicación
  Serial.begin(9600);

}

void loop() {
  

  //delay(300);
  Wire.read();
  Serial.print("Valor Estado = ");
  Serial.println(estado);

  leer_entrada_i2c();

}
