/* 
 
 Xbox One - Steering wheel controller hack
 
 2014 - Tino Soelberg
 
 */

// -------------------------------------------------------------------------

#include <Wire.h>                 // Library for i2c communication

// -------------------------------------------------------------------------



// CONSTANTS AND VARS FOR CONTROL OF THE APPLICATION
char      appVersion[5] = "0.02";
int       minValx = 400; // Calibration for the accelerometer
int       maxValx = 620; // Calibration for the accelerometer
int       minValy = 400; // Calibration for the accelerometer
int       maxValy = 610; // Calibration for the accelerometer
const int overallDelay = 0;      // Speeding down things for debug
int       wheelAngleOffset = 20; // Calibration for the accelerometer
int       turnEffectLevel = 80;
int       startScreenDelay = 1000;

// CONSTANTS FOR BORING THINGS LIKE PIN ASSIGNMENTS
const int buttonInput1 = 4;      // input pin for pushbutton
const int buttonInput2 = 5;      // input pin for pushbutton
const int xPin = 0;
const int yPin = 1;
const int DAC_I2C_address = 0x4C;  // I2C write address 
const int ledLatchPin = 8;  //Pin connected to ST_CP of 74HC595
const int ledClockPin = 12; //Pin connected to SH_CP of 74HC595
const int ledDataPin = 11;  //Pin connected to DS of 74HC595

// VARIABLE INIT
int previousButtonState1 = LOW;   // for checking the state of a pushButton
int previousButtonState2 = LOW;   // for checking the state of a pushButton
double wheelAngle; //
int DACval;
byte ledArray = 0;




// -------------------------------------------------------------------------

void setup() { // setup routine - is run once, before the loop() kicks off
  
  
  pinMode(buttonInput1, INPUT);  // make the pushButton pins inputs
  pinMode(buttonInput2, INPUT);  // make the pushButton pins inputs
  
  //set pins to output so you can control the shift register
  pinMode(ledLatchPin, OUTPUT);
  pinMode(ledClockPin, OUTPUT);
  pinMode(ledDataPin, OUTPUT);
  
  Wire.begin();	      // initialize i2c communication

  displayLedStartSequence();

}

// -------------------------------------------------------------------------

// MAIN LOOP ROUTINE
void loop() {

  getWheelAngle();

  wheelAngle = wheelAngle + wheelAngleOffset;





  if ( button1IsPressed() ) {
    turnEffectLevel = turnEffectLevel - 10;
    if (turnEffectLevel < 0) { 
        turnEffectLevel = 0;
    }    
  }

  if ( button2IsPressed() ) {
    turnEffectLevel = turnEffectLevel + 10;
    if (turnEffectLevel > 360) { 
        turnEffectLevel = 360;
    }    
  }


    
  wheelAngle = map(constrain(wheelAngle, 0 + turnEffectLevel,360 - turnEffectLevel), 0 + turnEffectLevel, 360 - turnEffectLevel,0,360);
  
  DACval = (map(wheelAngle,0,360,0,255))/(3.3/1.7);  // Get DAC data from user 
  
  setDAC(DACval);
  
//  Serial.print("Angle: ");
//  Serial.print(wheelAngle);
//  Serial.print(" | DACVal: ");
//  Serial.print(DACval);
    
  delay(overallDelay);

}

// -------------------------------------------------------------------------






