void getWheelAngle(){
 
   //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(xRead, minValx, maxValx, -90, 90);
  int yAng = map(yRead, minValy, maxValy, -90, 90);

  //Caculate 360deg values like so: atan2(-yAng, -zAng)
  //atan2 outputs the value of -π to π (radians)
  //We are then converting the radians to degrees
  wheelAngle = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
}


void setDAC(int value){

  int DAT1 = value >> 4;            // Ctrl/MS-Byte (PD1&PD0 = 0) 
  int DAT0 = value << 4;            // LS-Byte
    
  // Setup DAC
  Wire.beginTransmission(DAC_I2C_address);
  Wire.write(DAT1);
  Wire.write(DAT0);
  Wire.endTransmission();  
}



boolean button1IsPressed() {
  boolean state = false;  
  // read the pushbutton:
  int buttonState1 = digitalRead(buttonInput1);
  // if the button state has changed, 
  if ((buttonState1 != previousButtonState1) 
  // and it's currently pressed:
  && (buttonState1 == HIGH)) {
    // then by all means tell the app that its pressed
  state = true;    } 

  // save the current button state for comparison next time:
  previousButtonState1 = buttonState1;
  return state;
};  

boolean button2IsPressed() {
  boolean state = false;  
  // read the pushbutton:
  int buttonState2 = digitalRead(buttonInput2);
  // if the button state has changed, 
  if ((buttonState2 != previousButtonState2) 
  // and it's currently pressed:
  && (buttonState2 == HIGH)) {
    // then by all means tell the app that its pressed
  state = true;    } 

  // save the current button state for comparison next time:
  previousButtonState2 = buttonState2;
  return state;
};  



void updateLeds(byte ledArray)
{
   digitalWrite(ledLatchPin, LOW);
   shiftOut(ledDataPin, ledClockPin, MSBFIRST, ledArray);
   digitalWrite(ledLatchPin, HIGH);
}
