// Motor
int m1 = 5;
int m2 = 6;

int mlow;
int mhigh;

// Accel Sensor
float xSensorValue;
float ySensorValue;

int xbase;
int ybase;
int xupper;
int xlower;
int yupper;
int ylower;

int xSensor = A2;
int ySensor = A1;

// 7 seg display
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
 
  // Serial.print("X base is ");
  // Serial.println(xbase);
  // Serial.print("Y base is ");
  // Serial.println(ybase);


  Serial.print("X Value is ");
  Serial.println(xSensorValue);
  Serial.print("Y value is ");
  Serial.println(ySensorValue);
  
  int xupper = xbase + 4;
  int xlower = xbase - 4;
  int yupper = xbase + 4;
  int ylower = xbase - 4;
  
  int mplow = 517;
  int mphigh = 522;
  int mnlow = 503;
  int mnhigh = 508;
  
  int velocity;
  
  
  if (mnlow < xSensorValue < mnhigh) velocity = 170;
  if (xSensorValue < mnlow) velocity = 85;
  if (xSensorValue > mnhigh) velocity = 255;
  if (mplow < xSensorValue < mphigh) velocity = 170;
  if (xSensorValue < mplow) velocity = 85;
  if (xSensorValue > mphigh) velocity = 255;
  
  if (xlower < xSensorValue < xupper && ylower < ySensorValue < yupper) allon();
  if (xSensorValue > xupper) {
    xless (); 
    
  }
  if (xSensorValue < xlower) {
    xmore ();
  }
  if (ySensorValue > yupper) ymore ();
  if (ySensorValue < ylower) yless ();
  if (xSensorValue > xupper && ySensorValue < ylower) xyLess();
  if (xSensorValue < xlower && ySensorValue > yupper) xyMore();
  if (xSensorValue > xupper && ySensorValue > yupper) xLessYmore();
  if (xSensorValue < xlower && ySensorValue < ylower) xMoreYless(); 
  
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
//    Serial.println("X tilt is MORE ");
    digitalWrite(a, 1);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 1);
 }
  void xless () {
//    Serial.println("X tilt is LESS ");
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);

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
 
/*
 void pnormal(){
   analogWrite(m1, 170);
   analogWrite(m2, 0);
 }
  void pslow(){
   analogWrite(m1, 85);
   analogWrite(m2, 0);
 }
  void pfast(){
   analogWrite(m1, 255);
   analogWrite(m2, 0);
 }
 
  void nnormal(){
   analogWrite(m2, 170);
   analogWrite(m1, 0);
 }
  void nslow(){
   analogWrite(m2, 85);
   analogWrite(m1, 0);
 }
  void nfast(){
   analogWrite(m2, 255);
   analogWrite(m1, 0);
 }
*/
