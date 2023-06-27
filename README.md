# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of STM32 for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a reference. All specifics of the project are enlisted.

## Project Requirements v2.0
The project consists of **five** boards that are listed as:
1. Baseboard
2. LTE Module
3. Ethernet Module
4. EthPoE Module
5. LoRaWAN Module
6. OLED Module

**Please note that every board must use the smallest available component as board dimension need to be as small as possible**

### Baseboard v2.0
* The baseboard will now be reduced to only have the following circuits:
    * Inputs circuit will remain same but will be extended to 12 x inputs. The input protection scheme will be changed to using simple basic Zeners with necessary protection such that it can protect a 3.3V IO up to 39VDC.
    * Outut Relays will be reduced to 3 Relays instead of 4. The relay names will be RELAY1, RELAY2 and RELAY 3. RS232 / RS485 and DTMF will also remain same as before. There should be additional chasis GND pin for RS232 / RS485.
    * There should be capability to simulate a phone line using PWM output from ESP32. Further study needs to be done from [this](https://york.hackspace.org.uk/blog/simulating-a-phone-line/) article. We do not require the ring detection or phone pick up for this experiment. It is advised to expose a pad for VCC and GND (so that 9-12VDC can be supplied externally, if needed) and to expose a pad for Line Out. The Line In will be our PWM output from ESP32.
* The power input will be same as before. However, there is a change request that USB power input will now be done via USB-C connector
* Indication LEDs same as before.
* Dying gasp will be completely removed.
* The circuit should be intelligent to auto switch between power supplies keeping 9-30VDC at priority.
* All on board LEDs will be removed.
* Move to a modular approach for comms modules so we can accomodate all scenarios without lots of different products.
* 2 'comms module' slots/connectors.
* Any module type should be able to go in either slot (ie both slots supporting all SPI pins required for W5500 etc, IO pins for any PWR activation).
* The board must support 16 x inputs. The same circuitry for 8 x inputs will be re-used. All inputs should be same (i.e if they are directly connected, all should be this way, if even one of them is through expander, all of them should be shifted to expander). For the expander, please give INTA, INTB and RESET pins on MCU GPIOs.
* The MCU will be changed to an ESP32-S3R8 with additional external 8MB Flash. The antenna type is both UFL and PCB Antenna. The PCB antenna will be designed similar to module and then using an SPDT RF switch, the user should also be able to select an external angled SMA connector based antenna.
* Need to ensure sufficient power for both slots to be populated
* Expose I2C bus on both mPCIE slots.
* Expose USB on both mPCIE slots. Additionally, for JTAG support, we can use the same D+ and D- pins. Refer to [this](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-guides/jtag-debugging/) article for more information and to see if there's any limitation. The same power USB-C connector will be used for JTAG capability in prototype and will be NC in production version.
* The pin naming concept from client is uploaded [here](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/de9421c7-bf26-46f6-a9f4-a8df74dabe0c). Please make room for these signals. The main intent here is to be able to identify in which slot, the module is inserted.
* The USB D+ and D- will also be connected to OLED board.
* 1 x push button connected to ESP32 RESET. This button needs to be right angled and exposed from one of the suitable edges of the PCB.

### OLED v2.0
* OLED and supporting circuit. Same as development-v1.0. The OLED so selected should be 128x64 0.96 inch I2C based that has a external connector for easy integration with casing.
* 3 x Push buttons as before. They will be called BTN1, BTN2 and BTN3. System LED as before. The buttons will be finalized after input from the casing designer about the height / nose of the button.
* The PCB will be connected via single crimpshell connector to the baseboard.

### General description for Comms Modules
* Currently finalized dimensions for all Module boards (except for OLED board) are: 53mm(L) x 33mm(W)
* Should use the same motherboard connector for mating.
* Should be the same footprint as other module boards.
* Any external connectors should be accessible when the device is in the enclosure.
* 4 IO pins per slot to identify the comms module type (00=LTE; GPIO PU/PD can be used).
* Overall device should still remain as flat as possible.
* As small dimension as possible. Use smallest components possible.
* USB POGO for updates on module board.
* Optional screw-hole to firmly mount to enclosure
* All comms modules will have the miniPCIE slot built into the PCB itself. The baseboard will have the mating connector. For concept, refer to the image below:  
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/0cc94305-896f-4641-afa6-b2ecb042473d)

#### Genarel Layer Stack for Comms Modules
* Layer stackup should be 1mm with 1oz.

| Layer      | Thickness (mm) |
| ----------- | ----------- |
| Solder Mask      | 0.01 - 0.015       |
| Copper   | 0.035        |
| Core     | 0.9mm       |
| Copper   | 0.035        |
| Solder Mask      | 0.01 - 0.015       |


### LTE Module v2.0 (Comms module)
* External angled SMA antenna directly on the module board (not using separate fly-lead).
* SIM (x2) on the module board.
* SIM slot switching via SIM7500 GPIO.
* GNSS antenna on the module (small space as possible).
* Any LEDs such as NETLIGHT etc can be directly on the module board. Select and suggest appropriate glass pipe with LEDs to expose them from outside the casing.
* Both SIM cages should be NANO size if not already.
* SIM CD pins to be used and given on the Modem GPIOs (if possible), otherwise exposed to mPCIE for connection with ESP32.

### Ethernet Module v2.0 (Comms module)
* W5500 on the module board
* Low-profile RJ45 connector directly on module board, accessible at the edge of the enclosure
* [ARJM11D7-114-AB-EW2](https://eu.mouser.com/ProductDetail/ABRACON/ARJM11D7-114-AB-EW2?qs=YCa%2FAAYMW02ICsJcHu%252BNJg%3D%3D) is recommended.


### EthPoE Module v2.0 (Comms module)
* W5500 on the module board
* POE 802.3af support with all the components on the module board
* Low-profile RJ45 connector directly on module board, accessible at the edge of the enclosure.
* [ARJM11D7-114-AB-EW2](https://eu.mouser.com/ProductDetail/ABRACON/ARJM11D7-114-AB-EW2?qs=YCa%2FAAYMW02ICsJcHu%252BNJg%3D%3D) is recommended.

### LoRaWAN Module v2.0 (Comms module)
* UK/Europe 868Mhz
* Common tranceiver such as Semtech SX127X (Open discussion, most firmware friendly option should be selected)
* External angled SMA antenna directly on the module board
* SPI to ESP32

## miniPCIE Custom Pinout
[ChrisByrd-PinMappingmPCIE](https://docs.google.com/spreadsheets/d/1UC85la9PA6Eosm3OwLXHTxeFnjLNLskoqfJ7Z_iW8N4/edit#gid=0)

## PCB Placement concept reference
### Top View (Aerial View)
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/1f95a135-d252-4808-8fca-8252b7d831c3)

### Top View (Aerial View; Without Comms modules placed)
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/a414fa4d-9781-4f56-9394-f436f4fba37c)

### Front View
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/9c0c17f4-6431-49bd-ac9b-5abfbb7695bf)

## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
