
#pragma once
#include <stdlib.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);



void initializeDisplay(void){
 lcd.init();
 lcd.begin(16,2);

}

void DisplayString(int x, int y, char string[]){
  lcd.backlight();
  lcd.setCursor(x,y);
  lcd.print(string);
}

void DisplayInt(int x, int y,int getal){
if(getal<=99 && getal>=0){
lcd.setCursor(x,y);
lcd.print(0);
  x++;
}
lcd.setCursor(x,y);
lcd.print(getal);
}

void ClearDisplay(void){
  lcd.clear();
}

void DisplayMenu(uint8_t MenuNumber, int getal1, int getal2){

switch (MenuNumber){
case 0:
DisplayString(0,0,"Start or Select?");
break;

case 1:
DisplayInt(0,1,getal1);  
DisplayInt(13,1,getal2);
break;

default:
ClearDisplay();
break;
}

}



