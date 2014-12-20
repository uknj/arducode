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
2. Add overview of projects to the readme.
3. ~~Obtain and add pictures of the board.~~ See the img folder.
4. Add datasheet links for the components and the datasheets themselves potentially.

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