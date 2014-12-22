// Motor
int m1 = 5; // pin connection for motor
int m2 = 6; // pin connection for motor

int velocity; // speed motor goes at.

// Accelerometer
int xSensor = A2; //sensor pin for accelerometer
int ySensor = A1; //sensor pin for accelerometer

float xSensorValue; //value sensor pin outputs on x-axis
float ySensorValue; //value sensor pin outputs on y-axis

int xbase; // base value for x-axis, all measurements will be realtive to this one
int ybase; // base value for y-axis, all measurements will be realtive to this one

int xupper; //upper limit on the x-axis
int xlower; //lower limit on the x-axis
int yupper; //upper limit on the y-axis
int ylower; //lower limit on the y-axis

// sensor values used to decide the speed, will need to be adjusted depending on the base value, potential improvement here.
int mplow = xbase + 5;
int mphigh = xbase + 10;
int mnlow = xbase - 10;
int mnhigh = xbase - 5;
  
// 7 seg display. Pin numbers for the display.
int a = 12;
int b = 13;
int c = 9;
int d = 8;
int e = 7;
int f = 11;
int g = 10;


void setup() {
  
  Serial.begin(9600);
  //
  xbase = analogRead(xSensor);
  ybase = analogRead(ySensor);
  //
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //
  pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop () { 
  
  xSensorValue = analogRead(xSensor);
  ySensorValue = analogRead(ySensor);
 
  //Serial.print("X Value is ");
  //Serial.println(xSensorValue);
  //Serial.print("Y value is ");
  //Serial.println(ySensorValue);
  
  int xupper = xbase + 4;
  int xlower = ybase - 4;
  int yupper = xbase + 4;
  int ylower = ybase - 4;
  
  if (xlower < xSensorValue < xupper && ylower < ySensorValue < yupper) allon(); // switches all lights on if accelerometer registers as flat.
  if (xSensorValue > xupper) xless (); //single line depending on tilt.
  if (xSensorValue < xlower) xmore (); //single line depending on tilt.
  if (ySensorValue > yupper) ymore (); //single line depending on tilt.
  if (ySensorValue < ylower) yless (); //single line depending on tilt.
  if (xSensorValue > xupper && ySensorValue < ylower) xyLess(); //2 lines depending on tilt of both axis.
  if (xSensorValue < xlower && ySensorValue > yupper) xyMore(); //2 lines depending on tilt of both axis.
  if (xSensorValue > xupper && ySensorValue > yupper) xLessYmore(); //2 lines depending on tilt of both axis.
  if (xSensorValue < xlower && ySensorValue < ylower) xMoreYless(); //2 lines depending on tilt of both axis.
      
  Serial.print("Velocity is ");
  Serial.println(velocity);
  
  delay(100);
}
 void xyLess() {
//    Serial.println("X & y tilt is LESS ");
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);    
 }
 void xyMore() {
//    Serial.println("X & y tilt is MORE ");
    digitalWrite(a, 0);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);
 }
 void xLessYmore() {
//    Serial.println("X & y tilt is LESS ");
    digitalWrite(a, 0);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
 }
 void xMoreYless() {
//    Serial.println("X & y tilt is LESS ");
    digitalWrite(a, 1);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 0);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);
 }
 void xmore () {
    Serial.println("X tilt is positive ");
    digitalWrite(a, 1);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);

    // adjusts speed based on x-axis tilt (+ve or -ve) and angle of tilt.
    if (mplow < xSensorValue < mphigh) velocity = 170;
    if (xSensorValue < mplow) velocity = 85;
    if (xSensorValue > mphigh) velocity = 255;
    analogWrite(m2, velocity);
    analogWrite(m1, 0);
 }
  void xless () {
    Serial.println("X tilt is negative ");
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
    
    // adjusts speed based on x-axis tilt (+ve or -ve) and angle of tilt.
    if (mnlow < xSensorValue < mnhigh) velocity = 170;
    if (xSensorValue < mnlow) velocity = 85;
    if (xSensorValue > mnhigh) velocity = 255;
    analogWrite(m1, velocity);
    analogWrite(m2, 0);
 }
  void ymore () {
//    Serial.println("Y tilt is MORE ");
    digitalWrite(a, 0);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);
 }
  void yless () {
//    Serial.println("Y tilt is LESS ");
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 0);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);
 }
 
 void allon(){
//    Serial.println(" X & Y are flat ");
    digitalWrite(a, 0);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 0);
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
 }


