#include <Arduino.h>
#include <ESP8266WiFi.h>  // Include the ESP8266 Wi-Fi library

const int buttonPin = D5;  // Define the GPIO pin for the button
int buttonState = 0;       // Variable to store the button state

// Function to enter light sleep mode
void enterLightSleep() {
  Serial.println("Entering light sleep mode...");

  // Turn off the Wi-Fi to save power
  WiFi.forceSleepBegin();  // Enter modem sleep (low power)
  delay(10);               // Allow some time for sleep mode to stabilize
  
  // Stay in light sleep until a button press wakes it up
  // You can reduce this time to a smaller delay if necessary
  delay(10000000);  // Large delay keeps the ESP8266 in light sleep mode
  
  // Once woken up, the ESP8266 will exit light sleep and resume here
  WiFi.forceSleepWake();  // Wake up from modem sleep
  Serial.println("Woke up from light sleep.");
}

void setup() {
  Serial.begin(115200);  // Start serial communication for debugging
  delay(1000);
  // Configure GPIO D5 as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Print initial message
  Serial.println("System ready. Press the button to wake from light sleep.");
}

void loop() {
  // Read the button state (LOW when pressed, HIGH when not pressed)
  buttonState = digitalRead(buttonPin);

  // If the button is pressed
  if (buttonState == LOW) {
    Serial.println("Button pressed, waking up!");
    delay(500);  // Simple delay to debounce the button
    // Do something after wake-up, e.g., send a message, trigger an action, etc.
  } else {
    // If the button is not pressed, enter light sleep mode
    enterLightSleep();
  }
  
  delay(100);  // Debounce the button
}

