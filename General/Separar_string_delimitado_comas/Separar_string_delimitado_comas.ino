<code>
/* Programa para comprobar como a partir de un string con varias variables
separadas por comas, podemos acceder a cada una de ellas y manipularla
como queramos */

String mensaje = "Pepe,Jose,Juan";
int PosicionComa; //Variable que nos dice la posicion de la coma en el mensaje.

void setup () {
Serial.begin (9600); //Iniciamos la comunicacion serie.
}

void loop () {
Serial.println (mensaje); //Imprime el mensaje nada mas iniciar el programa
delay (5000);
do {
PosicionComa = mensaje.indexOf (','); //Buscamos la primera coma del mensaje.
if (PosicionComa != -1) {
Serial.println (mensaje.substring (0, PosicionComa)); //En caso de que encontremos una ',' mostramos el texto desde el principio hasta la posicion anterior a la ','.
mensaje = mensaje.substring (PosicionComa+1, mensaje.length()); //Ahora borramos el mensaje y decimos que es desde la posicion posterior a la ',' hasta el final del string.
delay (5000);
}
else { //Entramos aqui si ya no quedan mas ','
if (mensaje.length() > 0)
Serial.println (mensaje); //Imprimimos el resto de texto que falta.
mensaje = "Pepe,Jose,Juan";
}
}
while (PosicionComa > 0 );
delay(5000);
}

</code>
