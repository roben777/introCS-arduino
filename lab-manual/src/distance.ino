#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
// Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


const int trigPin=2;
const int echoPin=8;

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  Serial.begin(9600);

	// initialize the module by setting trig and echo to low (per manual)
	pinMode(trigPin,OUTPUT);
	pinMode(echoPin,OUTPUT);
	digitalWrite(trigPin,LOW);
	digitalWrite(echoPin,LOW);
	delay(10); // some value
}

void loop() {
	float d = distanceCm();
	Serial.println(d, DEC);
	delay(200);
}


float speed_sound = 331.5 + 0.6*20;  // temperature 20 C

// returns the distance as measured by the HC-SR04
float distanceCm() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin,INPUT);
	// can't trigger too frequently, keep trig low for 50 us (as per manual)
	digitalWrite(trigPin,LOW);
	delayMicroseconds(50);
	digitalWrite(trigPin,HIGH);
	delayMicroseconds(10); // as per manual
	digitalWrite(trigPin,LOW);

	float time_us = pulseIn(echoPin, HIGH);  // microseconds
	float time_1way_sec = time_us / 1000000 / 2;  // sec
	float dist = speed_sound * time_1way_sec;  // metres
	return dist*100;  // distance in cm
}
