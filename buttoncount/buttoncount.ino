// Longer, more obvious example for Arduino 7 segment display
// http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// License: http://www.opensource.org/licenses/mit-license.php (Go crazy)

/* 
 Debounce
 
 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).  
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 
 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 modified 28 Dec 2012
 by Mike Walters
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Debounce
 */


// Umar "Uknj" Khan


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
const int button = 2;
const int a = 12;
const int b = 13;
const int c = 9;
const int d = 8;
const int e = 7;
const int f = 11;
const int g = 10;


// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {               
  pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  // initialize serial communication:
  Serial.begin(9600);

}


void loop() {
// read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
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


  // counting  
  if (buttonPushCounter == 1) zero();
  if (buttonPushCounter == 2) one();
  if (buttonPushCounter == 3) two();
  if (buttonPushCounter == 4) three();
  if (buttonPushCounter == 5) four();
  if (buttonPushCounter == 6) five();
  if (buttonPushCounter == 7) six();
  if (buttonPushCounter == 8) seven();
  if (buttonPushCounter == 9) eight();
  if (buttonPushCounter == 10) nine();
  if (buttonPushCounter == 11) {
    buttonPushCounter = buttonPushCounter - 10;
    }
}

void nine(){
 // write '9' complete
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 1);
 digitalWrite(f, 0);
 digitalWrite(g, 0);
}
void eight(){
 // write '8' complete
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 0);
 digitalWrite(f, 0);
 digitalWrite(g, 0);
}
void seven(){
 // write '7' complete
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 1);
 digitalWrite(e, 1);
 digitalWrite(f, 1);
 digitalWrite(g, 1);
}
void six(){
 // write '6' 
 digitalWrite(a, 0);
 digitalWrite(b, 1);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 0);
 digitalWrite(f, 0);
 digitalWrite(g, 0);
}
void five(){
 // write '5'
 digitalWrite(a, 0);
 digitalWrite(b, 1);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 1);
 digitalWrite(f, 0);
 digitalWrite(g, 0);
}
void four(){
 // write '4'
 digitalWrite(a, 1);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 1);
 digitalWrite(e, 1);
 digitalWrite(f, 0);
 digitalWrite(g, 0);
}
void three(){
 // write '3' corrected
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 1);
 digitalWrite(f, 1);
 digitalWrite(g, 0);
}
void two(){
 // write '2'
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 1);
 digitalWrite(d, 0);
 digitalWrite(e, 0);
 digitalWrite(f, 1);
 digitalWrite(g, 0);
}
void one(){
 // write '1'
 digitalWrite(a, 1);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 1);
 digitalWrite(e, 1);
 digitalWrite(f, 1);
 digitalWrite(g, 1);
}
void zero(){
 // write '0'
 digitalWrite(a, 0);
 digitalWrite(b, 0);
 digitalWrite(c, 0);
 digitalWrite(d, 0);
 digitalWrite(e, 0);
 digitalWrite(f, 0);
 digitalWrite(g, 1);
}
