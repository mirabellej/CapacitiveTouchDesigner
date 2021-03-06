# CapacitiveTouchDesigner
Gets capacitive touch data from Teensy (Arduino) and sends to TouchDesigner over Serial. 
This data is then manipulated using Python scripts to switch between video feeds and edit ramp speed and shape.
Can be used for live video manipulation based on sensor input and to build tactile user interfaces. 

HARDWARE
For use with Teensy LC, 3.0, 3.2, or 3.6 (Teensy 3.5 does not have touch sensing).
Cap touch pins for Teensy: 0, 1, 15, 16, 17, 18, 19, 22, 23 // On Teensy 3.6: also pin 29, 30. 
Capacitive touch sensing is included in these pins on the Teensy. No additional / exterior sensors are needed. 

INSTRUCTIONS

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

To use this data, you can write a Python script in the serial1_callbacks (see example in DAT) or the datexec1 (see example in DAT). You can change the value in the THRESHOLD DAT as needed. 

HOW TO EXTEND THIS NETWORK

Software Extension: This network can be extended to include readings for multiple pins or sensors. Data can be distinguished and sorted by addressing the coordinating row and column of the serial1 DAT in your callback scripts. For timed events, you can include a timer CHOP, then use the timer's callback to compare values every n seconds. This is useful if you need additional debouncing of your data in TouchDesigner. If you're more comfortable with CHOPs in general, you could use a select chop to select the data from the serial DAT, then manipulate that data as a channel. This network can be combined with my pixel visualizer to switch patterns for LED animations. It can also be used to manipulate visuals for live shows. Other sensors can also be used! Just upload the sensor library in Arduino, and make sure the data is being sent via Serial.println() with a delay of at least 100 milliseconds. 

Hardware Extension: You can use this network as a starter for creating your own tactile VJ interface! Just attach the pins on the Teensy to copper pads, conductive fabric or thread or paint, spoons, bananas, or any other conductive material! Next, set up those pins to trigger different effects in your TouchDesigner network. For more on capacitive touch, see: https://www.bareconductive.com/make/what-is-capacitive-sensing/

TROUBLESHOOTING

Problem: The data in the serial1 DAT is coming in funny (i.e. the readings are running together or skipping lines).

Solution: Make sure that in the TouchDesigner parameters for the serial1 DAT, you have Row/Callback Format set to "One Per Line." Another reason data corruption might happen is if you don't have a significant delay for print / read statements on the Arduino or TouchDesigner end. Try changing the delay between Serial.println() statements in Arduino to be greater than 100 milliseconds. If this is not possible, and you need a very quick read, I recommend sending but not printing the data over Serial. This can be done using the Serial.write() function. You can also send data using OSC, UDP, or TCP / IP. 

Problem: TouchDesigner is chugging / the interactivity is delayed.

Solution: Delays might occur if you are trying to process data too quickly or if you have too many visual elements taxing your computer's GPU. Try the changes listed above or making the viewers inactive for your TOPs.

Problem: Arduino isn't recognizing the Teensy as an available board.

Solution: Make sure you that you have Teensyduino installed. If you do, you should see a drop down for Teensy boards under Tools > Boards. If you still don't see your Teensy, press the reset button to see if it needs to be switched from HEX into PROGRAM mode (fun fact: when Teensy boards are shipped, they are generally not in PROGRAM mode and so you will need to do this). If the board still doesn't appear, try unplugging / replugging in your Teensy. If that doesn't work, try a different Micro USB cable (also fun fact: not all micro USB cables are made for data transmission and some might not work with your microcontroller!) As a last resort, try a different Teensy. 
