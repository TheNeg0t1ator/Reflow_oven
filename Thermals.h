
#pragma once
#include <thermistor.h> 


int GetTemperatureCelsius(int pin){
thermistor therm1(pin,0);
return therm1.analog2temp();

}

float CalculateGraphpoint(void){// put struct in here
float Setpoint =0;



return Setpoint;
}