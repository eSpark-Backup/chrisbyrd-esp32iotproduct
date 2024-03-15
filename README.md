# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of ESP32 for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a reference. All specifics of the project are enlisted.

## Project Requirements v3.0
The project consists of a single board having capability to provide all the variants features as listed below from older revisions:
- Baseboard
    - WIFI
    - WIFI+LTE (SINGLE & DUAL SIM option)
    - WIFI+LTE+LTE (SINGLE SIM PER LTE)
    - WIFI+ETHERNET
    - WIFI+ETHERNET+LTE (SINGLE & DUAL SIM option)

**Please note that board must use the smallest available component as board dimension need to be as small as possible. The board also needs to be fully compatible with JLCPCB**

### Baseboard v3.0 Schematic
* The baseboard will have all the circuitry from the old v2.1 along with following additions / removals / changes:
    * The SoC will now be based on STM32F407 (preferably STM32F407VET6). Please do check JLCPCB availability before finalizing selection.
    * 16MB SPI Flash
    * 1 blue LED on any spare GPIO (if available directly, no need to add any MUX as this requirement is optional only).
    * 6-pin, 2.54mm, dual row, Male JST header is needed connected to SPI bus of MCU with 3.3V and GND. Do check for some standard pinout on the internet and follow that for connections. Preferred connector is [here](https://jlcpcb.com/partdetail/475972-HX20012_6Ablack/C469723)
    * ESP32-C3FH4 SoC without any external SPI or Flash for wifi+ble with MMCX antenna connector as well as PCB Antenna. SKY13489 RF switch or similar (JLCPCB available part) can be used to select between the two antennas for ESP32-C3FH4. The selection should be done by STM32 and not ESP32. By default, PCB antenna will be active.
    * It is also required to be able to flash ESP32 using STM32 so connection of all relevant strapping pins is required to be able to tweak boot modes of ESP32 and flash it using serial bootloader and then run it afterwards using boot from Flash.
    * RS232 will stay
    * RS485 will stay
    * 9-30v DC power input (same as before)
    * Remove: USB circuitry along with Oring circuit
    * Output relays: 3 (max 1A @ 30V DC)
    * GPIO Input pins: 12 (-0.5V – 30V). Our +/- power input pins should be at the left of our 12 IO terminals. So 14 pins altogether here.
    * JTAG Pogo for prototypes programming
    * Dialer circuitry: Remove all the DTMF/PWM/MT8870DN1 altogether. This will be replaced with the Si32185 chip. The sheet will be called "DIAL" instead of "DTMF". The Si32185 reference design is available in repo in docs folder. Some notes related to reference design as received from vendor are:
        * The ref design schematic covers 3 sections, navigate to:
            * Section 5.1 Si32185 base schematic, which includes branches to DCDC converter (see section 5.3) and input protection circuit (see Section 5.4)
            * Regarding section 5.4, there is always a little uncertainty about the way its drawn (although the protection chip is shunt), “tip_ext” and “ring_ext” go to the outside world, tip and ring go back to the Proslic.
            * The DC-DC converter generates the Vbat signal that feeds back into the Si32185. Its designed to run from a 4.5V to 16V DC input.
    * Remove: ATEC608 along with related circuitry and connections
    * Use ethernet MAC in STM32 and add DP83825I PHY (non-POE). [Suggested connector](https://jlcpcb.com/partdetail/RCH-RC01835/C708648). This connector will require separate magnetics. Preferred part for [external magnetics](https://jlcpcb.com/partdetail/PulseElec-H1102NLT/C18584).
    * RESET button should be straight faced. Position placement layout will be shared in a diagram below.
    * A7682E LTE Modem x 2 with MMCX antenna connector for both. Netlight LEDs should be green for both modems.
    * All LEDs on board should be same style and size but different colors (except for netlight).
    * Remove: All GPS based circuitry and antennae
    * Dual SIM (there will be some versions without second SIM cage and SIM-switcher i.e the 2nd SIM cage and SIM-Switcher will become DNP). Given the fact that we have two different Modems, there will be following possibilities and the circuit should be flexible to manage these:
        * There can be a single Modem with single SIM upon which the whole 2nd SIM cage and switcher circuitry will be DNP
        * There can be a signle modem with dual SIM upon which the same Modem will have connection to both SIM Cages via Switcher as in old design.
        * There can be two Modems with Two SIMs each upon which, 1st SIM Cage will be with 1st Modem and 2nd SIM cage will with 2nd Modem. Solder bridger combinations with proper notes in schematic are needed here.
    * The OLED should be on same Baseboard PCB along with 4 buttons. Buttons should be normal tactile buttons with normal height and not elongated. No LED required now. The Baseboard should have suitable connector for connecting FFC / FPC cable of N091-2832TSWFG05-C15 OLED module. Datasheet for the OLED is pushed to git docs folder.




### Baseboard v3.0 PCB
- Major circuitry should be placed on rear side so that we can have a clean front side and only place the things (ideally) on front side as mentioned in the Front View below.
- PCB target dimensions TBD.
#### Front View
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/2454c2b2-d69f-4f67-a375-91257a7ee937)


#### Rear View
![image](https://github.com/eSpark-Consultants/chrisbyrd-esp32iotproduct/assets/76909080/416e22b4-c11d-4108-ad23-f44dc7969934)


## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
