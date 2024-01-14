# Overview
Here are directions to create a module that will switch to personal mode when you start an Infinit Q60.
This should work for model years 2017-2022. This should also work for similar Q50 vehicles, as long as the same mode switch is used.

This uses a small Arduino chip and a relay to simulate pushing the "Change Mode" button several times. Great care is taken to make a plug and play solution. There is no need to cut any wires in the car, and it can be completely removed, returning the car to stock.

## Finished Product
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Complete.jpg" alt="Complete module and wiring harness" width="300" />

## Parts
- 3D printed box
- Plug/receptacle to connect to the switch
    - 1x [TH08FW-NH](https://www.bmotorsports.com/shop/product_info.php/products_id/4227)
    - 5x [Female Terminals](https://www.bmotorsports.com/shop/product_info.php/products_id/4223)
    - 1x [TH08MW-NH](https://www.bmotorsports.com/shop/product_info.php/products_id/5254)
    - 5x [Male Terminals](https://www.bmotorsports.com/shop/product_info.php/products_id/5253)
- Plug/receptacle for the main box
    - 1x [GT150 Receptacle Kit](https://www.bmotorsports.com/shop/product_info.php/products_id/5808)
    - 1x [GT150 Plug Kit](https://www.bmotorsports.com/shop/product_info.php/products_id/5806)
- [Very small screws](https://www.amazon.com/dp/B07ZH9GJWP) to attach the top to the box
- Arduino
    - 1x [Seeed XIAO SAMD21 pre-soldered](https://www.seeedstudio.com/Seeeduino-XIAO-Pre-Soldered-p-4747.html)
    - 1x [Seeed Studio Gove Base for XIAO](https://www.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-p-4621.html)
    - 1x [Grove Relay](https://www.seeedstudio.com/Grove-Relay.html)
    - 1x [12v - 5v DC Converter](https://www.amazon.com/dp/B0C13L11SB)
    - 1x [USB C male plug to bare wire](https://www.amazon.com/dp/B0CKVRD9VJ)
- [22 Guage wire in various colors](https://www.amazon.com/dp/B0C7TJ9191)
- Zip ties
- [Rocker Switch](https://www.amazon.com/dp/B07S2QJKTX)
- Several [Heat shrink tubing](https://www.bmotorsports.com/shop/product_info.php/products_id/596)
- [Tape](https://www.bmotorsports.com/shop/product_info.php/products_id/4060)
- [Connector Kit 24008-9DK9A](https://shop.hartnissanofnova.com/p/109288393/24008-9DK9A.html)
- [Accessory Power Socket](https://www.ebay.com/itm/374948881752)
- [Lighter Plug with leads](https://www.amazon.com/dp/B0963QJLRG)

## Tools
- A Windows or Apple computer to program the Arduino
> [!WARNING]
> A phone or tablet will likely **not** work.
- Soldering Iron
- Protective eyewear
- Pliers

# Wiring
The below picture shows the completed wiring harness. It has three main parts:
1. A harness between the car wiring harness and the mode switch.
2. A harness between the car wrining harness and the Accessory Power Socket (cigarette lighter)
3. A rocker switch to enable/disable operation - allows easily turning off the unit when taking the car in for service.
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Harness.jpg" alt="Complete wiring harness" width="300" />

## Between switch and wiring harness
### Introduction
The mode switch works by providing continuity between specific wires when you push the switch forward or backwards. When pushed forwards, the switch connects wires 1 and 3. For backwards, it connects wires 1 and 2. The below images identify the pins in the wiring harness side and show the actual connector in the car. The pins/wires and their colors (colors may vary) are:
1. Drive mode select switch ground - Black
2. Drive mode select swich backwards - White/Black
3. Drive mode select switch forwards - Sky Blue
4. Power - Red
5. Ground - Black
> [!NOTE]
> There are three blank pins in this connector.

> [!WARNING]
> The TH08 plugs require 22 guage wiring - 20 guage is too big and will not fit.
<table>
    <tr>
        <td><img src="https://github.com/Q60module/PersonalMode/blob/main/images/M35.JPG" alt="Diagram of the TH08 connector" width="225" /></td>
        <td><img src="https://github.com/Q60module/PersonalMode/blob/main/images/M35-in-car.jpg" alt="M35 connector in the car" width="225" /></td>
    </tr>
</table>

### Create harness
Create a harness that fits between the car wiring harness and the switch. Use the TH08FW-NH, TH08MW-NH, associated pins, and the 22 guage wire to connect each pin on the FW with the associated pin on the MW. Pins 1 (black) and 6 (Sky blue) need an additional wire connected to them.

Watch both of these videos:
1. <a href="https://www.youtube.com/watch?v=euZR3xzL7QE">How to assemble TH08FW-NH</a>
1. <a href="https://www.youtube.com/watch?v=rjbkZIhDN3w">How to connect multiple wires</a>

#### Aseemble the TH08FW Connector
Create the harness shown below, with all five wires of the same length, with an additional wire connected to the #1 (black) and #3 (blue) wires: 

<img src="https://github.com/Q60module/PersonalMode/blob/main/images/first-conn-progress.jpg" alt="First part of the wiring" width="225" /> 
    
1. Cut approximately 5 inches of blue and black wire. The exact length doesn't matter, but the wires should be exactly the same length.
1. Cut both wires approximately in half at the same spot.
1. Cut an additional blue and black wire about 8 inches long. Again, the exact length doesn't matter as much but the wires should be exactly the same length.
1. <a href="https://www.youtube.com/watch?v=rjbkZIhDN3w">Strip the ends and join the three</a> blue wires together. Be sure to use heat shrink tubing.
1. Strip the ends and join the three black wires together. Be sure to use heat shrink tubing.
2. Cut white, red, and black wires that are exactly the same length as the newly joined blue and black wires. The idea is to have five wires that will go between the TH08MW-NH and TH08FW-NH that are the same length, with the blue wire and one of the black wires having an additional wire connected to them. This is all shown in the picture above.
3. Strip one end of the black wire that is spliced, <a href="https://www.youtube.com/watch?v=euZR3xzL7QE">attach a pin, and insert into the plug</a> in spot #1 per the diagram above.
4. Strip one end of the white wire, attach a pin, and insert into the plug in spot #2.
5. Strip one end of the blue wire that is spliced, attach a pin, and insert into the plug in spot #3.
6. Strip one end of the red wire, attach a pin, and insert into the plug in spot #4.
7. Strip one end of the other black wire, attach a pin, and insert into the plug in spot #5.
8. It should now look just like the image above, with the wires in the correct spots per the diagram above.

#### Assemble the TH08MW Connector
Assemble the connector such that the newly created harness will connect at one end to the wiring harness in the car and the other end will plug in to the switch, and the wires are all connected straight through, so #1 is connected to #1, #2 is connected to #2 and so on. The only difference is that two of the wires have an additional wire connected to them.
1. Attach a pin the other end of each of the five wires connnected to the TH08FW connector.
2. Insert each pin into the connector in the corresponding position.
3. Use zip ties to stabilize the wires.
4. Use tape to wrap the wires.
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/first-conn-complete.jpg" alt="Complete first part of the wiring" width="225" />

## Power
### Introduction
The Arduino chip needs power to operate. This gets that power from the nearby accessory power socket in the center console under the arm rest. Similar to the TH08 connectors above, this creates a harness that plugs in between the car harness and the accessory power socket. It provides power while allowing the accessory power outlet to continue working as normal.

### Create Harness
Assemble the connector kit, Accessory Power Socket, and lighter plug with leads to provide power.
1. Assemble the 24008-9DK9A Connector Kit. It comes with the connector and three wires. Only use the two wires that have larger diameter - the smaller wire is not needed. Insert the wires into their places in the connector, and snap it shut.
> [!TIP]
> The connector has spots for three wires - the center position is positive.
1. From the 22 guage wire stock, cut off 5 or so inches of red and black wire. The exact lenght of the wire doesn't matter, but they should be the same length.
2. Strip one end of the red wire and <a href="https://www.youtube.com/watch?v=rjbkZIhDN3w">join it with the positive wire from the 24008-9DK9A and the red wire from the lighter plug with leads</a>. Be sure to use heat shrink tubing.
3. Strip one end of the black wire and join it with the negative wire from the 24008-9DK9A and the black wire from the lighter plug with leads. Be sure to use heat shrink tubing.
4. Use zip ties to stabilize the wires, then wrap with tape.
5. Plug the lighter plug into the accessory socket.
The below picture shows tbe completed power harness.
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/power.jpg" alt="Complete power wiring" width="225" />

## All together
It's time to put this all together to complete the wiring harness. Use the GT150 plug kit, the rocker switch, and the wiring harnesses from above to create the complete wiring harness. See the below diagram, the pins on the connectors are:
1. Blank
2. Blank
3. Blue wire from the TH08 wiring harness
4. One of the wires to the rocker switch
5. Red wire from the power harness
6. Blank
7. Blank
8. Black wire from the TH08 wiring harness
9. The other wire to the rocker switch
10. Black wire from the power harness
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/GT150.JPG" alt="GT150 diagram" width="225" />

### Create Harness
Here are two videos on assembeling the GT150 plugs:
1. <a href="https://www.youtube.com/watch?v=5HqLudHUbbI">https://www.youtube.com/watch?v=5HqLudHUbbI</a>
1. <a href="https://www.youtube.com/watch?v=7ucH7XyAD54">https://www.youtube.com/watch?v=7ucH7XyAD54</a>

Directions:
1. Strip the end of the black (ground) wire from the power wiring harness, attach a pin, and insert into the bottom-right (#10) spot in the connector.
2. Strip the end of the red (positive) wire from the power wiring harness, attach a pin, and insert into the top-right (#5) spot in the connector.
3. Strip the end of a wire connected to the rocker switch (it doesn't matter which of the two wires is used here), attach a pin, and insert into the #9 spot in the connector.
4. Strip the end of the other wire connected to the rocker switch, attach a pin, and insert into the #4 spot in the connector.
5. Strip the end of the black wire from the TH08 harness, attach a pin, and insert into the #8 spot in the connector.
6. Strip the end of the Blue wire from the TH08 harness, attach a pin, and insert into the #3 spot in the connector.
7. Attach the wire separator to the back of the connector.
8. Use zip ties to stabilize the wires, then wrap with tape.
The below image shows the complete wiring harness:
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Harness.jpg" alt="Complete wiring harness" width="300" />

# CPU
The Arduino takes care of most of the work in this project. The below picture shows the completed assembled cpu with all the parts. The main components are:
1. The SAMD21 cpu on the Grove Base.
2. The Grove Relay
3. A 12v - 5v DC/DC converter
4. The GT150 Receptacle
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Inside-the-box.jpg" alt="Assembled CPU inside the box" width="300" />

## Assemble and program Arduino
### Assemble the Arduino
Put the various components together to program and test the CPU:
1. Take the SAMD21 CPU, Grove Base, and Grove Relay out of their packages
2. Carefully remove the "extra" section of the grove base - the additional 4 plugs are not needed.
3. Insert the SAMD21 CPU into the Grove Base
4. Using the wiring included in the Grove Relay, connect the relay to the Grove base. As shown in the image above, the wire must be plugged in to the top-left socket.

### Program the Arduino
Download the appropriate software, configure it, load the program on the Arduino, and test it.
1. The below are selected directions from <a href="https://wiki.seeedstudio.com/Seeeduino-XIAO/">Getting Started</a>. See that page for screenshots.
2. Download and install <a href="https://www.arduino.cc/en/software">Arduino IDE</a>
3. Add the Seeed boards to Arduino IDE. Launch the IDE, go to File -> Preference, add this URL to the "Additional Boards Manager URLs":
   3. https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json
4. Go to Tools -> Board -> Boards Manager..., enter "Seeed Studio XIAO SAMD21"and search.
5. Install the appropriate Seeed SAMD Boards by Seeed Studio
6. Connect the SAMD6 to the computer via USB.
    7. The power light should turn on.
8. Go to Tools ->Board, find "Seeeduino XIAO" and select it.
9. Choose File -> New Sketch
10. Select everything in the new file and delete it.
11. Copy and paste the <a href="https://raw.githubusercontent.com/Q60module/PersonalMode/main/code/car_mode.ino">code</a> into the sketch.

The code should look similar to the below screenshot:

<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Arduino-IDE.png" alt="IDE with code" width="300" />

11. Save the sketch.
12. Select the serial device of the Arduino board from the Tools | Serial Port menu. This is likely to be COM3 or higher (COM1 and COM2 are usually reserved for hardware serial ports). To find out, you can disconnect your Arduino board and re-open the menu; the entry that disappears should be the Arduino board. Reconnect the board and select that serial port.
13. Upload the program. Simply click the "Upload" on the toolbar (looks like a right arrow). Wait a few seconds and if successful, the message "Done Uploading" will appear im the status bar.
14. Wait 5-10 seconds, then disconnect the SAMD21 from the computer. Wait a couple of seconds and connect it again.
    1. If the program was loaded successfully and you correctly connected  the Relay to the Grove Base, the relay should emit three audible tick-tocks after 20 seconds. 

## 3D Printed Box
Get the project box printed on a 3D printer:
1. Download the <a href="https://github.com/Q60module/PersonalMode/blob/main/3D-Box/project_box.stl">box definition</a>. 
   1. You will likely need to click the "Download raw file" button
1. Print the box
> [!NOTE]  
> The box design is available under a different license than these directions, the code, and images. See the <a href="https://github.com/Q60module/PersonalMode/blob/main/3D-Box/Readme.md">Readme</a> for details.

## Assemble
To finish up the wiring, connect wires from the GT150 Receptacle to the relay and power supply. Also connect the power supply to the SAMD21. To do that:
1. Solder red and black wires to the "Input +" and "Input -" on the 12v-5v converter.
2. Solder the red and black wires from the USB C male plug to bare wire to the "Output +" and "Output -" on the 12v-5v converter.

That should look something like:

<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Power-supply.jpg" alt="Power Supply" width="300" />  

> [!NOTE]  
> As shown in the image, I split the wires coming from the GT150 receptacle using bullet connectors to make it easier to assemble. 

1. Take a short yellow wire, strip both ends, attach terminals to both, and plug it into #10 and #4 on the GT150 Receptacle directly connecting the two pins.
3. Connect the red wire from the 12v-5v converter input to #5 on the GT150 Receptacle.
4. Connect the black wire from the 12v-5v converter input to #9 on the GT150 Receptacle.
5. Loosen the two screws in the green plastic on the Relay. Use blue and green wires to connect pins #3 and #8 on the GT150 Receptacle to the two slots in the green plastic, tighten the screws in the relay.
6. Connect the USB cable from the 12v-5v converter to the USB on the SAMD21.
7. Find a screw with a head that just fits in the slot on the bottom of the GT150 receptacle. Screw that in to the middle of the large rectangular block on the floor of the box, leaving just enough room for the head to go into the slot.
8. Attach the GT150 receptacle, relay, 12v-5v converter, and Grove Base to the box as shown below:

<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Inside-the-box.jpg" alt="Assembled CPU inside the box" width="300" />  

10. Attach the lid to the box using 4 M2.6x10 screws.

# Installation
Basically, remove the trim piece / center console piece with the gearshift in it, place the box in there, and plug in the various wiring harnesses.
Steps:
1. Remove the trim piece / center console peice containing the gearshift following the first 3:45 in <a href="https://www.youtube.com/watch?v=zX6RrhB0sOw">this video</a>.

> [!TIP]
> That video is slightly different than my car, your mileage may vary. Some differences with my car and notes:
> My car has an additional plug to remove around 0:38. It is much easier to use a small pair of pliers to remove the piece around 1:20. My car didn't have the screws starting around 1:54 (it does have the two starting around 2:19). Starting around 2:38, the remaining pieces come out as one piece for me. Removal ends around 3:45.

3. Place the box near the rear of the compartment with the GT150 plug facing forward.
4. Disconnect the plug going in to the Accessory power socket under the armrest.
5. Connect the plug from the prior step to the Accessory power socket in the new wiring harness.
6. Connect the new wiring harness to the Accessory power socket plug under the armrest.
7. Connect the TH08MW on the new harness to the TH08FW that you disconnected from the mode select switch.
8. Connect the TH08FW on the new harness to the mode select switch.
9. Make sure the rocker switch is turned On.
10. Test the wiring harness.
    1. Connect all wiring that you disconnected during the dis-assembly (leave the GT150 disconnected)
    2. Start the car
    3. Make sure that the car mode switch works when pushing it forward and backwards
    4. Make sure the LED on the Lighter Plug with leads lights up.
    5. Stop the car.
12. Connect the GT150 on the new harness to the box.
13. Verify it works.
    1. Start the car.
    2. Wait 20 seconds.
    3. You should hear three audible tick-tocks and the mode should switch to Personal mode.
    4. Turn the car off.
15. Re-assemble the car.

> [!IMPORTANT]  
> When you start the car, it should switch to personal mode approximately 20 seconds after starting. For me, this even works when remote starting the car.

# Explanation of the code
The code itself is explained over in the <a href="https://github.com/Q60module/PersonalMode/tree/main/code">code readme</a> 

# Possible enhancements/updates
1. The connection to the mode change switch has power, see if it is possible to use that instead of getting power from the accessory plug. Note that the power to the switch powers the LEDs. They vary in brightness with the other lights, so that will likely not work, depending on how they vary brightness (and if the lights can be turned completely off).
2. Use the enable/disable auto start/stop switch to enable/disable the unit instead of using a rocker switch.
3. In addition to changing into personal mode, also turn on driver assistance features and the cruise conntrol.

©2024 by David Horton. This work is openly licensed via <a href="https://github.com/Q60module/PersonalMode/blob/main/LICENSE.txt">CC BY 4.0</a> 
