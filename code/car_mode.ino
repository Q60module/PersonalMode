// ©2024 by David Horton. This work is openly licensed via <a href="https://github.com/Q60module/PersonalMode/blob/main/LICENSE.txt">CC BY 4.0</a> 

#include <ArduinoLowPower.h>

#define SWITCH1 A6  //switch pin, used to talk to the Relay

void printSetup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Starting"));
  Serial.println();
  Serial.flush();
}

void setup() {
  pinMode(1, OUTPUT);
  delay(20000);
  for (int i=0; i<3; i++) {
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
    delay(700);
  }
  pinMode(SWITCH1, INPUT);

  LowPower.attachInterruptWakeup(SWITCH1, wakeUp, CHANGE);  //setup interrupt for wake up
}

void loop() {
  LowPower.deepSleep();
}

void wakeUp()
{
  //handler for the interrupt
  LowPower.deepSleep();
}
