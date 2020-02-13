String data = "aeioLuz_Moni_5,21:51:08 26/03/2018,1.11,2.22,3.33,44,5.55,6.66";                 // Cadena de caracteres de prueba

void setup() {
  Serial.begin(115200);                                     // Iniciar comunicación serial
  
  String values[7];                                         // Una forma más "compacta" de crear seis variables.
  byte prevPos = data.indexOf(',');                       // Buscar la posición de la primera coma en la cadena
  String first = data.substring(0, prevPos);              // Extraer la primera cadena de caracteres (sin coma)
  prevPos++;                                              // Desplazar el índice de la primera coma. Sin esto, la próxima búsqueda resultará
                                                          // en la misma posición.
  byte currPos = data.indexOf(',', prevPos);              // La siguente subcadena ya no empezará desde el principio; por lo tanto, hay que
                                                          // almacenar dos posiciones.
  
  for (byte i = 0; i < 7; i++) {
    values[i] = data.substring(prevPos, currPos); // Extrae la subcadena que contiene un número, luego se convierte en un valor
                                                          // númerico de variable.
    prevPos = currPos + 1;                                // Como ahora trabajamos con dos posiciones y necesitamos pasar a la siguiente
                                                          // subcadena, la "posición actual" ahora es la anterior. No olvidemos el
                                                          // desplazamiento de índice.
    currPos = data.indexOf(',', prevPos);                 // La "posición actual" ahora es la próxima ocurrencia del "caracter separador"
                                                          // (en este caso, una coma).
  }                                                       // Y todo esto se repite 5 veces más.

  Serial.println(first);                     // Imprime, al monitor serie, la primera subcadena extraída.
  
  for (byte i = 0; i < 7; i++) {                          // Imprime el valor de las seis variables extraídas del texto de prueba.
    Serial.println(String(i + 1) + ": " + String(values[i]));

    Serial.print("PRUEBA2= ");
Serial.println(values[1]);
  }
}

void loop() {
                                                          // Y se acabó. Luego no ocurre nada :P

}
