//Esclavo 2 - Arduino Nano
//Control de leds Verdes de entrada de red.
//Control 3 leds batería

#include <Wire.h>

int estado = 0;
int brillo;
int pinOut = 0;

const int led_verde = 6;    //Led conectado al pin 3
const int led_amarillo = 5;
const int led_rojo = 3;

long Rondas_cargando_Bateria = 0;
long Rondas_descargando_Bateria = 0;

void Led_Verde_Salida_Red() {

    Serial.println("Función Led_Verde_Entrada_Red ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    delay(100);

    digitalWrite(2, HIGH);              //Led más cercano a batería
    delay(500);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(13, HIGH);             //Led más cercano a red
    delay(500);
    
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
    digitalWrite(7, LOW);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    
}

void Apagar_Leds_Verdes_Salida_Red() {

    Serial.println("Función Apagar_Leds_Verdes_Salida_Red ");
    delay(100);


  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

}

void Prueba_Test_ON() {

    Serial.println("Función Prueba_Test ");
    delay(100);

  digitalWrite(A3, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void Prueba_Test_OFF() {

    Serial.println("Función Prueba_Test_OFF ");
    delay(100);

  digitalWrite(A3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void Bateria_Cargando() {
  
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

void Descargando_Bateria() {

    Serial.println("Función Descargando_Bateria ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    //delay(100);

    Rondas_descargando_Bateria++;

    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_rojo, HIGH);

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

void Apagar_Bateria() {

    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
}

void Encender_Contador() {

    digitalWrite(A3, HIGH);
}

void Apagar_Contador() {

    digitalWrite(A3, LOW);
}

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
    Rondas_cargando_Bateria = 0;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 5) {

    estado = 5;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 6) {

    estado = 6;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 7) {

    estado = 7;
    Rondas_descargando_Bateria = 0;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 8) {

    estado = 8;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}

  if (pinOut == 9) {

    estado = 9;
    Serial.print("Valor de la variable estado cambia a ");
    Serial.println(estado);
    delay(100); 
}
}

void leer_entrada_i2c() {

    if (estado == 1) {

    Led_Verde_Salida_Red();
    }

    if (estado == 2) {

    Prueba_Test_ON();
    }


    if (estado == 3) {

      Apagar_Leds_Verdes_Salida_Red();
      
    }

    if (estado == 4) {

      Bateria_Cargando();
      
    }
    
    if (estado == 5) {

      Apagar_Bateria();
      
    }

    if (estado == 6) {

      Prueba_Test_OFF();
      
    }    

    if (estado == 7) {

      Descargando_Bateria();
      
    }

    if (estado == 8) {

      Encender_Contador();
      
    }

      if (estado == 9) {

      Apagar_Contador();
      
    } 
}

void setup(){
  
 // Pines en modo salida
 
  pinMode(A3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  // Unimos este dispositivo al bus I2C con dirección 1
  Wire.begin(2);

  // Registramos el evento al recibir datos
  Wire.onReceive(Recibir);

  // Iniciamos el monitor serie para monitorear la comunicación
  Serial.begin(115200);
}
 
void loop(){

  delay(300);
  Wire.read();
  Serial.print("Valor Estado = ");
  Serial.println(estado);

  leer_entrada_i2c();

}
