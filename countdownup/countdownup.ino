// Longer, more obvious example for Arduino 7 segment display
// http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// License: http://www.opensource.org/licenses/mit-license.php (Go crazy)

void setup() {               
  pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}
int a = 12;
int b = 13;
int c = 9;
int d = 8;
int e = 7;
int f = 11;
int g = 10;


void loop() {
nine();
eight();
seven();
six();
five();
four();
three();
two();
one();
zero();
one();
two();
three();
four();
five();
six();
seven();
eight();
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
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
 delay(1000);
}
