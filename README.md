PCB Business Card by: Corey Harding  
http://www.LegacySecurityGroup.com  
  
My PCB "business card" was designed with a credit card sized form factor in mind to easily fit into a wallet. The board also doubles as an ATtiny85 development board with pins broke out and a prototyping area. The ATtiny85 is pre-programmed to type out my contact info when a capacitive touch sensor is activated. There are also several optional through hole component upgrades for the end user to experiment with. You can even program the board using the Arduino IDE. It is preloaded with a custom 1s delay micronucleus bootloader and it is digispark compatible.  
  
I have seen other similar PCB business cards out there but I made sure to make my project easy for people to modify for personal use as well as allowing the person receiving the business card to have something extra to play with. I believe the ease of use and giving the end user something functional vs just something to look at and throw away is what makes my project stand out. Not to mention capacitive touch sensors are always fun to use!  
  
Hardware License  
-----  
Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0)  
https://creativecommons.org/licenses/by-sa/3.0/  
The hardware is based on the minimal schematic for a digispark/micronucleus compatible board. A few parts have also been added for better stability as well as a capacitive touch sensor. Gerber files are included in the repo to send immediately to a board house as well as Fritzing PCB files to allow users to easily customize my board design and export your own Gerber files.  
  
Software  
-----  
Utilizes the TinyTouchLib: https://github.com/cpldcpu/TinyTouchLib  
  
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
