/*  Teensy Touch Read to TouchDesigner 
 *  Mirabelle Jones 
 *  
 *  Instructions for use:
 *  For use with built-in cap touch pins using Teensy LC, 3.2, 3.6
 *  1. Install Teensyduino https://www.pjrc.com/teensy/teensyduino.html
 *  2. Re-start Arduino
 *  3. Plug in your Teensy
 *  4. Select your Teensy model from Tools > Board
 *  5. Upload the following sketch
 *  6. Open Tools > Serial Monitor to see data. Touch the pin!
 *  7. Close Serial Monitor before opening TouchDesigner
 *  Cap touch pins for Teensy: 0, 1, 15, 16, 17, 18, 19, 22, 23
 *  On Teensy 3.6: also pin 29, 30
 */

#define CAP_PIN 0 // Change this number to the pin you wish to use

int delay_time = 100; // Time between readings. Rec. > 100 to avoid TD hiccups.

void setup() {
  Serial.begin(115200); // Teensy defaults to a baudrate of 115200 
}

void loop() {
  int data = touchRead(CAP_PIN);
  Serial.println(data); // The actual formatted data which will be sent to TD
  delay(100); 
}
