void drawBar(byte porcent){
  //TODO: Optimize this code 
  int box=(8*porcent)/10;
  lcd.setCursor(0,1);
  while(box>=5){
    if(box>=5)
    {
      lcd.write(4);
      box-=5;
    }
  }
    switch(box){
    case 0:
      break;
    case 1:
      lcd.write((uint8_t)0);
      break;
    case 2:
      lcd.write(1);
      break;
    case 3:
      lcd.write(2);
      break;
    case 4:
      lcd.write(3);
      break;
    }
  

}
void cls(){
  lcd.clear();
  lcd.setCursor(0,0);
}

void printTime(unsigned long minutos, unsigned long aTiempo){

  timeCalcVar=minutos-aTiempo/60000;
  //Hours
  
  if(timeCalcVar/60==0 && refresh){
      lcd.clear();
      refresh=false;
      //delay(100);
      lcd.setCursor(3,1);
      Serial.println("!!!!");
  }
   
  if(timeCalcVar/60>=1){
    
    if(timeCalcVar/60<10)
  {
    lcd.setCursor(2,1);
    lcd.print("0");
    lcd.print(timeCalcVar/60);
  }
  else
  {
    lcd.print(timeCalcVar/60);
  }
  
  lcd.print(":");
  
  }
  //minutes
  if(timeCalcVar%60<10)
  {
    lcd.print("0");
    lcd.print(timeCalcVar%60);
  }
  else
  {
    lcd.print(timeCalcVar%60);
  }
  lcd.print(":");
  //seconds
  timeCalcVar=aTiempo/1000;
  if(59-(timeCalcVar%60)<10)
  {
    lcd.print("0");
    lcd.print(59-(timeCalcVar%60));
  }
  else
  {
    lcd.print(59-(timeCalcVar%60));
  }
  lcd.print(":");
  //this not mach with real time, is just a effect, it says 999 because millis%1000 sometimes give 0 LOL
  lcd.print(999-(millis()%1000));
}

void printTimeDom(unsigned long aTiempo, boolean showMillis){
  //minutes
  if((aTiempo/60000)<10)
  {
    lcd.print("0");
    lcd.print(aTiempo/60000);
  }
  else
  {
    lcd.print(aTiempo/60000);
  }
  lcd.print(":");
  //seconds
  if(((aTiempo/1000)%60)<10)
  {
    lcd.print("0");
    lcd.print((aTiempo/1000)%60);
  }
  else
  {
    lcd.print((aTiempo/1000)%60);
  }
  if(showMillis){
    lcd.print(":");
    //this not mach with real time, is just a effect, it says 999 because millis%1000 sometimes give 0 LOL
      lcd.print(999-millis()%1000);

  }
}

void startGameCount(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print(RBEGIN);
  lcd.setCursor(0,1);
  lcd.print(PBUTTON);
  keypad.waitForKey();//if you press a button game start

  cls();
  lcd.setCursor(1,0);
  lcd.print(STGAME);
  for(int i = 5; i > 0 ; i--){ // START COUNT GAME INIT
    lcd.setCursor(5,1);
    tone(tonepin,2000,100);
    lcd.print(EM);
    lcd.print(i);
    delay(1000);
  }
  cls();
}

void checkArrows(byte i,byte maxx ){

  if(i==0){
    lcd.setCursor(15,1);
    lcd.write(6); 
  }
  if(i==maxx){  
    lcd.setCursor(15,0);
    lcd.write(5);
  }
  if(i>0 && i<maxx){
    lcd.setCursor(15,1);
    lcd.write(6);
    lcd.setCursor(15,0);
    lcd.write(5);  
  }
}

void activateRelay(){

  digitalWrite(RELAYPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(RELAY_TIME); 
  digitalWrite(RELAYPIN, LOW);

}

boolean ogivas ()
{
  
  lcd.setCursor(0,1);
  lcd.print("          ");
//     Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent()){
//    Serial.println("There is no new card");

    return false;
  }

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial()){
//    Serial.println("READ IRFD");
    lcd.setCursor(4,1);
    lcd.print(WTOGIVA);
    return;
  }
  
    if (rfid.uid.uidByte[0] == nuidPICC[0] || rfid.uid.uidByte[1] == nuidPICC[1] || rfid.uid.uidByte[2] == nuidPICC[2] || rfid.uid.uidByte[3] == nuidPICC[3] ) {
//      Serial.println("RFID COINCIDE");
      lcd.setCursor(0,1);
      printHex(rfid.uid.uidByte, rfid.uid.size);
      rfid.PICC_HaltA();
      // Stop encryption on PCD
      rfid.PCD_StopCrypto1();
      return true;
    }

    else{
//      Serial.println("RFID fora");
      lcd.setCursor(3,1);
      lcd.print(WTOGIVA);
      delay(2000);
      // Halt PICC
      rfid.PICC_HaltA();
      // Stop encryption on PCD
      rfid.PCD_StopCrypto1();
      return false;
  }
}

void printHex(byte *buffer, byte bufferSize) {
  lcd.clear();
  lcd.setCursor(0,1);
  for (byte i = 0; i < bufferSize; i++) {
    lcd.print(buffer[i] < 0x10 ? " 0" : " ");
    lcd.print(buffer[i], HEX);
  }
}
