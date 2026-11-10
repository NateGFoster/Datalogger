/* Record file for handling data logging */
#pragma once // this is a header guard so that I can include this file in multiple other files without getting errors about redefinition of the struct
#include <stdint.h>
struct Record {
    uint32_t sample_number;//this is insurance that the data wasn't lost, it basically just counts the number of samples taken, if the sample number is not sequential then we know that data was lost
    uint32_t time_ms;//I used an unsigned 32 bit int because time can't be neg 
    float pressure_hPa;
    float temperature_C;
    float heading_degrees;//I used a float because heading can be a decimal value 
    float tilt_degrees;//I used a float because tilt can be a decimal value 
    float speed_mps;//I used a float because speed can be a decimal value 
};