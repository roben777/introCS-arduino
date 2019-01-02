/* ********************************************
Simple program testing the Adafruit motor shield

Author: R. Benkoczi
***********************************************/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // |\label{a5:adafruit}|

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1); // |\label{a5:getmotor}|
// OBS: can declare another motor variable on a different port

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void loop() {
  myMotor->setSpeed(80);  // |\label{a5:speed1}| speed betwen 0 and 255 max
  myMotor->run(FORWARD);  // |\label{a5:off1}| turn on (other
			  // values: BACKWARD for reverse, RELEASE to stop)  
  delay(3600000);         // wait for an hour
}
