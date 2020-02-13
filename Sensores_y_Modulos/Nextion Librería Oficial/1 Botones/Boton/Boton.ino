

#include "Nextion.h"
NexButton b0 = NexButton(0, 13, "b0");
NexButton b1 = NexButton(0, 14, "b1");
char buffer[100] = {0};

NexTouch *nex_listen_list[] =
{
  &b0,
  &b1,
  NULL
};

void setup(void) {

  nexInit();
  b0.attachPush(b0PushCallback, &b0);
  b1.attachPop(b1PopCallback, &b1);
  dbSerialPrintln("Setup OK.");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(5000);

}

void loop(void) {

  nexLoop(nex_listen_list);

}
void b1PopCallback(void *ptr)
{
 dbSerialPrintnl("Boton bt1 pulsado");
  digitalWrite(13,!digitalRead(13));
  delay(500);
}

void b0PushCallback(void *ptr)
{
  dbSerialPrintln("Boton bt0 pulsado");
  digitalWrite(13,!digitalRead(13));
  delay(500);
  
}

