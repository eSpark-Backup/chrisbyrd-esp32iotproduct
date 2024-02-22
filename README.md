# Chris Byrd - ESP32 IoT Product
The project deals with developing a custom board based off of ESP32 for the client that complies with the SOW shared by the client. The product is essentially an alarm signalling unit, to monitor the status of security / fire etc and send the alarm signal to the monitoring centre. A [competitor device](https://www.redcare.bt.com/assets/documents/installation-support/bt-redcare-installer-handbook.pdf) is shared as a reference. All specifics of the project are enlisted.

## Project Requirements v3.0
The project consists of a single board having capability to provide all the variants features as listed below from older revisions:
- Baseboard
    - LTE Variant
    - Ethernet Variant
    - Ethernet+LTE Variant
    - LTE+LTE Variant
    - OLED Variant

**Please note that board must use the smallest available component as board dimension need to be as small as possible. The board also needs to be fully compatible with JLCPCB**

### Baseboard v3.0
* The baseboard will have all the circuitry from the old v2.1 along with following additions / removals / changes:
    * The SoC based circuit will be shifted back to ESP32-S3 module with IPEX antenna connector. Please use the same module variant as the selected SoC.
    * RS232 will stay
    * RS485 will stay
    * 9-30v DC power input (same as before)
    * USB power (optional - there will be some versions without the USB connector+power components i.e it will be DNP)
    * Output relays: 3 (max 1A @ 30V DC)
    * GPIO Input pins: 12 (-0.5V – 30V)
    * JTAG Pogo for prototypes programming
    * Remove: dialer circuitry along with connections on ESP32
    * Remove: ATEC608 along with related circuitry and connections
    * W5500 ethernet (non-POE). [Suggested connector](https://jlcpcb.com/partdetail/Hctl-HC_RJ45_0535/C3010566) but open to suggestions
    * A7682E LTE modules x 2
    * MMCX antenna connector for both modems
    * Remove: All GPS based circuitry and antennae
    * Dual SIM (there will be some versions without second SIM cage and SIM-switcher i.e the 2nd SIM cage and SIM-Switcher will become DNP). Given the fact that we have two different Modems, there will be following possibilities and the circuit should be flexible to manage these:
        * There can be a single Modem with single SIM upon which the whole 2nd SIM cage and switcher circuitry will be DNP
        * There can be a signle modem with dual SIM upon which the same Modem will have connection to both SIM Cages via Switcher as in old design.
        * There can be two Modems with Two SIMs each upon which, 1st SIM Cage will be with 1st Modem and 2nd SIM cage will with 2nd Modem. Solder bridger combinations with proper notes in schematic are needed here.
    * The [OLED](https://www.amazon.co.uk/components-Display-0-96inch-Horizontal-SSD1306/dp/B07SX13VZY?th=1) should be on a separate PCB elevated via 2 header strips and this elevated board should have 3 buttons. The OLED link is only for reference of what type of OLED to use but the elevated PCB will be a custom made with custom circuitry for OLED (see if the ones from old versions OLED boards can be reused).



## PCB Placement concept reference
### Top View (Aerial View)
TBD

### Top View (Aerial View; Without Comms modules placed)
TBD

### Front View
TBD

## Product Concept Image
![image](https://user-images.githubusercontent.com/76909080/231306667-7d5fe828-1458-43cc-afbd-3eca53725494.png)
