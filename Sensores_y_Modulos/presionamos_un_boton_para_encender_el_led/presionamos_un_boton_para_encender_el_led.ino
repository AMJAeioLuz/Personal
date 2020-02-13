/*presionamos un boton para encender el led
lo volvemos a presionar para apagarlo.*/

int estado = 0; 


void setup() {

pinMode(4, INPUT);              //Declaramos el botón como entrada
pinMode(11, OUTPUT);             //Declaramos el LED como salida
Serial.begin(9600);  
}

void loop() {

  Serial.println(estado);                                   //Imprimimos por serial Detectada lluvia
  Serial.print("BOTON: ");
  Serial.println(digitalRead(4));
      delay(200);

  estado = digitalRead(4);      //Leer el estado del botón
  if(estado == HIGH){           // si estado está en alto
    digitalWrite(11, HIGH);      // encendemos el LED
    }

  else{
    digitalWrite(11,LOW);      // apagamos el LED
    }
}
