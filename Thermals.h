
#pragma once
#include <thermistor.h> 

struct GraphPoints {
  int Temperature; // temperature in degrees Celsius
  int timeStamp;   // time in seconds
};

extern GraphPoints Lead_Paste[];

int GetTemperatureCelsius(int pin){
thermistor therm1(pin,0);
return therm1.analog2temp();

}



float CalculateGraphpoint(struct GraphPoints Solder[], int TimeInterval, int ArraySize){
ArraySize--;
float Setpoint =0;
float YOffset =0;
int deltaTemp=0;
int deltaTime=0;
float slope =0;

if(TimeInterval>=Solder[ArraySize].timeStamp){
    Setpoint = 0;
}else{

for(int i =0; i <=ArraySize; i++){

    if((Solder[i].timeStamp<= TimeInterval) && (Solder[i+1].timeStamp>= TimeInterval)){

    deltaTime = Solder[i+1].timeStamp - Solder[i].timeStamp;
    deltaTemp = Solder[i+1].Temperature - Solder[i].Temperature;
    slope = (float)deltaTemp/deltaTime;
    //b = Ax-y
    YOffset = (Solder[i].Temperature - (slope*Solder[i].timeStamp));
    //YOffset*=(-1);
    Setpoint = (float)(slope*TimeInterval+YOffset);

    break;
    }
  }
}

return Setpoint;
}


