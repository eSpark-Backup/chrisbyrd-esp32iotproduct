#include <MCP23017.h>
#define MCP23017_I2C_ADDRESS 0x21  // I2C address of the MCP23017 IC

     
const uint8_t Switch0 = 8;   // GPB0 (1) of the MCP23017
const uint8_t Switch1 = 9;   // GPB1 (2) of the MCP23017
const uint8_t Switch2 = 10;  // GPB2 (3) of the MCP23017
const uint8_t Switch3 = 11;  // GPB3 (4) of the MCP23017

int sda = 39;
int scl = 40;

MCP23017 mcp23017 = MCP23017(MCP23017_I2C_ADDRESS);  // instance of the connected MCP23017 IC
void setup() {
   Wire.begin(sda,scl);     // initialize I2C serial bus
   mcp23017.init();  // initialize MCP23017 IC
   // Configure MCP23017 I/O pins
   configurePinsWithPinMode();  // familiar pinMode() style
   // Reset MCP23017 ports
   mcp23017.writeRegister(MCP23017Register::GPIO_A, 0x00);
   mcp23017.writeRegister(MCP23017Register::GPIO_B, 0x00);
   Serial.begin(9600);
}
void loop() {
   readAndWriteWithDigitalReadAndDigitalWrite();
}
void configurePinsWithPinMode() {
   // Configure output pins
   
   mcp23017.pinMode(Switch0, INPUT);
   mcp23017.pinMode(Switch1, INPUT);
   mcp23017.pinMode(Switch2, INPUT);
   mcp23017.pinMode(Switch3, INPUT);
 
}
void readAndWriteWithDigitalReadAndDigitalWrite() {
   // Read and write individual inputs and outputs

    int buttonState0 = mcp23017.digitalRead(Switch0);
    Serial.print("SLOTA TYPE 0 = ");
    Serial.println(buttonState0);
     

     int buttonState1 = mcp23017.digitalRead(Switch1);
    Serial.print("SLOTA TYPE 1 = ");
    Serial.println(buttonState1);
     

    int buttonState2 = mcp23017.digitalRead(Switch2);
    Serial.print("SLOTA TYPE 2 = ");
    Serial.println(buttonState2);
     

     int buttonState3 = mcp23017.digitalRead(Switch3);
    Serial.print("SLOTA TYPE 3 = ");
    Serial.println(buttonState3);
    delay(1000); 

}
