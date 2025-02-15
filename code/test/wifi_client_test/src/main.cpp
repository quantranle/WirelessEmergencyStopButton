#include <Arduino.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

byte ledPin = 2;
const char* ssid = "ESP8266_Master";  // Access Point SSID
const char* password = "21032002";    // Access Point Password
const char* host = "192.168.4.1";     // Master's IP (default AP IP)
WiFiServer server(80);

void setup() {
  Serial.begin(115200);                   
  WiFi.begin(ssid, password); 
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);           
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
  pinMode(ledPin, OUTPUT);
}

void loop () {
  WiFiClient client;  
  
  if (!client.connect(host, 80)) {
    Serial.println("Connection failed");
    delay(1000);
    return;
  }

  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  
  // Send a message to the server
  client.println("Hello from slave");

  // Wait for a response from the server
  while (client.connected()) {
    if (client.available()) {
      String response = client.readStringUntil('\r');
      Serial.print("Received: ");
      Serial.println(response);
      break;
    }
  }

  client.stop();  // Disconnect
  digitalWrite(ledPin, HIGH);
  delay(2000);                  // client will trigger the communication after two seconds
}
