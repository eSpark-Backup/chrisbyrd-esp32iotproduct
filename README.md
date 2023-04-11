# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of ESP32 Module for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a referenceAll specifics of the project are enlisted.

## Project Requirements
* The board will be powered using 9V-30V DC supply so the power section should be capable of supporting the complete range of voltages. In addition to this, the 5V rail and subsequent rails of the board can also be powered using MicroUSB connector. Please note that MicroUSB connector must not have any programming connections.
* The circuit should be intelligent to auto switch between power supplies keeping 9-30VDC at priority.
* ESP32 Module will be used as the main MCU. ESP32-S3 variant should be selected with 8MB Flash and 2MB PSRAM. Voltlink programming capability should be provided for the ESP32.
* 3 x push buttons are required with the MCU labelled as RESET, TEST and BLE_PAIR. RESET should be on the EN pin of ESP32 whereas TEST and BLE_PAIR can occupy any free GPIOs
* 2 x separate LTE chips preferably SIM7000x
* 2 x separate SIM Card connectors for each LTE chip
* 2 x separate antennae for cellular connectivity
* 2 x separate antennae for GPS of both modems
* 1 x Ethernet with RJ45. This will require installing a PHY Chip since ESP32 doesn't have builtin Ethernet. W5500 is suggested here. Working design is already available in Ambient Tracker Pro Schematic.
* 1 x Modbus RTU RS485 to UART circuit
* 1 x I2C based OLED display
* 16 x GPIO inputs
* 3 x GPIO outputs each having 3 pins NO / C / NC
* 1 x GPIO output pin indicating fault output
* 1 x Power LED (Green)
* 3 x system LEDs (Red / Green / Amber)
* 1 x BLE LED (Blue)
* 4 x LEDs; each LED supporting two colors (Red / Green) for COMMS path (LTE1, LTE2, WIFI, ETHERNET)
