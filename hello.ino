#define USBCON
#include <Arduino.h>
#include "bluetooth.h"

BlueTooth *bt;

void setup() { 
  Serial.begin(9600);
  bt = new BlueTooth(8, 9);
}

void loop() { 
  bt->sendFromSerial();
}