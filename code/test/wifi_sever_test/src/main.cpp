#include <Arduino.h>

#include <ESP8266WiFi.h>

byte ledPin = 2;
const char* ssid = "ESP8266_Master";  // Access Point SSID
const char* password = "21032002";    // Access Point Password

WiFiServer server(80);                    

void setup() {
  Serial.begin(115200);    
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);             
  
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();  // Start TCP server
  pinMode(ledPin, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r');
        Serial.print("Received: ");
        Serial.println(request);

        // Send a response back to the client
        client.println("Message received");
      }
    }
    client.flush();
    client.stop();                // terminates the connection with the client
    Serial.println("Client disconnected");
  }
}
