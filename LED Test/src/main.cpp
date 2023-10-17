#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 4
#define LED_COUNT 1

CRGB leds[LED_COUNT];

void setup() {
  Serial.begin(9600);
  while (! Serial) {
    delay(1);
  }
  Serial.println("Initialize");

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0] = CRGB::Blue;
  FastLED.show();
}
