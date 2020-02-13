//Esclavo 1 Arduino Nano
//Leds línea salida a red

#include <Wire.h>

int estado = 0;

int pinOut = 0;

void Salida_a_red() {

    Serial.println("Función Salida_a_red ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    delay(100);

    digitalWrite(29, HIGH);
    delay(500);
    digitalWrite(28, HIGH);
    delay(500);
    digitalWrite(27, HIGH);
    delay(500);
    digitalWrite(26, HIGH);
    delay(500);
    digitalWrite(25, HIGH);
    delay(500);
    digitalWrite(24, HIGH);
    delay(500);
    digitalWrite(23, HIGH);
    delay(500);
    digitalWrite(28, HIGH);
    delay(500);

    
    digitalWrite(29, LOW);
    delay(500);
    digitalWrite(28, LOW);
    delay(500);
    digitalWrite(27, LOW);
    delay(500);
    digitalWrite(26, LOW);
    delay(500);
    digitalWrite(25, LOW);
    delay(500);
    digitalWrite(24, LOW);
    delay(500);
    digitalWrite(23, LOW);
    delay(500);
    digitalWrite(22, LOW);
    delay(500);
    
}

void Entrada_desde_red() {

    Serial.println("Función Led_Salida ");
    Serial.print("El valor de estado es = ");
    Serial.println(estado);
    delay(100);

    digitalWrite(22, HIGH);
    delay(500);
    digitalWrite(23, HIGH);
    delay(500);
    digitalWrite(24, HIGH);
    delay(500);
    digitalWrite(25, HIGH);
    delay(500);
    digitalWrite(26, HIGH);
    delay(500);
    digitalWrite(27, HIGH);
    delay(500);
    digitalWrite(28, HIGH);
    delay(500);
    digitalWrite(29, HIGH);
    delay(500);

    digitalWrite(22, LOW);
    delay(500);
    digitalWrite(23, LOW);
    delay(500);
    digitalWrite(24, LOW);
    delay(500);
    digitalWrite(25, LOW);
    delay(500);
    digitalWrite(26, LOW);
    delay(500);
    digitalWrite(27, LOW);
    delay(500);
    digitalWrite(28, LOW);
    delay(500);
    digitalWrite(29, LOW);
    delay(500);

    
}

void Apagar_Led() {

    Serial.println("Función Apagar_Led ");
    delay(100);

    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);


}

void Encender_luz1() {

  digitalWrite(12, HIGH);
}

void Apagar_luz1() {

  digitalWrite(12, LOW);
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
}

void leer_entrada_i2c() {

    if (estado == 1) {

    Salida_a_red();
    
  }else{

    if (estado == 2) {

        Entrada_desde_red();
        
    }else{

      //estado = 0;
    }
  }

    if (estado == 3) {

      Apagar_Led();
      
    }  
}

void setup() {
  
  // Pines en modo salida
  
  pinMode(22, OUTPUT);     //Verde
  pinMode(23, OUTPUT);     //Rojo
  pinMode(24, OUTPUT);     //Verde
  pinMode(25, OUTPUT);     //Rojo
  pinMode(26, OUTPUT);     //Verde 
  pinMode(27, OUTPUT);     //Rojo
  pinMode(28, OUTPUT);     //Verde
  pinMode(29, OUTPUT);     //Rojo

  

  // Unimos este dispositivo al bus I2C con dirección 1
  Wire.begin(1);

  // Registramos el evento al recibir datos
  Wire.onReceive(Recibir);

  // Iniciamos el monitor serie para monitorear la comunicación
  Serial.begin(9600);
}

void loop() {
  
  delay(300);
  Wire.read();
  Serial.print("Valor Estado = ");
  Serial.println(estado);

  leer_entrada_i2c();

}
