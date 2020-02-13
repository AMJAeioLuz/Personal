#include <DS1302.h>

// Inicializacion del modulo
DS1302 rtc(2, 3, 5);
Time t;

void setup(){

  Serial.begin(9600);
  // Desproteger contra escritura
  rtc.halt(false);
  rtc.writeProtect(false);

  rtc.setDOW(SUNDAY);  // Configurar dia de la semana: MARTES.
  rtc.setTime(4, 16, 40);  // Configurar hora en formato 24hs con min y seg: 17:00:00 HORAS.
  rtc.setDate(21, 1, 2018);  // Configurar fecha en formato dia/mes/año: 4/3/2014.



}

void loop(){
  digitalWrite(13,HIGH);  // El led integrado confirmara la finalizacion.

  Serial.print("HORA:");  // Hora en formato 0-23.
  Serial.print(t.hour, DEC);
  Serial.print(", MIN:");  // Minutos.
  Serial.print(t.min, DEC);
  Serial.print(", SEG:");  // Segundos.
  Serial.print(t.sec, DEC);
  Serial.println();
    delay(3000);
}
