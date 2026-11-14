/* Sensors implementation file does the math for simulated sensors  */

#include <Arduino.h>   // millis(), random(), PI
#include <math.h>      // sinf(), fmodf()
#include "sensors.h"


void readSensors(Record *out) {
    // Pressure sensor simulation
    float t = millis() / 1000.0f; // time in seconds since boot

    /*syntax notes: -> means go to the struct this pointer points to which is defined in record.h
    we use -> instead of 
    Record sensor;
    Record *out = &sensor;
    sensor.speed_mps = 1.3f;
    out->speed_mps = 1.3f; 
    */

    // 847 + 0.5 * a wave that oscillates between -1 and 1, so the pressure oscillates between 846.5 and 847.5 hPa
    out->pressure_hPa = 847.0f + 0.5f * sinf(t * 2.0f * PI / 60.0f); // 1 minute period

    // Temperature sensor simulation
    out->temperature_C = 22.0f + 5.0f * sinf(t * 2.0f * PI / 3600.0f) + random(-50,51) / 100.0f; // 22 C center, +/-5 C drift over 1 hour, +/-0.5 C noise

    // Heading sensor simulation
    out->heading_degrees = fmodf(t * 10.0f, 360.0f); // rotates at 10 degrees per second, fmodf is the decimal version of %

    // Tilt sensor simulation
    out->tilt_degrees = random(-50,51) / 100.0f; // random simlulated tilt between -0.5 and 0.5 degrees

    // Speed sensor simulation
    float cycle = fmodf(t, 30.0f); // 30 second cycle
    if (cycle < 20.0f){
        out->speed_mps = 1.3f; //going 1.3 m/s for 20 seconds
    }
    else{
        out->speed_mps = 0.0f; //stopped for 10 seconds after that 20 seconds 
    }
}

