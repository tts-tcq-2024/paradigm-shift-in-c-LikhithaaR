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

int BatteryIsOkk(float temperature, float soc, float chargeRate) {
    int isTemperatureOk = CheckAndPrintValue(temperature, 0, 45, TEMPERATURE_ERROR);
    int isSocOk = CheckAndPrintValue(soc, 20, 80, SOC_ERROR);
    int isChargeRateOk = CheckAndPrintValue(chargeRate, 0, 0.8, CHARGE_RATE_ERROR);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}

int main() {
    assert(BatteryIsOkk(25, 70, 0.7));
    assert(!BatteryIsOkk(50, 85, 0));
    
    assert(BatteryIsOkk(1, 30, 0.1));     
    assert(BatteryIsOkk(44, 70, 0.7));    
   
    assert(!BatteryIsOkk(-5, 75, 0.6));   // Temperature below range
    assert(!BatteryIsOkk(44, 55, 0.9));   // Temperature above range
    
    assert(!BatteryIsOkk(23, 15, 0.7));   // SOC below range
    assert(!BatteryIsOkk(20, 86, 0.7));   // SOC above range
    // Test cases for invalid charge rate
    assert(!BatteryIsOkk(25, 70, 0.9));   // Charge rate above range

}

