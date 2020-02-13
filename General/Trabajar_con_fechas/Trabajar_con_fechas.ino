/*
 * Copyright (C) 2019  Aaron Murillo Jara
 * 
 * In this software I have enjoyed the previous work done by colleagues in the community.
 * All my work is based on your projects with specific modifications for each purpose that I have needed to achieve.
 * That is why I thank the entire community of free software. share!!!
 * modified by Aaron Murillo Aaron.murillo@AeioLuz.com
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>

#include <Wire.h>
#include <ESP8266WiFi.h>                                                  //Librería necesaria para usar ESP con IDE Arduino.
#include <ESP8266WebServer.h>                                             //Librería para crear los servidores de configuración.
#include <EEPROM.h>                                                       //Librería para utilizar la memoria EEPROM.
#include "FS.h"                                                           //librería necesaria para sistema archivos SPIFFS.
#include "RTClib.h"                                                       //Librería para trabajar con el DS1307.
#include <TimeLib.h>                                                      //Librería para llevar cuentas de tiempo real.
#include <NtpClientLib.h>

time_t  T0, T1 ;         // Contenedores de fechas

void setup()
   {    Serial.begin(115200);  }

void loop()    {    
        // 01/02/2017
        T0 = SetFecha(2017,  2,   1,  12,  0,  0);  //01/02/2017 12:00:00
        printFecha(T0) ;
        T1 = SetFecha(2017,  3,  18, 12,  0,  0);  // 18/03/2017 12:00:00
        printFecha(T1) ;
        printFecha(T1 - T0);

        Serial.println("--------------------------------------------------");
        time_t H =  T1 - T0 ;

        Serial.print(String(year(H )- 1970)+" años,"  + String(month(H)-1 )+" meses,");
        Serial.println(String(day(H)-1)+ " dias," + String(hour(H))+ " horas,");
        Serial.println(String(minute(H))+ " Minutos," + String(second(H))+ " Segundos");
        Serial.println("---------------------------------------------------");
   }

void printFecha(time_t  t)
   {
       Serial.print(day(t)) ;    Serial.print(+ "/") ;   Serial.print(month(t));   Serial.print(+ "/") ;
       Serial.print(year(t));    Serial.print( " ") ;
       Serial.print(hour(t));   Serial.print(+ ":") ;   Serial.print(minute(t));   Serial.print(":") ;
       Serial.println(second(t));
       delay(1000);
   }

time_t SetFecha(int y, int m, int d, int h, int mi, int s  )
   {  tmElements_t Fecha ;
      Fecha.Second = s;
      Fecha.Minute = mi;
      Fecha.Hour = h;
      Fecha.Day = d ;
      Fecha.Month = m ;
      Fecha.Year = y -1970 ;
 
      return makeTime(Fecha);
   }
