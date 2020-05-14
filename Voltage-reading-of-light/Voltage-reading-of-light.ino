#include <Wire.h> 
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();
 
#define inPin0 0
 
void setup(void) {
 
  Serial.begin(9600);
#ifndef _AVR_ATtiny85_
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);     
}
 
void loop(void) {
   
  int pinRead0 = analogRead(inPin0);
  float pVolt0 = pinRead0 / 1024.0 * 5.0;


   matrix.println(pVolt0);
   matrix.writeDisplay();
   Serial.print(pVolt0);
   Serial.println();
   
  delay(500);
   
}
