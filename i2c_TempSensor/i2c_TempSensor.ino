#include <Wire.h>
int address1 = 72; // define I2C Address


void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.beginTransmission(address1);   // transmit to I2C
  Wire.write(0);                      // sends zero bytes.   
  Wire.endTransmission(address1);     // stop transmitting
  int sensorValue = analogRead(A0);
  

  Wire.requestFrom(address1, 1);
  while(Wire.available()==0);
  int Temp = Wire.read();
  Serial.println(sensorValue);
  Serial.println(Temp);
  delay(100);
}
