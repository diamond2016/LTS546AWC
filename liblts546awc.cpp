/*
  Liblts546awc

  Controls one digit element LED
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

#include "liblts546awc.h"


// default constructor 
LTS546AWC::LTS546AWC(void){}

// init the chip
void LTS546AWC::begin()
{ 
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinDP, OUTPUT);
                
  // initialize LED pin HIGH to turn off
  clearAll();
}

void LTS546AWC::clearAll() {
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, HIGH);
  digitalWrite(ledPinC, HIGH);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, HIGH);
  digitalWrite(ledPinDP, HIGH);
}

void LTS546AWC::diag() {
  clearAll();
  setSegment('A');
  delay(digitDelay);
  clearSegment('A');
  setSegment('B');
  delay(digitDelay);
  clearSegment('B');
  setSegment('C');
  delay(digitDelay);
  clearSegment('C');
  setSegment('D');
  delay(digitDelay);
  clearSegment('D');
  setSegment('E');
  delay(digitDelay);
  clearSegment('E');
  setSegment('F');
  delay(digitDelay);
  clearSegment('F');
  setSegment('G');
  delay(digitDelay);
  clearSegment('G');
  setSegment('.');
  delay(digitDelay);
  clearSegment('.'); 
  delay(digitDelay);             
}

void LTS546AWC::setDigit(int n) {
  clearAll();
  switch (n) {
    case 0:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case 1:
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;    
     case 2:
      setSegment('A');
      setSegment('B');
      clearSegment('C');
      setSegment('D');
      setSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
     case 3:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 4:
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;   
     case 5:
      setSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 6:
      clearSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
     case 7:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;      
     case 8:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 9:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;                                   
    default:
      break;
  }
} // setDigit

// in order to use single segment remember to clearAll
void LTS546AWC::setSegment(char s) {
  switch (s) {
    case 'A':
      digitalWrite(ledPinA, LOW);
      break;  
    case 'B':
      digitalWrite(ledPinB, LOW);
      break;
    case 'C':
      digitalWrite(ledPinC, LOW);
      break;
    case 'D':
      digitalWrite(ledPinD, LOW);
      break;
    case 'E':
      digitalWrite(ledPinE, LOW);
      break;
    case 'F':
      digitalWrite(ledPinF, LOW);
      break;
    case 'G':
      digitalWrite(ledPinG, LOW);
      break;                                          
    case '.':
      digitalWrite(ledPinDP, LOW);
      break; 
    default:
      break;
    }
  } // setSegment

// in order to use single segment remember to clearAll
void LTS546AWC::clearSegment(char s) {
  switch (s) {
    case 'A':
      digitalWrite(ledPinA, HIGH);
      break;  
    case 'B':
      digitalWrite(ledPinB, HIGH);
      break;
    case 'C':
      digitalWrite(ledPinC, HIGH);
      break;
    case 'D':
      digitalWrite(ledPinD, HIGH);
      break;
    case 'E':
      digitalWrite(ledPinE, HIGH);
      break;
    case 'F':
      digitalWrite(ledPinF, HIGH);
      break;
    case 'G':
      digitalWrite(ledPinG, HIGH);
      break;                                          
    case '.':
      digitalWrite(ledPinDP, HIGH);
      break; 
    default:
      break;
    }
} // clearSegment

