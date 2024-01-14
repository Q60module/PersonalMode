# Overview
The code in the <a href="https://raw.githubusercontent.com/Q60module/PersonalMode/main/code/car_mode.ino">ca_mode.ino</a> has the Arduino CPU do the following:
1. Sleep (do nothing) for 20 seconds to give the car time to get settled
2. Close the relay for 200 milliseconds and then open it again - this simulates pushing the mode button forward and then releasing it
3. Sleep (do nothing) for 700 milliseconds to pause between pushing the button
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

Now we start getting to some actual code. This next section shouldn't be there - oops. It would setup the CPU to output info when connected to a computer and then print the message "Startring", but it isn't actually used. I'll remove this the next time I update the device.
```
#define SWITCH1 A6  //switch pin, used to talk to the Relay

void printSetup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Starting"));
  Serial.println();
  Serial.flush();
}
```
## Setup Function
The `setup()` function (lines 15-27) runs when the CPU starts up. This function contains all the code that switches modes. For Arduino CPUs, the pins can be in various modes. The next line has to do with where the relay is connected to the Grove base. You can see in the below picture that the Grove base has four white plug receptacles. The relay is connected to the top-left receptacle using the black, red, white, and yellow wires. While is is a little hard to see which of the left receptacles the wire is plugged in to, you can see that the bottom one is empty and that it is plugged into the top one. The top one is #1. 
<img src="https://github.com/Q60module/PersonalMode/blob/main/images/Inside-the-box.jpg" alt="Assembled CPU inside the box" width="300" />  
We need that pin #1 to be in output mode so we can provide power to the Relay to turn it on or off. This code puts pin #1 in the output mode.
```
  pinMode(1, OUTPUT);
```

Continuing in the `setup()` function, I wanted to make sure that the device didn't try to switch modes before the car was ready. The way to take care of that is to tell the CPU to sleep (do nothing) for an amount of time. This code has the CPU do nothing for 20 seconds (20,000 milliseconds).
```
  delay(20000);
```

### Loop
In my Q60, after starting the car, I have to click the mode forward button three times to get to Personal mode. It starts in Normal, moving the switch forward once moves to Sport mode, forward again goes to Sport+, and forard a third time moves to Personal mode. This means we need the CPU to do the same thing three times in a row, this loop does that.
```
  for (int i=0; i<3; i++) {
```

Things inside a computer happen much faster than people are used to. If you consider the last time that you pushed the mode button forward in your car, how long was it forward before you released it? You probably think "immediately", but looking at it carefully, you likely had the button pushed forward for at least 1/10th of a second. This timing is important because if we just instructed the CPU to provide power to the Relay (which simulates pushing the button forward), and immediately had the CPU remove power from the Relay (which simulates releasing the button), that would likely happen in 1-2 hundredths of a second. Since the car's computers are programmed to expect people to push the button forard, it will likely not recognize it if the button is pressed for just 1-2 hundredths of a second. In addition to that, a humnan takes time in between button pushes. To take care of that the code does the following each of the three times through the loop:
1. Provides power to the Relay (pushes the button forward)
2. Waits for 200 milliseconds
3. Removes power from the Relay (releases the button)
4. Waits 700 milliseconds
```
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
    delay(700);
```

The closing curly brace signifies the end of the loop.
```
  }
```

### Set up low power mode
This code instructs the CPU that if it wakes up from low-power mode that it should call the `wakeUp()` function and then ends the setup function.
```
  pinMode(SWITCH1, INPUT);

  LowPower.attachInterruptWakeup(SWITCH1, wakeUp, CHANGE);  //setup interrupt for wake up
}
```

## Loop function
In a typical Arduino program, the `loop()` function is where most of the work happens. The CPU typically runs that function over and over to perform the main work. In this case, we did everything in the `setup()` function, so there is nothing for the `loop()` function to do.
This just puts the CPU in low-power mode, which basically stops all processing.
```
void loop() {
  LowPower.deepSleep();
}
```

## WakeUp function
Is seen in the `setup()` function, if the CPU wakes up from low-power mode, it calls this function. This just puts the CPU back in low-power mode.
```
void wakeUp()
{
  //handler for the interrupt
  LowPower.deepSleep();
}
```
