/*************************************
		Analog in Digital out		
		Example Code: 					
		N.Reed Parsons 2017 
		revised R. Benkoczi
*************************************
 Output the analog value of the	
 potentiometer to the IDE serial	
 console							
*************************************/

// input pin:
const int potentiometer_pin = 1 ; 
  
void setup() {
  Serial.begin(9600); // initialize the serial port |\label{a3:begin}|
}

void loop() {
	// variable to store the voltage 
	int value;  
	value = analogRead(potentiometer_pin); 
	Serial.println(value);  // send the value to the serial monitor window |\label{a3:println}|
	delay(500);  // avoid reading too frequently...
}
