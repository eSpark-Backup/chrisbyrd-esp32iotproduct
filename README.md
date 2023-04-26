# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of ESP32 Module for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a reference. All specifics of the project are enlisted.

## Project Requirements
* The board will be powered using 9V-30V DC supply so the power section should be capable of supporting the complete range of voltages. This input will be a screw terminal. In addition to this, the 5V rail and subsequent rails of the board can also be powered using MicroUSB connector. Please note that MicroUSB connector must not have any programming connections.
* Dying gasp functionality is also required to send a dying signal to server. Please do some research such that there is enough power to keep Modem and ESP32 powered up to send the dying gasp signal.
* The circuit should be intelligent to auto switch between power supplies keeping 9-30VDC at priority.
* ESP32 Module will be used as the main MCU. ESP32-S3 variant should be selected with 8MB Flash and 2MB PSRAM. Voltlink programming capability should be provided for the ESP32. Embedded antenna module should be selected.
* 3 x push buttons are required with the MCU labelled as Reset / Learn / ConfigMode. RESET should be on the EN pin of ESP32 whereas TEST and BLE_PAIR can occupy any free GPIOs
* 1 x separate LTE-CAT 1 chip. The modem finalized with client is SIM7500E.
* 2 x separate SIM Card connectors should be given with the capability to switch between the active SIM using firmware. 1 x SIM cage should be 4FF NanoSIM. The main SIM card will be MFF2 (eSIM).
* 1 x antenna for cellular connectivity. UFL connector will be provided for the antenna. End product will have an SMA to IPEX cable and and IPEX antenna. You can refer to switchbox design for this.
* 1 x SMA508 SMA Antenna on DIV_ANT interface.
* 1 x antenna for GPS of modem. [This](https://www.te.com/usa-en/product-2118900-1.html) embedded antenna has been finalized by the client.
* 1 x Ethernet with RJ45. This will require installing a PHY Chip since ESP32 doesn't have builtin Ethernet. W5500 is selected here. Working design is already available in Ambient Tracker Pro Schematic.
* 1 x MT8870 DTMF Decoder embedded on-board. [This](http://www.electronics-diy.com/dtmf-decoder-using-mt8870.php) link can be used as a schematic design reference. Please note that the reference link shows Q1, Q2, Q3, Q4 and STD on LEDs but they will be connected to ESP32 GPIOs in this circuit. Furthermore, the JP1 header shown in reference schematic should be a screw terminal in our schematic.
* 1 x Modbus RTU RS485 to UART circuit that should also support RS232.
* 1 x I2C based OLED display
* 8 x GPIO inputs. These inputs need to be protected and not direct GPIO connections. Please note that this part needs to be done in end after using GPIOs of ESP32 for all other peripherals. Screw terminals similar to main power will be used but this connector will be a 9-pin screw terminal with 1 x GND and 8 x Inputs.
* 3 x GPIO outputs each having 3 pins NO / C / NC
* 1 x GPIO output pin indicating fault output. This should also be a 3-pin output NO / C / NC.
* All inputs and outputs should be given via screw terminals.
* 1 x Power LED (Green)
* 3 x system LEDs (Red / Green / Amber)
* 1 x BLE LED (Blue)
* 4 x LEDs; each LED supporting two colors (Red / Green) for COMMS path (LTE1, LTE2, WIFI, ETHERNET)

## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
