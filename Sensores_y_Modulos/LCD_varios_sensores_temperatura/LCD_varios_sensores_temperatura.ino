#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

inline size_t LiquidCrystal_I2C::write(uint8_t value) {
  send(value, Rs);
  return 1;
}

const int sensor = A0;             //entrada del sensor LM35-1
const int sensor1 = A1;            //entrada del sensor LM35-2

long miliVolts;                    //declaramos la variable long ya que el resultado de la lectura va ser un número muy grande 
long temperatura;

long miliVolts1;
long temperatura1;

byte simGrad[8] = {               //introducimos el simbolo de º
    B00110,
    B01001,
    B01001,
    B00110,
    B00000,
    B00000,
    B00000,
    B00000,
};

void setup() {
 Serial.begin(9600);              //Iniciamos comunicación serial

 lcd.begin();                     //Iniciamos el lcd

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  lcd.createChar(1, simGrad);
}

void loop() {
  
  miliVolts = (analogRead(sensor) * 5000L) / 1023;   //Calculamos los Mv en la entrada
  temperatura = miliVolts / 10;                     //Calculamos la temperatura

  miliVolts1 = (analogRead(sensor1) * 5000L) / 1023;   //Calculamos los Mv en la entrada
  temperatura1 = miliVolts1 / 10;                      //Calculamos la temperatura

  

  Serial.print("Temperatura: ");                    //mandamos la temperatura por
  Serial.print(temperatura1);                       //serial
  Serial.println(" grados");
  delay(300);                                       //Esperamos para no saturar la consola

  lcd.setCursor(1,0);
  lcd.print("Temperatura S1");
  lcd.setCursor(6,1);
  lcd.print(temperatura);
  lcd.write(byte(1));
  lcd.print("C");
  delay(2000);

  lcd.clear();
  
  lcd.setCursor(1,0);
  lcd.print("Temperatura S2");
  lcd.setCursor(6,1);
  lcd.print(temperatura1);
  lcd.write(byte(1));
  lcd.print("C");
  delay(2000);

}
