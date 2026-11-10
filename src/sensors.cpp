/* Sensors implementation file does the math for simulated sensors  */

#include <Arduino.h>   // millis(), random(), PI
#include <math.h>      // sinf(), fmodf()
#include "sensors.h"


void readSensors(Record *out) {
    // Pressure sensor simulation
    float t = millis() / 1000.0f; // time in seconds since boot

    // 847 + 0.5 * a wave that oscillates between -1 and 1, so the pressure oscillates between 846.5 and 847.5 hPa
    out->pressure_hPa = 847.0f + 0.5f * sinf(t * 2.0f * PI / 60.0f); // 1 minute period

    // Temperature sensor simulation
    out->temperature_C = 22.0f + 5.0f * sinf(t * 2.0f * PI / 3600.0f); // 1 hour period

    // Heading sensor simulation
    out->heading_degrees = fmodf(t * 10.0f, 360.0f); // rotates at 10 degrees per second, fmodf is the decimal version of %

    // Tilt sensor simulation
    out->tilt_degrees = 5.0f * sinf(t * 2.0f * PI / 120.0f); // 2 minute period

    // Speed sensor simulation
    out->speed_mps = 1.0f + 0.5f * sinf(t * 2.0f * PI / 30.0f); // 30 second period
}

