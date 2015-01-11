const int buttonPin = 2; // the number of the pushbutton pin
int buttonState = 0; // current state of the button
int lastButtonState = 0; // previous state of the button

int lightsensor = A3; // sensor pin
int lightlevel; // sensor value
int baselight; // the background amount of light

void setup()
{
  Serial.begin(9600); // start serial for output
  baselight = analogRead(lightsensor);
}

void loop()
{

// first, detect button press.
 buttonState = digitalRead(buttonPin);
  delay(100); //delay to prevent debounce.
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {      // if the current state is HIGH then the button went from off to on:
      delay(100); // delay the reading of the lightsensor for 0.1s to allow the increase in light due to 
      lightlevel = analogRead(lightsensor); // read the lightsensor to obtain a value.
//      Serial.println(lightlevel); // Output the value to serial.
      
      // Check to see if the lightvalue is above the background value.
      if (lightlevel > baselight) {{
      // read the input on analog pin 0:
      float sensorValue = analogRead(A0); // 
      float voltageValue = 5 * sensorValue/1024;
      float resValue = (5 * 1000 / voltageValue) - 1000;
      float tempValue = (resValue - 1599) / 17.25;
  
      // print the temperature value.
      Serial.println(tempValue);
      }
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("Not enough light"); 
    }

  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

}}
