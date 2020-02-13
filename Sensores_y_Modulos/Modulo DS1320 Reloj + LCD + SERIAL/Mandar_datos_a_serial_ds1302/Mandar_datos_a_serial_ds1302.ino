#include <DS1302.h>

// Inicializacion del modulo.
DS1302 rtc(2, 3, 5);
Time t;

void setup() {
// Inicializacion del puerto serie.
Serial.begin(9600);
}

void loop() {
  // Obtencion de datos
  t = rtc.getTime();
  
  // Publicar en LCD
  // Se publicara el dia de la semana
  Serial.print("HOY:"); 
  if (t.dow == 1) Serial.print("lunes");  // La variable t.dow (dia de la semana) tedra valor de 1 para dia lunes y 7 para domingo.
  if (t.dow == 2) Serial.print("martes");
  if (t.dow == 3) Serial.print("miercoles");
  if (t.dow == 4) Serial.print("jueves");
  if (t.dow == 5) Serial.print("viernes");
  if (t.dow == 6) Serial.print("sabado");
  if (t.dow == 7) Serial.print("domingo");
  
  Serial.println();  // Linea aparte
  
  // Se publicaran datos de fecha, en numeros.
  Serial.print("DIA:");
  Serial.print(t.date, DEC);  // Dia del mes
  
  Serial.println();
  
  // Mes
  Serial.print("MES:");
  Serial.print(t.mon);
  
  Serial.println();
  
  // Año
  Serial.print("DE:");
  Serial.print(t.year, DEC);
  
  Serial.println();
  
  Serial.print("HORA:");  // Hora en formato 0-23.
  Serial.print(t.hour, DEC);
  Serial.print(", MIN:");  // Minutos.
  Serial.print(t.min, DEC);
  Serial.print(", SEG:");  // Segundos.
  Serial.print(t.sec, DEC);
  
  Serial.println();
  Serial.println();
  Serial.println();
  
  delay(3000);  // Demora para no sobrecargar las comunicaciones con el modulo.
}
