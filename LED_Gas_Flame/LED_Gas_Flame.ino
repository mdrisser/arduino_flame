/*
 * LED Gas Flame Effect
 * 
 * This sketch mimics a natural gas flame. It is based on a Jacklyn Smith
 * Christmas Lantern purchased from Kmart. The effect looks very natural
 * behind a peice of frosted glass.
 * 
 * The circuit:
 * - Ardunio Uno or Arduino Nano
 *   Inputs:
 * 	  - NONE
 *   Outputs:
 * 	  - Yellow LED attached to pin 5
 * 	  - Yellow LED attached to pin 6
 * 	  - Yellow LED attached to pin 9
 * 	  - Yellow LED attached to pin 10
 * 	  - Yellow LED attached to pin 11
 * 
 * Created February, 2020
 * By Mike Risser
 */

/*
 * Here, we're going to create some variables to be used later.
 * They are declared as constants(const) since they will not change
 * value during code execution.
 */
const int THRESHOLD_1 = 150;
const int THRESHOLD_2 = 100;
const int THRESHOLD_3 = 55;
const int THRESHOLD_4 = 20;

/*
 * Assign LEDs to the appropriate pins. The pins selected are
 * all capable of PWM (Pulse Width Modulation), which will
 * allow us to vary the brightness of the attached LED.
 */
const int LED_1 = 3;
const int LED_2 = 5;
const int LED_3 = 6;
const int LED_4 = 9;
const int LED_5 = 10;

/*
 * Function: fade(int increment, int wait)
 * 		performs the bulk of the work of the sketch,
 * 		turning the LEDs on (HIGH) or off (LOW) and
 * 		setting the brightness.
 * 
 * Parameter: int increment
 * 		the amount to change the fade value through
 * 		each iteration of the loop.
 * 
 * Parameter: int wait
 * 		the number of milliseconds to wait before
 * 		continuing through the loop.
 */
void fade(int increment, int wait) {
	// Loop from 255 down to 0, using the specified increment, or
	// in this case decrement...
	for(int fadeValue = 255; fadeValue >= 0; fadeValue -= increment) {
		// Send a PWM signal that effectively dims the LED
		analogWrite(LED_2, fadeValue);

		// Once we reach predefined thresholds, start dimming the
		// next LED in line...
		if(fadeValue > THRESHOLD_1) {
			analogWrite(LED_1, fadeValue);
		}

		// ... and the next...
		if(fadeValue > THRESHOLD_2) {
			analogWrite(LED_3, fadeValue - 60);
		}

		// ... and the next...
		if(fadeValue > THRESHOLD_3) {
			analogWrite(LED_4, fadeValue - 80);
		}

		// ... and the next...
		if(fadeValue > THRESHOLD_4) {
			analogWrite(LED_4, fadeValue - 100);
		}

		// Wait the specified number of milliseconds, then continue back at
		// the beginning of the loop.
		//
		// We *could* use millis() or another timer here, but since
		// all we're doing is playing with LEDs, there is no need to
		delay(wait);
	}

	// This loop is the reverse of the loop above, instead of dimming
	// the LEDs, we're going to make them brighter
	for(int fadeValue = 255; fadeValue >= 0; fadeValue += increment) {
		analogWrite(LED_2, fadeValue);

		if(fadeValue > THRESHOLD_1) {
			analogWrite(LED_1, fadeValue);
		}

		if(fadeValue > THRESHOLD_2) {
			analogWrite(LED_3, fadeValue + 60);
		}

		if(fadeValue > THRESHOLD_3) {
			analogWrite(LED_4, fadeValue + 80);
		}

		if(fadeValue > THRESHOLD_4) {
			analogWrite(LED_4, fadeValue + 100);
		}

		// Again, wait the specified number of milliseconds...
		delay(wait);
	}
}

/*
 * Function: setup()
 * 		The standard, and required, setup function which runs one
 * 		time, when the sketch first starts.
 */
void setup() {
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(LED_4, OUTPUT);
	pinMode(LED_5, OUTPUT);
}

/*
 * Function: loop()
 * 		The second of to required functions for an Arduino sketch.
 * 		The loop() function runs continually, over and over again,
 * 		while the Arduino is powered on.
 */
void loop() {
	fade(3,10);
}