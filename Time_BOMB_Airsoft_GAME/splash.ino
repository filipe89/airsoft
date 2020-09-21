
void explodeSplash(){
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(1,0);
  lcd.print(TWIN);
  lcd.setCursor(4,1);
  lcd.print(GAME_OVER );
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(5000);
  cls();

  //end code
  lcd.print(PAGAIN);
  lcd.setCursor(0,1);
  lcd.print(option);
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();

      break;
    }  
  } 
}
void failSplash(){
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(1,0);
  lcd.print(TOUT);
  lcd.setCursor(4,1);
  lcd.print(GAME_OVER);
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(5000);
  cls();

  //end code
  lcd.print(PAGAIN);
  lcd.setCursor(0,1);
  lcd.print(option);
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();

      break;
    }  
  } 
}
void disarmedSplash(){
  endGame = false;
  digitalWrite(REDLED, LOW); 
  digitalWrite(GREENLED, LOW);
  if(sdStatus || saStatus){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print(DISARM);
    lcd.setCursor(3,1);
    lcd.print(DEFENDERS_WIN);
    digitalWrite(GREENLED, HIGH);  
    delay(5000);
    digitalWrite(GREENLED, LOW); 
  }
  //end code
  lcd.clear();
  lcd.print(PAGAIN);
  lcd.setCursor(0,1);
  lcd.print(option);
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();
      break;
    }  
  } 
}
