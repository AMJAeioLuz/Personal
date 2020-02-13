#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

inline size_t LiquidCrystal_I2C::write(uint8_t value) {
  send(value, Rs);
  return 1;
}
void setup() 
{
   
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 // lcd.print("Hola Mundo!!!");

}

void loop() 
{

  lcd.print("AARON CAMPEON");
  delay(3000);
  lcd.setCursor(0,1);
  
  lcd.print("Programando");
  delay(4000);
  lcd.clear();
  delay(2000);
  
  lcd.blink();
  delay(3000);
  lcd.noBlink();
  
  lcd.print("ESTO SE SALE");
  
  lcd.setCursor(0,1);
  lcd.print("NUEVO HOBIE");
  delay(5000);
  lcd.clear();
  
}
