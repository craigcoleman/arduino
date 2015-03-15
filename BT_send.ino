#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
SoftwareSerial mySerial(8, 9); //RX,TX

const int ledPin = 13; // the pin that the LED is attached to

byte iB;      // a variable to read incoming serial data into
int count = 0;

void setup() 
{
  // initialize serial communication:
  Serial.begin(9600);
  
  mySerial.begin(9600);

  Serial.print("set up complete...");
  // make sure that the default chip select pin is set to
  }

void loop() 
{
  count++;
  
  mySerial.listen();
  Serial.print(" ...");
    if (mySerial.available() > 0) {
    // read the oldest byte in the serial buffer:
    iB = mySerial.read();
    Serial.println(iB);
    //Serial.print("+");
    if (count % 16)Serial.println();
    analogWrite(ledPin, iB);
    delay (100);
    }
}
