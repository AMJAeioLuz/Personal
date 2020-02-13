
void setup() {
  Serial.begin(9600); 
}

void loop() {
 String variable = "este es el contenido la variable";
int pos=variable.indexOf("contenido");
if (pos>=0) {
Serial.print("se ha detectado la palabra contenido en la posicion ");
Serial.print(pos);
}
}
