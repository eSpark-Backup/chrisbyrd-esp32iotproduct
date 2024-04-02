

int incomingByte = 3; // for incoming serial data

const int Enable =  16;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(17,18); // RX, TX

void setup() {
  Serial.begin(115200);    // Initialize the Serial monitor for debugging
  
  mySerial.begin(115200);
   
  pinMode(Enable, OUTPUT);
  digitalWrite(Enable, HIGH);


}

void loop() {


      mySerial.println(incomingByte);  // Send the message through Serial1 with a newline character
      Serial.println(incomingByte);
      
    
  
}
