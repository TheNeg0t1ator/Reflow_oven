#pragma once
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
#define buzzer 6
#define Thermistor_PIN A0
#define MAXTEMP 270



GraphPoints Lead_Paste[] = {
  {0, 0},
  {150, 90},
  {180, 180},
  {245, 225},
  {245, 255}
};

int tempC = 0;
bool buttonstate[4];
uint64_t millisPrevious;
uint64_t millisStart;
uint64_t millisGraph;

uint8_t CurrentMenu = 0;
bool PWM_OUT = 0;
bool OutputLoop = 0;
uint16_t setpoint = 0;

int lastButtonStateFalling;
int lastButtonStateFalling2;
int lastButtonStateFalling3;
int lastButtonStateFalling4;

int Selectcounter = 0;

void setup() {
  initializeInput(but_plus, but_min, but_menu, but_exit, SSR, buzzer, Thermistor_PIN);
  initializeDisplay();
}

void loop() {
  
  millisGraph = millis() - millisStart;

  switch (CurrentMenu){
    case 0:
      DisplayMenu(CurrentMenu, tempC, Selectcounter); 
      break;
    case 1:
      DisplayMenu(CurrentMenu, tempC, Selectcounter); 
      break;
    case 3:
      DisplayMenu(CurrentMenu, setpoint, millisGraph); 
      OutputLoop = 1;
      break;
      default:
      OutputLoop = 0;
      break;
  }

  
  

  if(millis() >= (millisPrevious + 1000)){
    tempC = GetTemperatureCelsius(Thermistor_PIN);
    setpoint = CalculateGraphpoint(Lead_Paste, 50, sizeof(Lead_Paste) / sizeof(struct GraphPoints));
    if(PWM_OUT){
      digitalWrite(SSR, HIGH);
    } else {
      digitalWrite(SSR, LOW);
    }
    
    if (OutputLoop)
  {
    if (setpoint > tempC )
    {
      PWM_OUT = 1;
    }else{
      PWM_OUT = 0;
    }
    
  }
    millisPrevious = millis();        
  }

  if(CheckInput(but_menu, &lastButtonStateFalling3)){
    switch (CurrentMenu){
      case 0:
        CurrentMenu = 1;
        break;
      default:
        break;
    }
  
    ClearDisplay();
    Selectcounter = 0;
  }

  if(digitalRead(but_exit) == 0){
    switch (CurrentMenu){
      case 0:
        CurrentMenu = 3;
        millisStart = millis();
        break;
      default:
        break;
    }
    ClearDisplay();
    Selectcounter = 0;
  }
    if(CheckInput(but_plus, &lastButtonStateFalling)){
      Selectcounter += 10;
    }

    if(CheckInput(but_min, &lastButtonStateFalling2)){
      Selectcounter -= 10;
    }
  

  //DoOutput();

}
