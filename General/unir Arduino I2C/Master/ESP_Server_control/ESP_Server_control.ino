#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <Wire.h>

//-------------------VARIABLES GLOBALES--------------------------
int contconexion = 0;
unsigned long previousMillis = 0;

char ssid[50];
char pass[50];
char Modo_Representacion[50];

const char *ssidConf = "Autoconsumo AeioLuz";
const char *passConf = "CeroEmisiones";

String mensaje = "";
byte Valor_envio = 0;

//-----------CODIGO HTML PAGINA DE CONFIGURACION---------------
String pagina = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<title>Maqueta Autoconsumo AeioLuz</title>"
                "<meta charset='UTF-8'>"
                "</head>"
                "<body>"
                "</form>"
                "<form action='Envio_Esclavo2_Salida_a_red' method='get'>"
                "<a href='Envio_Esclavo2_Salida_a_red'><button class='boton'>Encender inyección a red</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Apagar_Inyeccion_a_red' method='get'>"
                "<a href='Envio_Esclavo2_Apagar_Inyeccion_a_red'><button class='boton'>Apagar inyección a red</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Bateria_Cargando' method='get'>"
                "<a href='Envio_Esclavo2_Bateria_Cargando'><button class='boton'>Batería cargando</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Descargar_Bateria' method='get'>"
                "<a href='Envio_Esclavo2_Descargar_Bateria'><button class='boton'>Descargar batería</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Apagar_Bateria' method='get'>"
                "<a href='Envio_Esclavo2_Apagar_Bateria'><button class='boton'>Apagar batería</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Encender_Contador' method='get'>"
                "<a href='Envio_Esclavo2_Encender_Contador'><button class='boton'>Encender Contador</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Apagar_Contador' method='get'>"
                "<a href='Envio_Esclavo2_Apagar_Contador'><button class='boton'>Apagar Contador</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Prueba_Test_ON' method='get'>"
                "<a href='Envio_Esclavo2_Prueba_Test_ON'><button class='boton'>Test ON</button></a><br><br>"
                "</form>"
                "<form action='Envio_Esclavo2_Test_OFF' method='get'>"
                "<a href='Envio_Esclavo2_Test_OFF'><button class='boton'>Test OFF</button></a><br><br>"
                "</form>"
                "<a href='escanear'><button class='boton'>ESCANEAR</button></a><br><br>";

String paginafin = "</body>"
                   "</html>";

//------------------------SETUP WIFI----------------------------- 
void setup_wifi() {
  
  // Conexión WIFI
  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED and contconexion < 50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    delay(250);
    Serial.print(".");
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
  }
  if (contconexion < 50) {
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
    digitalWrite(13, HIGH);
  }
  else {
    Serial.println("");
    Serial.println("Error de conexion");
    digitalWrite(13, LOW);
  }
}

//--------------------------------------------------------------
WiFiClient espClient;
ESP8266WebServer server(80);
//--------------------------------------------------------------

//-------------------PAGINA DE CONFIGURACION--------------------
void paginaconf() {
  server.send(200, "text/html", pagina + mensaje + paginafin);
}

//--------------------MODO_CONFIGURACION------------------------
void modoconf() {

  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);

  WiFi.softAP(ssidConf, passConf);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP del acces point: ");
  Serial.println(myIP);
  Serial.println("WebServer iniciado...");

  server.on("/", paginaconf); //esta es la pagina de configuracion

  server.on("/escanear", escanear); //Escanean las redes wifi disponibles 

  server.on("/Envio_Esclavo2_Salida_a_red", Envio_Esclavo2_Salida_a_red);

  server.on("/Envio_Esclavo2_Prueba_Test_ON", Envio_Esclavo2_Prueba_Test_ON);

  server.on("/Envio_Esclavo2_Apagar_Inyeccion_a_red", Envio_Esclavo2_Apagar_Inyeccion_a_red);

  server.on("/Envio_Esclavo2_Bateria_Cargando", Envio_Esclavo2_Bateria_Cargando);

  server.on("/Envio_Esclavo2_Apagar_Bateria", Envio_Esclavo2_Apagar_Bateria);

  server.on("/Envio_Esclavo2_Encender_Contador", Envio_Esclavo2_Encender_Contador);

  server.on("/Envio_Esclavo2_Apagar_Contador", Envio_Esclavo2_Apagar_Contador);

  server.on("/Envio_Esclavo2_Test_OFF", Envio_Esclavo2_Test_OFF);

  server.on("/Envio_Esclavo2_Descargar_Bateria", Envio_Esclavo2_Descargar_Bateria);
  
  server.begin();

  while (true) {
    server.handleClient();
  }
}

//---------------------GUARDAR CONFIGURACION-------------------------
void guardar_conf() {

  Serial.println(server.arg("ssid"));//Recibimos los valores que envia por GET el formulario web
  grabar(0, server.arg("ssid"));
  Serial.println(server.arg("pass"));
  grabar(50, server.arg("pass"));
  Serial.println(server.arg("Modo_Representacion"));
  grabar(100, server.arg("Modo_Representacion"));


  mensaje = "Configuracion Guardada...";
  paginaconf();
}

//----------------Función para grabar en la EEPROM-------------------
void grabar(int addr, String a) {
  int tamano = a.length();
  char inchar[50];
  a.toCharArray(inchar, tamano + 1);
  for (int i = 0; i < tamano; i++) {
    EEPROM.write(addr + i, inchar[i]);
  }
  for (int i = tamano; i < 50; i++) {
    EEPROM.write(addr + i, 255);
  }
  EEPROM.commit();
}

//-----------------Función para leer la EEPROM------------------------
String leer(int addr) {
  byte lectura;
  String strlectura;
  for (int i = addr; i < addr + 50; i++) {
    lectura = EEPROM.read(i);
    if (lectura != 255) {
      strlectura += (char)lectura;
    }
  }
  return strlectura;
}

//---------------------------ESCANEAR----------------------------
void escanear() {
  int n = WiFi.scanNetworks(); //devuelve el número de redes encontradas
  Serial.println("escaneo terminado");
  if (n == 0) { //si no encuentra ninguna red
    Serial.println("no se encontraron redes");
    mensaje = "no se encontraron redes";
  }
  else
  {
    Serial.print(n);
    Serial.println(" redes encontradas");
    mensaje = "";
    for (int i = 0; i < n; ++i)
    {
      // agrega al STRING "mensaje" la información de las redes encontradas
      mensaje = (mensaje) + "<p>" + String(i + 1) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") Ch: " + WiFi.channel(i) + " Enc: " + WiFi.encryptionType(i) + " </p>\r\n";
      //WiFi.encryptionType 5:WEP 2:WPA/PSK 4:WPA2/PSK 7:open network 8:WPA/WPA2/PSK
      delay(10);
    }
    Serial.println(mensaje);
    paginaconf();
  }
}

//------------------------------Envio_instruccion_1----------------------------

void Envio_Esclavo2_Salida_a_red() {

    Valor_envio = 1;

    Serial.println("Envio_Esclavo2_Salida_a_red");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Inyectando energía Verde a la red!";

    paginaconf();
}

//------------------------------Envio_instruccion_2----------------------------

void Envio_Esclavo2_Prueba_Test_ON() {

    Valor_envio = 2;

    Serial.println("Envio_Esclavo2_Prueba_Test_ON");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Probando!!! Todo conectado!!!";

    paginaconf();
}

//------------------------------Envio_instruccion_3----------------------------

void Envio_Esclavo2_Apagar_Inyeccion_a_red() {

    Valor_envio = 3;

    Serial.println("Envio_instruccion_3");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Apagando línea de inyección a red!";

    paginaconf();
}

//------------------------------Envio_instruccion_4----------------------------

void Envio_Esclavo2_Bateria_Cargando() {

    Valor_envio = 4;

    Serial.println("Envio_instruccion_4");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Batería cargando!";

    paginaconf();
}

//------------------------------Envio_instruccion_5----------------------------

void Envio_Esclavo2_Apagar_Bateria() {

    Valor_envio = 5;

    Serial.println("Envio_instruccion_5");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Apagando Batería!";

    paginaconf();
}

//------------------------------Envio_instruccion_6----------------------------

void Envio_Esclavo2_Test_OFF() {

    Valor_envio = 6;

    Serial.println("Envio_instruccion_6");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Envio_Esclavo2_Test_OFF";

    paginaconf();
}

//------------------------------Envio_instruccion_7----------------------------

void Envio_Esclavo2_Descargar_Bateria() {

    Valor_envio = 7;

    Serial.println("Envio_instruccion_7");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Descargando Batería";

    paginaconf();
}

//------------------------------Envio_instruccion_8----------------------------

void Envio_Esclavo2_Encender_Contador() {

    Valor_envio = 8;

    Serial.println("Envio_instruccion_8");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Contador Encendido";

    paginaconf();
}

//------------------------------Envio_instruccion_9----------------------------

void Envio_Esclavo2_Apagar_Contador() {

    Valor_envio = 9;

    Serial.println("Envio_instruccion_9");

    // Comenzamos la transmisiÃ³n al dispositivo 1
    Wire.beginTransmission(2);

    // Enviamos un byte, serÃ¡ el pin a encender
    Wire.write(Valor_envio);
    Serial.print("Envío al esclavo 2, número = ");
    Serial.println(Valor_envio);

    // Paramos la transmisiÃ³n
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);

    mensaje = "Contador Encendido";

    paginaconf();
}
//------------------------SETUP-----------------------------
void setup() {

  pinMode(13, OUTPUT); // D7

  // Inicia Serial
  Serial.begin(115200);
  Serial.println("");

  // Unimos este dispositivo al bus I2C
  Wire.begin();

  EEPROM.begin(512);

}

//--------------------------LOOP--------------------------------
void loop() {

  modoconf();


}
