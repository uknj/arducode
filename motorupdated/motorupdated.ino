// Motor
int m1 = 5; // pin connection for motor
int m2 = 6; // pin connection for motor

int velocity; // speed motor goes at.

// Accelerometer
int xSensor = A2; //sensor pin for accelerometer

float xSensorValue; //value sensor pin outputs on x-axis

int xbase; // base value for x-axis, all measurements will be realtive to this one

int xupper; //upper limit on the x-axis
int xlower; //lower limit on the x-axis

// sensor values used to decide the speed, will need to be adjusted depending on the base value, potential improvement here.
int mplow;
int mphigh;
int mnlow;
int mnhigh;  

void setup() {
  
  Serial.begin(9600);
  
  // assing base values
  xbase = analogRead(xSensor);
  
  // sensor values used to decide the speed, will need to be adjusted depending on the base value, potential improvement here.
  mplow = xbase + 5;
  mphigh = xbase + 8;
  mnlow = xbase - 8;
  mnhigh = xbase - 5;
  
  xupper = xbase + 3;
  xlower = xbase - 3;  
  
  //Setup pins for motor.
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop () { 
  xSensorValue = analogRead(xSensor);
//  Serial.println(mplow); // 524
//  Serial.println(mphigh); // 529
//  Serial.println(mnlow); // 509
//  Serial.println(mnhigh); // 514
  if (xSensorValue > xupper) xless (); // single line depending on tilt.
  if (xSensorValue < xlower) xmore (); // single line depending on tilt.
  if (xlower < xSensorValue && xSensorValue < xupper) allon(); // switches all lights on if accelerometer registers as flat.
}
void xmore () {
    Serial.println("X tilt is positive ");
    // adjusts speed based on x-axis tilt (+ve or -ve) and angle of tilt.
    if (mnlow < xSensorValue && xSensorValue < mnhigh) velocity = 170;
    if (xSensorValue < mnlow) velocity = 255;
    if (xSensorValue > mnhigh) velocity = 85;
    analogWrite(m2, velocity);
    analogWrite(m1, 0);
    
    Serial.print("Velocity is ");
    Serial.println(velocity);
    delay(100);
 }
void xless () {
    Serial.println("X tilt is negative ");    
    // adjusts speed based on x-axis tilt (+ve or -ve) and angle of tilt.
    if (mplow < xSensorValue && xSensorValue < mphigh) velocity = 170;
    if (xSensorValue < mplow) velocity = 85;
    if (xSensorValue > mphigh) velocity = 255;
    analogWrite(m1, velocity);
    analogWrite(m2, 0);
    
    Serial.print("Velocity is ");
    Serial.println(velocity);
    delay(100);
 }
void allon(){
    Serial.println(" X & Y are flat ");
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  
    Serial.print("Velocity is ");
    Serial.println(0);
    delay(100);
 }


