#include <IRremote.h> //incluimos en la compilación la librería IRemote.h
int ReceptorIR = 2; //pin del receptor infrarrojo
int led = 5; //pin del led
int i;       // variable auxiliar

IRrecv irrecv(ReceptorIR); //instanciar pin a la librería
decode_results CodigoTecla; ////variable que guarda el código de tecla recibido por receptor

void setup()
{
 Serial.begin(9600); //inicio comunicación serial
 irrecv.enableIRIn(); //comienza a tomar datos
 pinMode(led, OUTPUT);//establece el pin del led como salida
}
void loop()
{
 if (irrecv.decode(&CodigoTecla)) //si alguna tecla se pulso:
 {
 Serial.print("0x"); //macro para ver código de tecla por comunicación serial
 Serial.println(CodigoTecla.value, HEX); //

 switch (CodigoTecla.value) //la variable CodigoTecla como switch
 {
 case 0xFFA25D: //al presionar la primera tecla:
 if (digitalRead(led)) //si el led se encuentra prendido
 digitalWrite(led, LOW);
 else //por el contrario, si led esta apagado, se prende
 digitalWrite(led, HIGH);
 break;
 
 case 0xFF30CF: //al presionar la segunda tecla:
 for(i=0; i<=255; i++) //prendemos el led gradualmente
 {analogWrite(led, i);
 delay(10);}
 break;

 case 0xFF18E7: //al presionar la tercera tecla:
 for(i=255; i>=0; i--) //apagamos gradualmente el led
 {analogWrite(led, i);
 delay(10);}
 break;

 }
 delay(250); //delay para evitar que se presione la tecla 2 veces
 irrecv.resume(); //dejar de recibir datos
 }
}
