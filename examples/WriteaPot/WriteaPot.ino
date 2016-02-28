#include <DS1267.h>

DS1267 pot = DS1267(2,3,4);

void setup() {
  Serial.begin(9600);
}

void loop() {
  pot.WRT();
  pot.SET(0,100);
  Serial.println(analogRead(A0));
}
