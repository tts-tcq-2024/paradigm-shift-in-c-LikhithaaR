#include <stdio.h>

#include <assert.h>
 
typedef enum {
    BATTERY_OK,
    TEMPERATURE_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGERATE_OUT_OF_RANGE
} BatteryStatus;
 

BatteryStatus checkTemperature(float temperature) {

  if(temperature < 0 || temperature > 45){
        return TEMPERATURE_OUT_OF_RANGE;
    }
    return BATTERY_OK;
}
 
BatteryStatus checkSOC(float soc) {

    if (soc < 20 || soc > 80){
      return SOC_OUT_OF_RANGE;
    }
    return BATTERY_OK;
}
 
BatteryStatus checkChargeRate(float chargeRate) {

    if (chargeRate > 0.8) {
      return CHARGERATE_OUT_OF_RANGE;
    }
    return BATTERY_OK;

}
 
BatteryStatus batteryIsOk(float temperature, float soc, float chargeRate) {

    BatteryStatus status;
 
    status = checkTemperature(temperature);

    if (status != BATTERY_OK) return status;
 
    status = checkSOC(soc);

    if (status != BATTERY_OK) return status;
 
    status = checkChargeRate(chargeRate);

    return status;

}
 
// Function to print error message based on BatteryStatus

void printErrorMessage(BatteryStatus status) {

    switch (status) {

        case TEMPERATURE_OUT_OF_RANGE:
            printf("Temperature out of range!\n");
            break;

        case SOC_OUT_OF_RANGE:
            printf("State of Charge is out of range!\n");
            break;

        case CHARGERATE_OUT_OF_RANGE:
            printf("Charge Rate is out of range!\n");
            break;
        case BATTERY_OK:

        default:

            break;

    }

}
 
int main() {

    BatteryStatus status;

    status = batteryIsOk(25, 70, 0.7); 
    status = batteryIsOk(50, 70, 0.7);
    printErrorMessage(status);

    return 0;

}

 
