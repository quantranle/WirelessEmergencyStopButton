#include <Arduino.h>

/*
 * This ESP8266 NodeMCU code was developed by newbiely.com
 *
 * This ESP8266 NodeMCU code is made available for public use without any restriction
 *
 * For comprehensive instructions and wiring diagrams, please visit:
 * https://newbiely.com/tutorials/esp8266/esp8266-button-led
 */

#define BUTTON_PIN D1  // The ESP8266 pin D1 connected to button
#define LED_PIN    D0  // The ESP8266 pin D0 connected to led

int button_state = 0;   // variable for reading the button status

void setup() {
  // Configure the LED pin as a digital output
  pinMode(LED_PIN, OUTPUT);
  // Configure the ESP8266 pin as a pull-up input: HIGH when the button is open, LOW when pressed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // read the state of the button value:
  button_state = digitalRead(BUTTON_PIN);

  // control LED according to the state of button
  if (button_state == LOW)       // if button is pressed
    digitalWrite(LED_PIN, HIGH); // turn on LED
  else                           // otherwise, button is not pressing
    digitalWrite(LED_PIN, LOW);  // turn off LED
}
