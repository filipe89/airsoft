#include <EEPROM.h>


void getConfig(){

//Check first time 

//if (EEPROM.read(0)!= 0)
{
//write default config values

GAMEMINUTES= ((EEPROM.read(0)*600)+(EEPROM.read(1)*60)+(EEPROM.read(2)*10)+(EEPROM.read(3)));
      for (int l=0; l<4; l++)  
        Serial.println(EEPROM.read(l));
BOMBMINUTES= ((EEPROM.read(4)*10)+EEPROM.read(5));
ACTIVATESECONDS= ((EEPROM.read(6)*10)+EEPROM.read(7));
soundEnable = EEPROM.read(8);
relayEnable = EEPROM.read(9);
passwordEnable = EEPROM.read(10);

 for(int i=0;i<8;i++){
      password[i]=EEPROM.read(11+i); //add 11 - 19
    }

 for(int i=0;i<4;i++){
      nuidPICC[i]=EEPROM.read(20+i); //add 11 - 19
    }
FUSEEnable = EEPROM.read(30);
}
  
//RELAY_TIME = EEPROM.read(1) * 1000 ;

  
}

void save(int modo){

  if (modo == 1){ //time game
      EEPROM.write(0, time[0]);
      EEPROM.write(1, time[1]);
      EEPROM.write(2, time[2]);
      EEPROM.write(3, time[3]);
      Serial.println("\n gravou:");
      for (int l=0; l<4; l++)  
        Serial.println(EEPROM.read(l));
  }
  if (modo == 2) // time  bomb
  {
      EEPROM.write(4, time[0]);
      EEPROM.write(5, time[1]);
  }

  if (modo == 3) //activating time
  {
     EEPROM.write(6, time[0]);
     EEPROM.write(7, time[1]);
  }
  if (modo == 4)
  
    EEPROM.write(8, soundEnable); 
  
  if (modo == 5)
     EEPROM.write(9,relayEnable);
     
  if (modo == 6)   
     EEPROM.write(10,passwordEnable);

  if (modo == 7)
    for(int i=0;i<8;i++){
      EEPROM.write(11+i, password[i]);
    }

  if (modo == 10)
    for(int i=0;i<4;i++){
      EEPROM.write(20+i, nuidPICC[i]);
    }
    
//  if (modo == 11)
//    for(int i=0;i<4;i++){
//      EEPROM.write(24+i, password[i]);
//    }
  if (modo == 11)
    EEPROM.write(30,FUSEEnable);
    
}
