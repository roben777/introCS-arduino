/*************************************/
/**			Blinking an LED			**/
/**	Example Code: 					**/
/**				N.Reed Parsons 2017 **/
/*************************************/

//	void pinMode(int pin_number,int direction)	//
// \params=2; pin number, direction=INPUT or OUTPUT
// *Built in function used to configure GPIOs

//	void digitalWrite(int pin_number, int pin_value) //
// \params=2; pin number, Pin value= HIGH or LOW
// *Built in function sets the designated pin to HIGH or LOW
// \Example:set pin 13 to HIGH, outputs 5VDC to the LED

//	void delay(int TimeToWait) //
//	\params=1; Time to wait in milliseconds
// *Built in function waits TimeToWait.
// **NOTE:There are 1000 milliseconds in 1 second
 
void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);   // Turn on the LED
  delay(1000);              // Wait for one second
  digitalWrite(13, LOW);    // Turn off the LED
  delay(1000);              // Wait for one second
}