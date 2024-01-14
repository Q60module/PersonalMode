# Overview
The code in the <a href="https://raw.githubusercontent.com/Q60module/PersonalMode/main/code/car_mode.ino">ca_mode.ino</a> has the Arduino CPU do the following:
1. Sleep (do nothing) for 20 seconds to give the car time to get settled (this might not be needed).
2. Close the normally-open relay for 200 milliseconds and then open it again
3. Sleep (do nothing) for 700 milliseconds
4. Perform steps 2 and 3 twice more

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
