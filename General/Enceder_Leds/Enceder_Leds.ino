// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  for (int a=0; a<5; a++)

{
  
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
   digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
   digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
   digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
   digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
  
   digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
  
   digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delay(700);               // wait for a second

}  
  
    for (int a=0; a<5; a++)
  
{
      
   digitalWrite(2, HIGH);
   digitalWrite(4, HIGH);
      delay(500);
      
   digitalWrite(3, HIGH);
   digitalWrite(5, HIGH);
      delay(500);
        
        
        
    }      
}
