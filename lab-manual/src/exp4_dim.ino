/************************************
	PWM Output			
	Example Code: 		
	R. Benkoczi
*************************************
Assign the LED intensity randomly
*************************************/

const int LED_pin = 9; // PWM pin
  
void setup() {
  randomSeed(analogRead(1));
}  

void loop() {
  int LED_intensity = random(0,256);

  // change the intensity
  analogWrite(LED_pin, LED_intensity);
  delay(1000);
}
