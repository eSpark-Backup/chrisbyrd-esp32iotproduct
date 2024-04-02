String receivedMessage;


const int Enable =  16;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(17,18); // RX, TX

void setup() {
  Serial.begin(115200);    // Initialize the Serial monitor for debugging
  
  mySerial.begin(115200);
   
  pinMode(Enable, OUTPUT);
  digitalWrite(Enable, LOW);


}

void loop() {
  while (mySerial.available() > 0) {
    char receivedChar = mySerial.read();
    Serial.println(receivedChar);
  }

  
}
