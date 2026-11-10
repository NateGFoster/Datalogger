#include <Arduino.h>
#include "record.h" //I use "" because it's my file and not a library
// Blink code to confirm teensy is working To be deleted 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   // pin 13, the orange LED
  Serial.begin(115200);
 uint32_t start =millis(); //time when we strat waiting

    do{
    // just waiting 
    } while (millis() - start < 3000  && !Serial); // so the teensy will wait 3 seconds and if it isn't connected to the serial then it will put out a false
    
    Serial.println("Logger booting");//if we get the all clear and it connects to the serial monitor then print this 
    sizeof(Record); //this is just to make sure that the struct is the right size, it should be 28 bytes, if it isn't then something is wrong with the struct and we need to fix it
  }

void loop() {
  //checks for the serial monitor on the computer 
  static uint32_t count = 0; //static is nessesary to keep the count accurate, it tells the loop to skip the initialization of that line after the first time
  static bool ledOn = false; // LED starts off 

  ledOn = !ledOn; // toggle the LED state
  digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW); // turn the LED on or off based on the ledOn variable
  Serial.println(count);// print the count to the serial monitor
  count++;
  
  delay(1000); // wait 1 second
}

