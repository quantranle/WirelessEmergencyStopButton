#include <Arduino.h>

// Define the LED pin number
const int LED_PIN = 2;

void setup() {
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);

  // Wait for 500ms
  delay(500);

  // Turn the LED off
  digitalWrite(LED_PIN, LOW);

  // Wait for 500ms
  delay(500);
}