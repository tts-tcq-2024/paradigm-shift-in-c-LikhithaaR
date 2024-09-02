#include <stdio.h>
#include <assert.h>

#define TEMPERATURE_ERROR "Temperature is out of range!"  
#define SOC_ERROR "State of Charge is out of range!"
#define CHARGE_RATE_ERROR "Charge Rate is out of range!"

int CheckAndPrintValue(float value, float min_value, float max_value, const char* errormessage) {
    if (value < min_value || value > max_value) {
        printf("%s", errormessage);
        return 0;
    }
    return 1;
}

int BatteryIsOk(float temperature, float soc, float chargeRate) {
    int isTemperatureOk = CheckAndPrintValue(temperature, 0, 45, TEMPERATURE_ERROR);
    int isSocOk = CheckAndPrintValue(soc, 20, 80, SOC_ERROR);
    int isChargeRateOk = CheckAndPrintValue(chargeRate, 0, 0.8, CHARGE_RATE_ERROR);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}

int main() {
    assert(BatteryIsOk(25, 70, 0.7));
    assert(!BatteryIsOk(50, 85, 0));
    
    assert(BatteryIsOk(1, 30, 0.1));     
    assert(BatteryIsOk(44, 70, 0.7));    
   
    assert(!BatteryIsOk(-5, 75, 0.6));   // Temperature below range
    assert(!BatteryIsOk(44, 55, 0.9));   // Temperature above range
    
    assert(!BatteryIsOk(23, 15, 0.7));   // SOC below range
    assert(!BatteryIsOk(20, 86, 0.7));   // SOC above range
    // Test cases for invalid charge rate
    assert(!BatteryIsOk(25, 70, 0.9));   // Charge rate above range

}

