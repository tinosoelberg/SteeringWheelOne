// MODE 1 - Sensitivity correction
void mode1Selected(){

  if (newModeSelected){

    for (int i=0; i < 3; i++){
      
    int ledArray = 0;
    updateLeds(ledArray);
    
    bitSet(ledArray, 1);
    updateLeds(ledArray);

    delay(50); 
    }
  }


  if ( button1IsPressed() ) {
    turnEffectLevel = turnEffectLevel - 10;
    if (turnEffectLevel < 60) { 
        turnEffectLevel = 60;
    }    
    int ledArray = 0;
    updateLeds(ledArray);
    bitSet(ledArray, map(turnEffectLevel,60,110,0,4));
    updateLeds(ledArray);

  }

  if ( button2IsPressed() ) {
    turnEffectLevel = turnEffectLevel + 10;
    if (turnEffectLevel > 110) { 
        turnEffectLevel = 110;
    }    
    int ledArray = 0;
    updateLeds(ledArray);
    bitSet(ledArray, map(turnEffectLevel,60,110,0,4));
    updateLeds(ledArray);
  }

  
}



// MODE 2 - Angle calibration
void mode2Selected(){

  if (newModeSelected){

    for (int i=0; i < 3; i++){
      
    int ledArray = 0;
    updateLeds(ledArray);
    
    bitSet(ledArray, 2);
    updateLeds(ledArray);

    delay(50); 
    }
  }


  if ( button1IsPressed() ) {
    wheelAngleOffset = wheelAngleOffset - 5;
    if (wheelAngleOffset < 10) { 
        wheelAngleOffset = 10;
    }    
    int ledArray = 0;
    updateLeds(ledArray);
    bitSet(ledArray, map(wheelAngleOffset,10,30,0,4));
    updateLeds(ledArray);
  }

  if ( button2IsPressed() ) {
    wheelAngleOffset = wheelAngleOffset + 10;
    if (wheelAngleOffset > 30) { 
        wheelAngleOffset = 30;
    }    
    int ledArray = 0;
    updateLeds(ledArray);
    bitSet(ledArray, map(wheelAngleOffset,10,30,0,4));
    updateLeds(ledArray);
  }

  
}




void modeSelect(){
  newModeSelected = false;

  // read the pushbutton:
  int buttonState3 = digitalRead(buttonInput3);
  // if the button state has changed, 
  if ((buttonState3 != previousButtonState3) 
  // and it's currently pressed:
  && (buttonState3 == HIGH)) {
    // increment the button counter

    newModeSelected = true;
    modeSelected++;

    if (modeSelected == 3) { 
        modeSelected = 1;
    } 
    // type out a message
  }
  // save the current button state for comparison next time:
  previousButtonState3 = buttonState3; 
 
}




void  displayLedStartSequence() {

    byte ledArray;
  
    bitSet(ledArray, 0);
    bitSet(ledArray, 4);
    updateLeds(ledArray);

    delay(50);
    
    ledArray = 0;
    updateLeds(ledArray);
    
    bitSet(ledArray, 1);
    bitSet(ledArray, 3);
    updateLeds(ledArray);

    delay(50);
    
    ledArray = 0;
    updateLeds(ledArray);
    
    bitSet(ledArray, 2);
    updateLeds(ledArray);
 
    delay(50);

    ledArray = 0;
    updateLeds(ledArray);
  
}





