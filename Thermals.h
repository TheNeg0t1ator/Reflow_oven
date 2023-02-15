
#pragma once
#include <thermistor.h> 


int GetTemperatureCelsius(int pin){
thermistor therm1(pin,0);
return therm1.analog2temp();

}



float CalculateGraphpoint(struct GraphPoints Solder[4], int TimeInterval){
float Setpoint =0;
float YOffset =0;
int deltaTemp=0;
int deltaTime=0;

for(int i =0; i <=3; i++){
if(Solder[i].timeStamp<= TimeInterval){
deltaTime = Solder[i+1].timeStamp - Solder[i].timeStamp;
deltaTemp = Solder[i+1].Temperature - Solder[i].Temperature;
YOffset =  

Setpoint = (float)((deltaTemp/deltaTime)*TimeInterval);
break;
}
}


return Setpoint;
}