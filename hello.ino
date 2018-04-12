#include <Arduino.h>
#include "bluetooth.h"

int lastTime = 0;
BlueTooth *bt;

void setup() {
  Serial.begin(9600);
  bt = new BlueTooth(8, 9);
}

void loop() {
  char buf[64];
  int cnt;
  while (bt->check()) {
    cnt = bt->receive(buf, 63);
    buf[cnt] = 0;
    Serial.print(buf);
  }
  bt->sendRaw();
  delay(10);
}