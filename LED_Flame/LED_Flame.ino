/**
 * LED Flame
 * 
 * This sketch mimics a natural gas flame. It is based on a Jacklyn Smith
 * Christmas Lantern purchased from Kmart. The effect looks very natural
 * behind a peice of frosted glass.
 * 
 * The circuit:
 * - Ardunio Uno or Arduino Nano
 * Inputs:
 * 	- NONE
 * Outputs:
 * 	- Yellow LED attached to pin 5
 * 	- Yellow LED attached to pin 6
 * 	- Yellow LED attached to pin 9
 * 	- Yellow LED attached to pin 10
 * 	- Yellow LED attached to pin 11
 * 
 * Created February, 2020
 * By Mike Risser
 */

/*
 * The following class is adapted from the article:
 * Multi-Tasking the Arduin - Part 2, Earl, Bill
 * https://learn.adafruit.com/multi-tasking-the-arduino-part-2?view=all
 */
class Flame {
  // Class Member variables; initialized at startup
  int ledPin;	// Number of the LED pin
  long OnTime;	// milliseconds of on time
  long OffTime;	// milliseconds of off time

  // These two variables store the state of the LED
  int ledState;					// The current state of the LED, either HIGH (on) or LOW (off)

  unsigned long previousMillis;	// Millis value of the previous update
								// We use an unsigned long because the value returned by millis()
								// is an unsigned long. If we were to use a long, the value from
								// millis() would overflow the long variable. (longs are smaller 
								// than unsigned longs)
  
  public:Flame(int pin, long on, long off) {
    ledPin = pin;				// Pin the LED is attached to
    pinMode(ledPin, OUTPUT);	// Set the pin to be an output

    OnTime = on;				// Amount of time (in milliseconds) that the LED should be on
    OffTime = off;				// Amount of time (in milliseconds) that the LED should be off

    ledState = LOW;				// Set the initial LED state to LOW (off)
    previousMillis = 0;			// Set the initial perviousMillis value to zero
  }
  
  /*
   * The Update function turns the LEDs on and off, determined by the OnTime and OffTime variables
   * to create the flame effect.
   */
  void Update(unsigned long currentMillis) {
	// If the LED is on and it's time to turn it off...
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
      ledState = LOW;  // ...turn it off
	
	// If the LED is off and it's time to turn it on...
    } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
      ledState = HIGH;  // ...turn it on
    }

    // I have moved these two lines out of the if statement
    // above as they are the same for both the if and else, no
    // need to duplicate them
    digitalWrite(ledPin, ledState); // Update the LED
    previousMillis = currentMillis; // Remember the time
  }
};

// Setup the LEDs, see the Flame function in the Flame class above
Flame led1(5, 400, 200);
Flame led2(6, 350, 350);
Flame led3(9, 200, 222);
Flame led4(10, 125, 400);
Flame led5(11, 100, 425);

void setup() {
  // We will be using a non-blocking timer, rather than delay(), so
  // that if we want to do something else, we don't have to stop and
  // wait for the LEDs to update.
  //
  // Here we are adjusting the timer register
  OCR0A = 0xAF;				// Sets the value to 
  TIMSK0 |= _BV(OCIE0A);	// Sets the interupt request
}

/* 
 * The following code is from:
 * Multi-Tasking the Arduino - 
 * https://learn.adafruit.com/multi-tasking-the-arduino-part-2?view=all
 *
 * Interrupt is called once a millisecond, to update the LEDs
 */
SIGNAL(TIMER0_COMPA_vect){
  unsigned long currentMillis = millis();
  
  led1.Update(currentMillis);
  led2.Update(currentMillis);
  led3.Update(currentMillis);
  led4.Update(currentMillis);
  led5.Update(currentMillis);
}

/*
 * Because we are using a seperate timer, we don't need to put any code
 * inside the loop, unless we want to do something else.
 */
void loop() {

}