# Lab notes

## Lab 1

### Bugs hit and fixes
- **Upload said SUCCESS but the board didn't change.** The red LED meant the Teensy was sitting in bootloader mode, and PlatformIO was trying to hand the file to the Teensy Loader GUI, which wasn't running. Fixed by adding `upload_protocol = teensy-cli` to `platformio.ini`.
- **Temperature read ~0 °C.** I replaced the whole temperature formula with just the noise term instead of adding the noise to it. Fixed: `center + drift + noise`.

### Part C: where sample number and timestamp get set
`sample_number` and `time_ms` are set by the caller (`loop()`, later the timer callback), not inside `readSensors()`.
Reason: `readSensors()` should only read sensors, so it can be swapped for real sensor code in Labs 4–6 without touching the bookkeeping. The caller is the one that decides *when* a sample is taken (in Part F that's the IntervalTimer), so it should stamp the time and number.
