#include <MCP23017.h>
#define MCP23017_I2C_ADDRESS 0x20  // I2C address of the MCP23017 IC
const uint8_t LED0 = 0;      // GPA0 (21) of the MCP23017
const uint8_t LED1 = 1;      // GPA1 (22) of the MCP23017
const uint8_t LED2 = 2;      // GPA2 (23) of the MCP23017
const uint8_t LED3 = 3;      // GPA3 (24) of the MCP23017
const uint8_t LED4 = 4;      // GPA4 (25) of the MCP23017
const uint8_t LED5 = 5;      // GPA5 (26) of the MCP23017
const uint8_t LED6 = 6;      // GPA6 (27) of the MCP23017
const uint8_t LED7 = 7;      // GPA7 (28) of the MCP23017
const uint8_t Switch0 = 8;   // GPB0 (1) of the MCP23017
const uint8_t Switch1 = 9;   // GPB1 (2) of the MCP23017
const uint8_t Switch2 = 10;  // GPB2 (3) of the MCP23017
const uint8_t Switch3 = 11;  // GPB3 (4) of the MCP23017
const uint8_t Switch4 = 12;  // GPB4 (5) of the MCP23017
const uint8_t Switch5 = 13;  // GPB5 (6) of the MCP23017
const uint8_t Switch6 = 14;  // GPB6 (7) of the MCP23017
const uint8_t Switch7 = 15;  // GPB7 (8) of the MCP23017

int sda = 39;
int scl = 40;

const uint8_t MCP23017_INTB = 9;  // connected to MCP23017 INTB (19) pin
volatile bool switchDidChange = false;  // change status of MCP23017 input pins


MCP23017 mcp23017 = MCP23017(MCP23017_I2C_ADDRESS);  // instance of the connected MCP23017 IC
void setup() {
  Serial.begin(9600);
   Wire.begin(sda,scl);     // initialize I2C serial bus
   mcp23017.init();  // initialize MCP23017 IC
   // Configure MCP23017 I/O pins
   configurePinsWithPinMode();  // familiar pinMode() style
   // Reset MCP23017 ports
   mcp23017.writeRegister(MCP23017Register::GPIO_A, 0x00);
   mcp23017.writeRegister(MCP23017Register::GPIO_B, 0x00);

   configureInterrupts();
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
   mcp23017.pinMode(LED4, OUTPUT);
   mcp23017.pinMode(LED5, OUTPUT);
   mcp23017.pinMode(LED6, OUTPUT);
   mcp23017.pinMode(LED7, OUTPUT);
   // Configure input pins with internal 100K pull-up resistors
   // Third argument inverts the polarity of the input value when read
   mcp23017.pinMode(Switch0, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch1, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch2, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch3, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch4, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch5, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch6, INPUT_PULLUP, true);
   mcp23017.pinMode(Switch7, INPUT_PULLUP, true);
}
void readAndWriteWithDigitalReadAndDigitalWrite() {
   // Read and write individual inputs and outputs
   mcp23017.digitalWrite(LED0, mcp23017.digitalRead(Switch0));
   mcp23017.digitalWrite(LED1, mcp23017.digitalRead(Switch1));
   mcp23017.digitalWrite(LED2, mcp23017.digitalRead(Switch2));
   mcp23017.digitalWrite(LED3, mcp23017.digitalRead(Switch3));
   mcp23017.digitalWrite(LED4, mcp23017.digitalRead(Switch4));
   mcp23017.digitalWrite(LED5, mcp23017.digitalRead(Switch5));
   mcp23017.digitalWrite(LED6, mcp23017.digitalRead(Switch6));
   mcp23017.digitalWrite(LED7, mcp23017.digitalRead(Switch7));
}




void configureInterrupts() {
   // Configure MCP23017 interrupts
   mcp23017.interruptMode(MCP23017InterruptMode::Separated);  // INTA and INTB act independently
   mcp23017.interrupt(MCP23017Port::B, CHANGE);  // trigger an interrupt when an input pin CHANGE is detected on PORTB
   // Set up interrupt connection and attach interrupt service routine
   mcp23017.clearInterrupts();  // reset interrupt system
   pinMode(MCP23017_INTB, INPUT_PULLUP);  // utilize microprocessor's internal pull-up resistor
   attachInterrupt(digitalPinToInterrupt(MCP23017_INTB), mcp23017ChangeDetectedOnPortB, FALLING);  // INTB is active LOW
}

void mcp23017ChangeDetectedOnPortB() {
  Serial.print("SLOTA TYPE 1 = ");
   switchDidChange = true;
}

void readAndWritePortOnInputChange() {
   if (switchDidChange) {
      delay(100);  // allow time for MCP23017 to set interrupt registers
       // copy values from PORTB (switches) to PORTA (LEDs)
      mcp23017.clearInterrupts();  // clear interrupt
      switchDidChange = false;
   }
}
