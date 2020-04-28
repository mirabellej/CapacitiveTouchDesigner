# CapacitiveTouchDesigner
Gets capacitive touch data from Teensy (Arduino) and sends to TouchDesigner over Serial. 
This data is then manipulated using Python scripts to switch between video feeds and edit ramp speed and shape.

For use with Teensy LC, 3.2, or 3.6 (Teensy 3.5 does not have built-in capacitive touch pins).
Cap touch pins for Teensy: 0, 1, 15, 16, 17, 18, 19, 22, 23 // On Teensy 3.6: also pin 29, 30

Instructions For Use:

In Arduino:
1. Install Teensyduino if you have not already: https://www.pjrc.com/teensy/teensyduino.html
2. Re-start Arduino.
3. Plug in your Teensy.
4. Select your Teensy model from Tools > Board.
5. Upload the sketch to your board.
6. Open Tools > Serial Monitor to see the data. Touch the pin and watch the values change!
7. Close Serial Monitor before opening TouchDesigner.

In TouchDesigner:
1. Make sure Serial Monitor is closed in Arduino.
2. In the serial1 DAT, select the port for your Teensy in the "Port" field.
3. Make sure the Active slider in the same DAT is toggled to On.
4. You should see data streaming in. 

To use this data, you can:
-Write a Python script in the serial1_callbacks (see example in DAT).
-Write a Python script in the datexec1 (see example in DAT).
-Use the THRESHOLD dat to trigger a video to change when the data is above this value.

How to extend this network:
Some other things you might try include adding a timer CHOP, then using the callback to compare values every n seconds. This is useful if you need additional debouncing of your data in TouchDesigner. If you're more comfortable with CHOPs in general, you could use a select chop to select the data from the serial DAT, then manipulate that data as a channel. This network can be combined with my pixel visualizer to switch patterns for LED animations. It can also be used to manipulate visuals for live shows. Other sensors can also be used! Just upload the sensor library in Arduino, and make sure the data is being sent via Serial.println() with a delay. 

Troubleshooting

Problem: The data in TouchDesigner is coming in funny (i.e. the numbers are jamming together).
Solution: Make sure that in the TouchDesigner parameters for the serial1 DAT, you have Row/Callback Format set to "One Per Line." Anotehr reason data corruption might happen is if you don't have a significant delay for print / read statements on the Arduino or TouchDesigner end. Try changing the delay between Serial.println() statements in Arduino to be greater than 100 milliseconds. If this is not possible, and you need a very quick read, I recommend sending but not printing the data over Serial. This can be done using the Serial.write() function. You can also send data using OSC, UDP, or TCP / IP. 
