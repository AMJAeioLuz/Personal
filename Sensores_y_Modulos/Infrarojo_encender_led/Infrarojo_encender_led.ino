void setup() { 
  pinMode(11,OUTPUT); 
  Serial.begin(9600); 
} 


void loop() { 

  int sensor = analogRead(A5); 
   
  if(sensor<25){ 
    digitalWrite(11,HIGH); 
  }else{ 
    digitalWrite(11,LOW); 
  } 
   
  delay(1);   


  // Imprimimos el valor en el monitor.
  Serial.print("sensor = " );                       
  Serial.println(sensor);     

  delay(100);                     
}
