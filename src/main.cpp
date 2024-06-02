// Based off FastLED Cylon.ino example; 
// An animation that moves a single LED back and forth (Larson Scanner effect)
#include <Arduino.h>
#include <FastLED.h>

#define DATA_PIN 3
//#define BUTTON_PIN 3

#define NUM_LEDS 20
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	delay(100);

	Serial.println("resetting");
	FastLED.addLeds<WS2812B,DATA_PIN,RGB>(leds,NUM_LEDS);
	FastLED.setBrightness(255);
  //  pinMode(BUTTON_PIN, INPUT);  // sets the digital pin 0 as input

}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
//  Serial.print( digitalRead(BUTTON_PIN));
	static uint8_t hue = 0;
	Serial.print("A");
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i] = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show(); 
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
	Serial.print("B");

	// Now go in the other direction.  
	for(int i = (NUM_LEDS)-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i] = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
  Serial.print("C");
}