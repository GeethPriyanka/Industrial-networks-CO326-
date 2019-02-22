#include <Wire.h>

byte pins[] = {2, 3, 4, 5, 6, 7, 8, 9};


// Simple DS1621 demo
// -- 2007-12-19 - by Jon McPhalen (www.jonmcphalen.com)
// -- 2010-10-23 - by J.-C. Heger (www.ordinoscope.net) - added half celcius degrees

// Pinout:
// Arduino Uno: 4 (SDA) / 5 (SCL)
// Arduino Mega: 20 (SDA) / 21 (SCL)
// DS1621 has A2, A1, and A0 pins connected to GND

#define DEV_ID 0x90 >> 1                    // shift required by wire.h

const byte numPins = 8; // how many leds
int state;

void setup() {
  Serial.begin (9600);

  for(int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }

  Wire.begin ();
  Wire.beginTransmission (DEV_ID);           // connect to DS1621 (#0)
  Wire.write (0xAC);                          // Access Config
  Wire.write (0x02);                          // set for continuous conversion
  Wire.beginTransmission (DEV_ID);           // restart
  Wire.write (0xEE);                          // start conversions
  Wire.endTransmission ();
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}


void loop() {
  unsigned int data,tmp,x;

  Wire.beginTransmission (DEV_ID);
  Wire.write (0xAA);                          // read temperature
  Wire.endTransmission ();
  Wire.requestFrom (DEV_ID, 2);              // request 2 bytes from DS1621
  if (Wire.available ()) data  = Wire.read () << 8;
  if (Wire.available ()) data |= Wire.read ();
  
  tmp = 17;// + 
  x = data >> 8;
  tmp = tmp +x;
  //tmp = 19;
  
  //Serial.print (data >> 8);
  Serial.print (tmp);
  Serial.print (data & 0xFF ? ".5" : ".0");
  Serial.println("");

  String binNumber = String(tmp, BIN);
  int binLength = binNumber.length();  
  
  if(tmp <= 255) {  // if we have less or equal to 255 presses
                // here is the scary code
    for(int i = 0, x = 1; i < binLength; i++, x+=2) { 
      if(binNumber[i] == '0') state = LOW;
      if(binNumber[i] == '1') state = HIGH;
      digitalWrite(pins[i] + binLength - x, state);
    } 
  } else {
    // do something when we reach 255
  }
  
  //Change device
  if(digitalRead(2)==LOW && digitalRead(3)==LOW){
     Serial.print("Select 1st Slot"); 
  }
  
  delay (1000);
}
