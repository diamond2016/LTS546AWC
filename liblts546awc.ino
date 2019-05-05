/*
  Liblts546awc.ino

  Example arduino skectch for library liblts546awc
  
  The library controls one digit element LED
  Type common anode
  Model LTS-546AWC but pins are easily adaptable to layout
  Turns on and off a light emitting diode(LED) connected to digital pin
  Layout is with 3 or 8 common anode

  The circuit:
  - Common anode 3 (+5V)
  - Resistor 220Ohm for every led input
  - Arduino pins from 2 (A) to 8 (G) and 9 = DP (decimal point)
  - Displays segments snd numbers in direct and reverse order

  created april 2019
  by Riccardo G Corsi
  last modified 27 apr 2019

  This example code is in the public domain.

*/

include "liblts546awc.h"
LTS546AWC ledModule = LTS546AWC();


void setup() {
   ledModule.begin();
  // initialize LED pin HIGH to turn off
   ledModule.clearAll();
}

void loop() {
    ledModule.diag();     
    ledModule.clearAll();
    count();
    ledModule.clearAll();
    reverse();   
    delay(2*digitDelay);           
}


void count() {
  for (int i = 0; i < 10; i++) {
    ledModule.setDigit(i);
    delay(digitDelay);
  }             
}

void reverse() {
  for (int i = 9; i >= 0; i--) {
    ledModule.setDigit(i);
    delay(digitDelay);
  }             
}

