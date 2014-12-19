#include <math.h>
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  float voltageValue = 5 * sensorValue/1024;
  float resValue = (5 * 1000 / voltageValue) - 1000;
  float tempValue = (resValue - 1599) / 17.25;
  
  // print out the value you read:
  // Serial.println(sensorValue);
  // Serial.println(voltageValue);
  Serial.println(resValue);
  Serial.println(tempValue);
  
  // delay in between reads for stability:
  delay(100);
}
