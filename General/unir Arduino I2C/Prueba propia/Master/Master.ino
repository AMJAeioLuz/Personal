//Master para Nodemcu


#include <Wire.h>
#include <Keypad.h>

const byte n_rows = 4;
const byte n_cols = 4;

char myKey;

String Valor_recibido_teclado;
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','M','C'},
  {'*','0','#','D'}
};
 
byte colPins[n_rows] = {D3, D9, D8, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 

byte pin;
byte Valor_envio = 0;
long contador;


void Envio_instruccion_1() {

    Serial.println("Envio_instruccion_1");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(1);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 1, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    Leer_Teclado();

    // Esperamos 1 segundo
    delay(1000);
}

void Envio_instruccion_2() {

    Serial.println("Envio_instrucción_2");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    Leer_Teclado();

    // Esperamos 1 segundo
    delay(1000);
}

void Envio_instruccion_3() {

    Serial.println("Envio_instrucción_3");

    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(3);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 3, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    Leer_Teclado();

    // Esperamos 1 segundo
    delay(1000);
}

void Leer_Teclado() {

    myKey = myKeypad.getKey();
 
  if (myKey != NULL){
    
    Serial.print("Key pressed: ");
    
    Serial.println(myKey);
  }
  

  Valor_recibido_teclado = myKey;
}


void Envio_intrucciones_por_I2C() {
 
  if (Valor_recibido_teclado == "1") {

    Valor_envio = 1;
    Envio_instruccion_1();
  }

  if (Valor_recibido_teclado == "2") {

    Valor_envio = 2;
    Envio_instruccion_1();
  }  

  if (Valor_recibido_teclado == "A") {

    Valor_envio = 3;
    Envio_instruccion_1();
  }
  
  if (Valor_recibido_teclado == "4") {

    Valor_envio = 4;
    Envio_instruccion_1();
  }  

  if (Valor_recibido_teclado == "5") {

    Valor_envio = 5;
    Envio_instruccion_1();
  }  

    
  

  if (Valor_recibido_teclado == "*") {

    Valor_envio = 1;
    Envio_instruccion_2();
  }

  if (Valor_recibido_teclado == "0") {

    Valor_envio = 2;
    Envio_instruccion_2();
  }

  if (Valor_recibido_teclado == "#") {

    Valor_envio = 3;
    Envio_instruccion_2();
  }



  if (Valor_recibido_teclado == "B") {

    Valor_envio = 1;
    Envio_instruccion_3();
  }   

  if (Valor_recibido_teclado == "7") {

    Valor_envio = 2;
    Envio_instruccion_3();
  }
  
  if (Valor_recibido_teclado == "C") {

    Valor_envio = 4;
    Envio_instruccion_3();
  }

  if (Valor_recibido_teclado == "D") {

    Valor_envio = 3;
    Envio_instruccion_3();
  }
}

void setup() {

  pinMode(D3, INPUT);
  pinMode(D9, INPUT);
  pinMode(D8, INPUT);
  pinMode(D0, INPUT);
  pinMode(D7, INPUT);
  pinMode(D6, INPUT);
  pinMode(D5, INPUT);
  pinMode(D4, INPUT);

  
  
  // Unimos este dispositivo al bus I2C
  Wire.begin();
  Serial.begin(9600);
}



void loop() {

  contador++;
  
  Leer_Teclado();

  Envio_intrucciones_por_I2C();

  /*Serial.print("Rondas = ");
  Serial.println(contador);
  delay(500);
  */
}
