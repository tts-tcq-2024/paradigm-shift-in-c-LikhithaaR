#include <stdio.h>
#include <assert.h>




int temperature_limit_chek(float temp){
float min_temperature = 0;
float max_temperature = 45; 
  if((temp < min_temperature)) || (temp > max_temperature))
    {
    printf("Temperature out of range!\n");
    }
  return 0;
}


int soc_limit_chek(float SOC){
float min_SOC = 20;
float max_SOC = 80; 
  if((SOC < min_SOC)) || (SOC > max_SOC))
    {
    printf("SOC out of range!\n");
    }
  return 0;
}


int chargeRate_limit_chek(float ChargeRate){
float max_ChargeRate = 0.8;
 
  if((ChargeRate > max_ChargeRate)) 
    {
    printf("ChargeRate out of range!\n");
    }
  return 0;
}


int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(temperature_limit_chek()) 
  {
   return 0;
  } 
  else if(soc_limit_chek()) 
  {
    return 0;
  } 
  else if(chargeRate_limit_chek()) 
  {
    return 0;
  }
  return 1;
}
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
