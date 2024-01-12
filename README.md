# Overview
Directions to create a module that will switch to personal mode when you start an Infinit Q60.
This should work for model years 2017-2022. This should also work for similar Q50 vehicles, as long as the same mode switch is used.

This uses a small Arduino chip and a relay to simulate pushing the "Change Mode" button several times. Great care is taken to make a plug and play solution. There is no need to cut any wires, and it can be completely removed, returning the car to stock.

## Finished Product
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Complete.jpg" alt="Complete module and wiring harness" width="300" />

Parts
- 3D printed box
- Plug/receptacle to connect to the switch
    - 1x [TH08FW-NH](https://www.bmotorsports.com/shop/product_info.php/products_id/4227)
    - 5x [Female Terminals](https://www.bmotorsports.com/shop/product_info.php/products_id/4223)
    - 1x [TH08MW-NH](https://www.bmotorsports.com/shop/product_info.php/products_id/5254)
    - 5x [Male Terminals](https://www.bmotorsports.com/shop/product_info.php/products_id/5253)
- Plug/receptacle for the main box
    - 1x [GT150 Receptacle Kit](https://www.bmotorsports.com/shop/product_info.php/products_id/5808)
    - 1x [GT150 Plug Kit](https://www.bmotorsports.com/shop/product_info.php/products_id/5806)
- [Very small screws](https://www.amazon.com/dp/B07ZH9GJWP)
- Arduino
    - 1x [Seeed XIAO SAMD21 pre-soldered](https://www.seeedstudio.com/Seeeduino-XIAO-Pre-Soldered-p-4747.html)
    - 1x [Seeed Studio Gove Base for XIAO](https://www.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-p-4621.html)
    - 1x [Grove Relay](https://www.seeedstudio.com/Grove-Relay.html)
    - 1x [12v - 5v DC Converter](https://www.amazon.com/dp/B0C13L11SB)
    - 1x [USB C male plug to bare wire](https://www.amazon.com/dp/B0CKVRD9VJ)
- [22 Guage wire in various colors](https://www.amazon.com/dp/B0C7TJ9191)
- Zip ties
- [Rocker Switch](https://www.amazon.com/dp/B07S2QJKTX)
- several [Heat shrink tubing](https://www.bmotorsports.com/shop/product_info.php/products_id/596)
- [Tape](https://www.bmotorsports.com/shop/product_info.php/products_id/4060)
- [Connector Kit 24008-9DK9A](https://shop.hartnissanofnova.com/p/109288393/24008-9DK9A.html)
- [Accessory Power Socket](https://www.ebay.com/itm/374948881752)
- [Lighter Plug with leads](https://www.amazon.com/dp/B0963QJLRG)

# Wiring
The below picture shows the completed wiring harness. It has three main parts:
1. A harness between the car wiring harness and the mode switch.
2. A harness between the car wrining harness and the Accessory Power Socket (cigarette lighter)
3. A rocker switch to enable/disable operation - allows easily turning off the unit when taking the car in for service.
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Harness.jpg" alt="Complete wiring harness" width="300" />

## Between switch and wiring harness
### Introduction
The mode switch works by providing continuity between specific wires when you push the switch forward or backwards. When pushed forwards, the switch connects wires 1 and 6. For backwards, it connects wires 1 and 2. The below image identifies the pins in the wiring harness side. The pins/wires and their colors (colors may vary) are:
1. Drive mode select switch ground - Black
2. Drive mode select swich backwards - White/Black
3. blank
4. blank
5. blank
6. Drive mode select switch forwards - Sky Blue
7. Power - Red
8. Ground - Black

<img src="https://github.com/Q60module/PersonalMode/blob/main/images/M35.JPG" alt="Diagram of the TH08 connector" width="150" />

### Create harness
Create a harness that fits between the car wiring harness and the switch. Use the TH08FW-NH, TH08MW-NH, associated pins, and the 22 guage wire to connect each pin on the FW with the associated pin on the MW. Pins 1 (black) and 6 (Sky blue) need an additional wire connected to them.

Watch both of these videos:
1. <a href="https://www.youtube.com/watch?v=euZR3xzL7QE">How to assemble TH08FW-NH</a>
1. <a href="https://www.youtube.com/watch?v=rjbkZIhDN3w">How to connect multiple wires</a>

## Power
The Arduino chip needs power to operate. 

## All together

# 3D Printed Box
## Box
## Assemble
### Program Arduino
