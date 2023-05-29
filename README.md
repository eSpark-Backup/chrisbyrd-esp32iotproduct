# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of STM32 for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a reference. All specifics of the project are enlisted.

## Project Requirements v2.0
The project consists of **five** boards that are listed as:
1. Baseboard
2. LTE Module
3. Ethernet Module
4. EthPoE Module
5. LoRaWAN Module

### Baseboard v2.0
* The baseboard will now be reduced to only have the following circuits:
    * OLED and supporting circuit. Same as development-v1.0
    * Inputs circuit will remain same but will be extended to 16 x inputs. Same as development-v1.0
    * Outut Relays / RS232 / RS485 and DTMF will also remain same as before.
* The power input will be same as before.
* Dying gasp will remain in compile mask.
* The circuit should be intelligent to auto switch between power supplies keeping 9-30VDC at priority.
* 3 x Push buttons as before. Indication LEDs as before.
* All system LEDs will remain as before.
* Move to a modular approach for comms modules so we can accomodate all scenarios without lots of different products.
* 2 'comms module' slots/connectors.
* Any module type should be able to go in either slot (ie both slots supporting all SPI pins required for W5500 etc, IO pins for any PWR activation).
* The board must support 16 x inputs. The same circuitry for 8 x inputs will be re-used.
* The MCU will remain same as before.
* Need to ensure sufficient power for both slots to be populated

### General description for Comms Modules
* Should use the same motherboard connector for mating.
* Should be the same footprint as other module boards.
* Any external connectors should be accessible when the device is in the enclosure.
* 2 IO pins per slot to identify the comms module type (00=LTE; GPIO PU/PD can be used).
* Overall device should still remain as flat as possible.
* As small dimension as possible. Use smallest components possible.
* USB POGO for updates on module board.
* Optional screw-hole to firmly mount to enclosure
* All comms modules will have the miniPCIE slot built into the PCB itself. The baseboard will have the mating connector. For concept, refer to the image below:
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/0cc94305-896f-4641-afa6-b2ecb042473d)


### LTE Module v2.0 (Comms module)
* External angled SMA antenna directly on the module board (not using separate fly-lead).
* SIM (x2) on the module board.
* SIM slot switching via SIM7500 GPIO.
* GNSS antenna on the module (small space as possible).
* Any LEDs such as NETLIGHT etc can be directly on the module board. Select and suggest appropriate glass pipe with LEDs to expose them from outside the casing.

### Ethernet Module v2.0 (Comms module)
* W5500 on the module board
* Low-profile RJ45 connector directly on module board, accessible at the edge of the enclosure


### EthPoE Module v2.0 (Comms module)
* W5500 on the module board
* POE 802.3af support with all the components on the module board
* Low-profile RJ45 connector directly on module board, accessible at the edge of the enclosure

### LoRaWAN Module v2.0 (Comms module)
* UK/Europe 858Mhz
* Common tranceiver such as Semtech SX127X (Open discussion, most firmware friendly option should be selected)
* External angled SMA antenna directly on the module board
* SPI to ESP32

## PCB Placement concept reference
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/69b61e96-2dc5-45cb-8cac-e25a02b01084)

## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
