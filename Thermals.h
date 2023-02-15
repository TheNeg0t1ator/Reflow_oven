
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



float CalculateGraphpoint(struct GraphPoints Solder[5], int TimeInterval){
float Setpoint =0;
float YOffset =0;
int deltaTemp=0;
int deltaTime=0;
float slope =0;

if(TimeInterval>=Solder[4].timeStamp){
    Setpoint = 0;
}else{

for(int i =0; i <=4; i++){

    if((Solder[i].timeStamp<= TimeInterval) && (Solder[i+1].timeStamp>= TimeInterval)){

    deltaTime = Solder[i+1].timeStamp - Solder[i].timeStamp;
    deltaTemp = Solder[i+1].Temperature - Solder[i].Temperature;
    slope = (float)deltaTemp/deltaTime;
    //b = Ax-y
    YOffset = ((slope*Solder[i].timeStamp)-Solder[i].Temperature);
    Setpoint = (float)(slope*TimeInterval+YOffset);

    break;
    }
  }
}

return Setpoint;
}


