/*************************************
	Push Button Digital I/O		
	Example Code: 					
	N.Reed Parsons 2017
  revised by R. Benkoczi
*************************************
 Push button to turn a LED on/off
***********************************/

const int button_pin = 2;     
const int LED_pin = 13;    
int LED_state;  // state of LED: false (0) = off, true (non-zero) = on

void setup() {
  pinMode(LED_pin, OUTPUT);      
  pinMode(button_pin, INPUT);
	LED_state = 0;  // LED is initially off
	setLED(LED_state);  // turn the LED off initially
}

void loop() {
	//Read button state//
	if (isButtonPressed()) {
		// toggle LED state only if button is pressed
		LED_state = !LED_state;  // toggle the state variable |\label{a2:toggle}|
		setLED(LED_state);   // light the LED according to state
		delay(500);  // once state is changed, do not read the
		             // button too quickly to change LED back again
	}
}

// RETURN: 0 (false) if button is not pressed
//         non-zero (true) if button is pressed
int isButtonPressed() {
	int button_state = digitalRead(button_pin);
	// we do not wish to read the input pin too frequently...
	delay(125);
	// if button pressed, we read LOW
	return (button_state == LOW);
}

// state = true: turn the LED on, otherwise turn LED off
void setLED(int state) {
	if (state) // on
		digitalWrite(LED_pin, HIGH);
	else
		digitalWrite(LED_pin, LOW);
}
