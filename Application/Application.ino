/*
PCB Business Card by: Corey Harding  
http://www.LegacySecurityGroup.com  
  
Initial programming instructions if building the board from scratch.  
-----  
(Any of my assembled boards already have the bootloader burned in)  
Fuse: avrdude -c buspirate -P /dev/ttyUSB1 -p attiny85 -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m -B 20  
Burn Bootloader: avrdude -c buspirate -P /dev/ttyUSB1 -p attiny85 -U flash:w:bootloader.hex:i -B 20  
The Micronucleus build included has a custom 1 second programming delay before running the application.  
The default 6 second delay was too long to wait to run the application for my specific use case.  
  
Programming the application portion via the Arduino IDE.  
-----  
File - Preferences - Additional Board Manager URLs - http://digistump.com/package_digistump_index.json - OK  
Tools - Board - Boards Manager... - Digistump AVR Boards - Install  
Board: Digispark (Default - 16.5mhz)  
Programmer: Micronucleus  
  
Jumpers  
-----  
Cut J1 to disable the capacitive touch sensor.  
Cut J2 to disable R5 resistor from RST to VCC.  
Bridge J3 to enter programming mode when flashed with a different Micronucleus build.  
  
Optional Features  
-----  
Reset Switch  
Power LED - Requires 1K Resistor  
Utilizing the Prototyping Area  
Flashing a new application via USB  
Flashing via the AVR ISP header(Do not connect a programmer while connected to a USB port)  
  
Notes  
-----  
The board thickness is 1.6mm and requires a shim to fit snugly into the USB port.  
Currently a blank PVC ID card is cut to size and bonded using Loctite 495 Instant Adhesive.  
This has proven so far to be a fast, strong, and relatively consistent solution.  
  
Enjoy!  
*/

#include "DigiKeyboard.h"

extern "C" {
#include "TinyTouchLib.h" //From: https://github.com/cpldcpu/TinyTouchLib
}

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  tinytouch_init();
}

void loop() {

  CLKPR = _BV(CLKPCE);
  CLKPR = 0;

  if (tinytouch_sense() == tt_push) {
    DigiKeyboard.update();
    DigiKeyboard.println(F("---Contact Info---"));
    DigiKeyboard.println(F(""));
    DigiKeyboard.println(F("Name:  Corey Harding"));
    DigiKeyboard.println(F("Email: contact@legacysecuritygroup.com"));
    DigiKeyboard.println(F("Phone: (555)-123-4567"));
    DigiKeyboard.println(F("URL:   https://www.LegacySecurityGroup.com"));
    DigiKeyboard.println(F(""));
    DigiKeyboard.println(F("Board designed, assembled, and programmed by Corey Harding."));
    DigiKeyboard.println(F("GitHub: https://github.com/exploitagency/PCB-Business-Card"));
    DigiKeyboard.println(F("This board also doubles as an ATtiny85 development board."));
    DigiKeyboard.println(F("It is loaded with the micronucleus bootloader and can be programmed using the Arduino IDE."));
    DigiKeyboard.println(F("Select \"Board: Digispark (Default - 16.5mhz)\" and Programmer: \"Micronucleus\"."));
    DigiKeyboard.println(F(""));
  }

}
