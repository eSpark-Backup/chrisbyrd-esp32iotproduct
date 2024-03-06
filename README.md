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

### Baseboard v3.0
* The baseboard will have all the circuitry from the old v2.1 along with following additions / removals / changes:
    * The SoC will now be based on STM32F407 (preferably STM32F407VET6). Please do check JLCPCB availability before finalizing selection.
    * 32MB SPI Flash
    * ESP32-S3 SoC without any external SPI or Flash for wifi with MMCX antenna connector as well as PCB Antenna. SKY13489 RF switch or similar (JLCPCB available part) can be used to select between the two antennas for ESP32-S3. The selection should be done by STM32 and not ESP32. By default, PCB antenna will be active.
    * RS232 will stay
    * RS485 will stay
    * 9-30v DC power input (same as before)
    * USB power (optional - there will be some versions without the USB connector+power components i.e it will be DNP). In production all USB related will be DNP
    * Output relays: 3 (max 1A @ 30V DC)
    * GPIO Input pins: 12 (-0.5V – 30V). Our +/- power in the middle run of our 12 IO terminals in a similar way - ie 6 each side of the +/-. So 14 pins altogether here
    * JTAG Pogo for prototypes programming
    * Dialer circuitry: Remove all the DTMF/PWM/MT8870DN1 altogether. This will be replaced with the Si32185 chip. The sheet will be called "DIAL" instead of "DTMF".
    * Remove: ATEC608 along with related circuitry and connections
    * Use ethernet MAC in STM32 and add DP83825I PHY (non-POE). [Suggested connector](https://jlcpcb.com/partdetail/RCH-RC01835/C708648). This connector will require separate magnetics. Preferred part for [external magnetics](https://jlcpcb.com/partdetail/PulseElec-H1102NLT/C18584).
    * RESET button should be angled and on the side of the enclosure.
    * 
    * A7682E LTE Modem x 2 with MMCX antenna connector for both
    * Remove: All GPS based circuitry and antennae
    * Dual SIM (there will be some versions without second SIM cage and SIM-switcher i.e the 2nd SIM cage and SIM-Switcher will become DNP). Given the fact that we have two different Modems, there will be following possibilities and the circuit should be flexible to manage these:
        * There can be a single Modem with single SIM upon which the whole 2nd SIM cage and switcher circuitry will be DNP
        * There can be a signle modem with dual SIM upon which the same Modem will have connection to both SIM Cages via Switcher as in old design.
        * There can be two Modems with Two SIMs each upon which, 1st SIM Cage will be with 1st Modem and 2nd SIM cage will with 2nd Modem. Solder bridger combinations with proper notes in schematic are needed here.
    * The OLED should be on same Baseboard PCB along with 3 buttons. No LED required now. The Baseboard should have suitable connector for connecting FFC / FPC cable of N091-2832TSWFG05-C15 OLED module. Datasheet for the OLED is pushed to git docs folder.




## PCB Placement concept reference
### Top View (Aerial View)
TBD

### Top View (Aerial View; Without Comms modules placed)
TBD

### Front View
TBD

## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
