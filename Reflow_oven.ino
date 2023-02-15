
#pragma once
//#include <EEPROM.h>
#include <stdlib.h>
#include <string.h>
#include "Display.h"
#include "InputOutput.h"
#include "Thermals.h"


#define but_plus 12
#define but_min 11
#define but_menu 10 
#define but_exit 9
#define SSR 13
//3
#define buzzer 6
#define Thermistor_PIN A0

#define MAXTEMP 270

struct GraphPoints {
  int Temperature;// temperature in devrees celsius
  int timeStamp;//time in seconds
  };


int tempC = 0;
bool buttonstate[4];
unsigned long millisPrevious;
uint8_t CurrentMenu = 0;
bool PWM_OUT = 0;


int lastButtonStateFalling;
int lastButtonStateFalling2;
int lastButtonStateFalling3;
int lastButtonStateFalling4;
//char temperature[5];
int Selectcounter =0;

void setup() {
  // put your setup code here, to run once:

initializeInput(but_plus,but_min,but_menu,but_exit,SSR,buzzer,Thermistor_PIN);
//initializePID();
initializeDisplay();

struct GraphPoints Lead_Paste[4];

Lead_Paste[0] = {150/*temp*/,90/*time*/};
Lead_Paste[1] = {180, 180};
Lead_Paste[2] = {245, 225};
Lead_Paste[3] = {245, 255};

}

void loop() {
  // put your main code here, to run repeatedly:
  DisplayMenu(CurrentMenu, tempC, Selectcounter); 
  tempC = GetTemperatureCelsius(Thermistor_PIN);
  
  if(millis()>= (millisPrevious+3000)){
  if(PWM_OUT){
    digitalWrite(SSR, HIGH);
  }else {
    digitalWrite(SSR, LOW);
  }
  millisPrevious = millis();        
  }



  if(CheckInput(but_menu,&lastButtonStateFalling3)){//checks menu button
  switch (CurrentMenu){ //check what menu we are in
  case 0:
  CurrentMenu=1;
  break;
  
  default:
  break;

  }
  
  ClearDisplay();
  Selectcounter =0;
  }
  if(digitalRead(but_exit)==0){ //check button
    PWM_OUT = 200;
  }else{
    PWM_OUT = 0;
  }
  if(CheckInput(but_plus,&lastButtonStateFalling)){ //check button
  Selectcounter +=10;
  }
  if(CheckInput(but_min,&lastButtonStateFalling2)){ //check button
  Selectcounter -=10;
  }


//RunPIDCalc();

//delay(100);


//DoOutput();
}
