#Project: Arducode

####Author(s): Umar "Uknj" Khan. Date started: 13th November 2014.

     __    __   __  ___ .__   __.        __  
    |  |  |  | |  |/  / |  \ |  |       |  | 
    |  |  |  | |  '  /  |   \|  |       |  | 
    |  |  |  | |    <   |  . `  | .--.  |  | 
    |  `--'  | |  .  \  |  |\   | |  `--'  | 
     \_______/ |__|\__\ |__| \__| \_______/  
                                         



#####Arduino Code as part of the University 2014-2015 Semester 1 Electronics and Instrumentation module (ENG 2090) for Mechanical Engineering. 

---

#####Things to still do:
1. Comment Code.
2. ~~Add overview of projects to the readme.~~
3. ~~Obtain and add pictures of the board.~~ See the img folder.
4. ~~Add datasheet links for the components and the datasheets themselves.~~ See datasheet.md and the datasheets folder.
5. Fix MotorAccelControl

----

###Hardware Setup
All the code was tested on an [Arduino Leonardo](http://arduino.cc/en/Main/arduinoBoardLeonardo) with a custom built shield to go on top of it. For the board schematic and the connection to pins refer to the BoardShematic.pdf file. The SurreyInstrumentBoard was (to the best of my knowledge) built buy [Professor Roger Webb](http://www.surrey.ac.uk/ati/ibc/people/roger_webb/). For pictures of the board, see the img folder.

One thing to note about the board is the infrared LED that is automatically activated on button press, this is to ensure that the photo-transistor which is located next to the infrared LED can register a light source when the button is pressed.

A motor is also used for one of the projects (MotorAccelControl) for pictures see the img folder.

###Overview of projects

#####1. Blink.

Quite simple and self explanatory, causes a LED to blink. Based on the public domain code from the Arduino documentation. Only needed to change the pin number to ensure that it worked with the hardware setup.

#####2. NumberCountdown.

Using the seven segment display, numbers from 0-9 are displayed and scrolled through.

#####3. Buttonpress_count.

Using the seven segment display and the button on the board, the seven segment display shows the number of times the button was pressed. Only counts from 0 to 9 due to it being a single digit display.

#####4. Analog_TempSensor.

Uses an analog temperature sensor to read a value and convert that to temperature. The temperature is then output to the serial monitor. In order to get this to work, the value output by the sensor needs to be converted to temperature. To do this the sensor value needs to be converted to voltage using `voltageValue = 5 * sensorValue/1024`, this is subsequently converted to resistance using the equation `resValue = (5 * 1000 / voltageValue) - 1000`. Finally using the specification sheet, the resistance needs to be calibrated with the temperature values, this can be done by plotting the values in the table given in MATLAB or Excel and obtain an equation that gives the temperature. For simplicities sake and the fact that we were working mainly at room temperature, I used MATLAB to obtain a linear function even though an exponential equation would be more accurate.

#####5. i2c_TempSensor.

Uses the i2c bus to read the temperature. No math needed as the temperature can be read directly.

#####6. MotorAccelControl.

Using the accelerometer, the seven segment display shows lines based on the tilt of the device. Pluggin in the motor to the Motor 2 pins allows the tilt to control the direction and speed of motor. However due to the fact that plugging in the motor causes the accelerometer to go "crazy", the direction and speed is output to the serial port so it can be read in the arduino software. The code however should still work if a motor is plugged in far enough away from the accelerometer.

Also as the range of values for tilt is so small, the motor only has 3 speeds rather than a linear increase with tilt. The speeds are output as analogue values of `(0, 85, 170 and 255)`. The direction of the motor also changes with tilt direction.

Some fixes are still required for this to work perfectly.

#####7. Light_TempSensor.

When the button is pushed on the board, the phototransistor senses the light sensitivity, if it is above a certain threshold, the analogue temperature sensor gives a temperature reading.