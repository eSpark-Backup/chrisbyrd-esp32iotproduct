#include <MCP23017.h>
#define MCP23017_I2C_ADDRESS 0x22  // I2C address of the MCP23017 IC
const uint8_t LED0 = 4;      // GPA0 (21) of the MCP23017
const uint8_t LED1 = 5;      // GPA1 (22) of the MCP23017
const uint8_t LED2 = 6;      // GPA2 (23) of the MCP23017
const uint8_t LED3 = 7;
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
}
void loop() {
   readAndWriteWithDigitalReadAndDigitalWrite();
}
void configurePinsWithPinMode() {
   // Configure output pins
   mcp23017.pinMode(LED0, OUTPUT);
   mcp23017.pinMode(LED1, OUTPUT);
   mcp23017.pinMode(LED2, OUTPUT);
   mcp23017.pinMode(LED3, OUTPUT);
 
}
void readAndWriteWithDigitalReadAndDigitalWrite() {
   // Read and write individual inputs and outputs
   mcp23017.digitalWrite(LED0, LOW);
   delay(2000);
   mcp23017.digitalWrite(LED0, HIGH);
   delay(2000);


}
