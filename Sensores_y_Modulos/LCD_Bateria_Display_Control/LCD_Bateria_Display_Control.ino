

const int Bateria_Baja = 2;
const int Bateria_Baja_Control = 3;
const int Bateria_1_raya = 4;
const int Bateria_1_raya_Control = 5;
const int Bateria_2_raya = 6;
const int Bateria_2_raya_Control = 7;
const int Bateria_3_raya = 8;
const int Bateria_3_raya_Control = 9;
const int Bateria_4_raya = 10;
const int Bateria_4_raya_Control = 11;







void setup() {

  Serial.begin(115200);                                                         // Inicia Serial
  Serial.println("");
  // put your setup code here, to run once:
pinMode(Bateria_Baja, OUTPUT);
pinMode(Bateria_Baja_Control, OUTPUT);
pinMode(Bateria_1_raya, OUTPUT);
pinMode(Bateria_1_raya_Control, OUTPUT);
pinMode(Bateria_2_raya, OUTPUT);
pinMode(Bateria_2_raya_Control, OUTPUT);
pinMode(Bateria_3_raya, OUTPUT);
pinMode(Bateria_3_raya_Control, OUTPUT);
pinMode(Bateria_4_raya, OUTPUT);
pinMode(Bateria_4_raya_Control, OUTPUT);

Serial.println("Prueba XXXXXXXXXXXXXXXXXXXXX");
}

void loop() {
  // put your main code here, to run repeatedly:



Serial.println("Bateria_Baja ON");
digitalWrite(Bateria_Baja, HIGH);   //para usarlo en analogWrite
digitalWrite(Bateria_Baja_Control, HIGH);
delay(5000);
//Serial.println("Bateria_Baja OFF");
//digitalWrite(Bateria_Baja, LOW);   //para usarlo en analogWrite
//digitalWrite(Bateria_Baja_Control, LOW);
//delay(2000);
Serial.println("Bateria_1_raya ON");
digitalWrite(Bateria_1_raya, HIGH);   //para usarlo en analogWrite
digitalWrite(Bateria_1_raya_Control, HIGH);
delay(5000);
//Serial.println("Bateria_1_raya OFF");
//digitalWrite(Bateria_1_raya, LOW);   //para usarlo en analogWrite
//digitalWrite(Bateria_1_raya_Control, LOW);
//delay(2000);
Serial.println("Bateria_2_raya ON");
digitalWrite(Bateria_2_raya, HIGH);   //para usarlo en analogWrite
digitalWrite(Bateria_2_raya_Control, HIGH);
delay(5000);
//Serial.println("Bateria_2_raya OFF");
//digitalWrite(Bateria_2_raya, LOW);   //para usarlo en analogWrite
//digitalWrite(Bateria_2_raya_Control, LOW);
//delay(2000);
Serial.println("Bateria_3_raya ON");
digitalWrite(Bateria_3_raya, HIGH);   //para usarlo en analogWrite
digitalWrite(Bateria_3_raya_Control, HIGH);
delay(5000);
//Serial.println("Bateria__raya OFF");
//digitalWrite(Bateria_3_raya, LOW);   //para usarlo en analogWrite
//digitalWrite(Bateria_3_raya_Control, LOW);
//delay(2000);
Serial.println("Bateria_4_raya ON");
digitalWrite(Bateria_4_raya, HIGH);   //para usarlo en analogWrite
digitalWrite(Bateria_4_raya_Control, HIGH);
delay(5000);
Serial.println("Bateria_4_raya OFF");
digitalWrite(Bateria_4_raya, LOW);   //para usarlo en analogWrite
digitalWrite(Bateria_4_raya_Control, LOW);
delay(5000);
Serial.println("Bateria_3_raya OFF");
digitalWrite(Bateria_3_raya, LOW);   //para usarlo en analogWrite
digitalWrite(Bateria_3_raya_Control, LOW);
delay(5000);
Serial.println("Bateria_2_raya OFF");
digitalWrite(Bateria_2_raya, LOW);   //para usarlo en analogWrite
digitalWrite(Bateria_2_raya_Control, LOW);
delay(5000);
Serial.println("Bateria_1_raya OFF");
digitalWrite(Bateria_1_raya, LOW);   //para usarlo en analogWrite
digitalWrite(Bateria_1_raya_Control, LOW);
delay(5000);
Serial.println("Bateria_Baja OFF");
digitalWrite(Bateria_Baja, LOW);   //para usarlo en analogWrite
digitalWrite(Bateria_Baja_Control, LOW);

delay(2000);




}
