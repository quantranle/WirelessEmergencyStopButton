//Transmitter

#include <ESP8266WiFi.h>

const char* ssid = "ESP8266_Master";  // Access Point SSID
const char* password = "21032002";    // Access Point Password

WiFiServer server(80);

const int buttonPin = 0; // Button connected to GPIO0
bool buttonState = false; // Tracks the button state

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password); // Set up as Access Point

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin(); // Start TCP server

  pinMode(buttonPin, INPUT_PULLUP); // Configure button as input with pull-up resistor
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      buttonState = digitalRead(buttonPin) == LOW; // Check if the button is pressed
      
      // Send button state to the client
      if (buttonState) {
        client.println("RED"); // Send "RED" to turn on the RED LED and turn off GREEN
        Serial.println("Sent: RED");
      } else {
        client.println("GREEN"); // Send "GREEN" to turn on the GREEN LED
        Serial.println("Sent: GREEN");
      }
      
      delay(200); // Delay to reduce rapid updates
    }
    client.flush();
    client.stop(); // Terminate the connection with the client
    Serial.println("Client disconnected");
  }
}
