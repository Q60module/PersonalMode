# Overview
The code in the <a href="https://raw.githubusercontent.com/Q60module/PersonalMode/main/code/car_mode.ino">ca_mode.ino</a> has the Arduino CPU do the following:
1. Sleep (do nothing) for 20 seconds to give the car time to get settled (this might not be needed).
2. Close the relay for 200 milliseconds and then open it again
3. Sleep (do nothing) for 700 milliseconds
4. Perform steps 2 and 3 twice more

The relay is a <a href="https://en.wikipedia.org/wiki/Relay">Single-Pole Single-Throw, Normally-Open Relay</a>, which basicaly means that while power is applied, it connects the two wires attached to it.

# Details
Below are explanations for each section of code, starting at the top.

The first line is a copyright notice. Everything in this repository is licensed under the <a href="https://github.com/Q60module/PersonalMode/blob/main/LICENSE.txt">CC BY 4.0</a> except for the 3D printed box design which is licensed under the <a href="https://opensource.org/licenses/bsd-license.php">2-Clause BSD License</a>. 
```
// ©2024 by David Horton. This work is openly licensed via <a href="https://github.com/Q60module/PersonalMode/blob/main/LICENSE.txt">CC BY 4.0</a> 
```

This next line includes functions for putting the CPU into low power mode after the work has been completed.
```
#include <ArduinoLowPower.h>
```

The next line has to do with where the relay is connected to the Grove base. You can see in the below picture that the Grove base has four white plug receptacles. The relay is connected to the top-left receptacle using the black, red, white, and yellow wires. While is is a little hard to see which of the left receptacles the wire is plugged in to, you can see that the bottom one is empty and that it is plugged into the top one. The top one is A6.
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Inside-the-box.jpg" alt="Assembled CPU inside the box" width="300" />

```
#define SWITCH1 A6  //switch pin, used to talk to the Relay
```
