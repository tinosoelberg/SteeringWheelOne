
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





