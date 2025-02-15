#include <Arduino.h>

/*
 * This ESP8266 NodeMCU code was developed by newbiely.com
 *
 * This ESP8266 NodeMCU code is made available for public use without any restriction
 *
 * For comprehensive instructions and wiring diagrams, please visit:
 * https://newbiely.com/tutorials/esp8266/esp8266-button-piezo-buzzer
 */

#define BUTTON_PIN D1 // The ESP8266 pin connected to button's pin
#define BUZZER_PIN D8 // The ESP8266 pin connected to Buzzer's pin
#define LED_PIN D5     // LED is connected to D5

void setup() {
  Serial.begin(9600);                // Initialize the Serial to communicate with the Serial Monitor.
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configure the ESP8266 pin to the input pull-up mode
  pinMode(BUZZER_PIN, OUTPUT);       // Configure the ESP8266 pin to the output mode
  pinMode(LED_PIN, OUTPUT);           // LED is connected to D5 (output)
}

void loop() {
  int button_state = digitalRead(BUTTON_PIN); // read new state

  if (button_state == LOW) {
    Serial.println("The button is being pressed");
    digitalWrite(BUZZER_PIN, HIGH); // turn on
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
  }
  else
  if (button_state == HIGH) {
    Serial.println("The button is unpressed");
    digitalWrite(BUZZER_PIN, LOW);  // turn off
    digitalWrite(LED_PIN, LOW);  // Turn off the LED
  }
}







