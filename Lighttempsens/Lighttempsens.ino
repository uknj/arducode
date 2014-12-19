#include <math.h>

int address = 72; // define I2C Address

const int buttonPin = 2;    // the number of the pushbutton pin
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int lightsensor = A3;
int lightlevel;

void setup()
{
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  lightlevel = analogRead(lightsensor);
  Serial.println(lightlevel);
  delay(100);

 buttonState = digitalRead(buttonPin);
  delay(100);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      if (lightlevel > 50) {
      // read the input on analog pin 0:
      float sensorValue = analogRead(A0);
      float voltageValue = 5 * sensorValue/1024;
      float resValue = (5 * 1000 / voltageValue) - 1000;
      float tempValue = (resValue - 1599) / 17.25;
  
      // print out the value you read:
      // Serial.println(sensorValue);
      // Serial.println(voltageValue);
//      Serial.println(resValue);
      Serial.println(tempValue);
      }
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off"); 
    }

  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

}
