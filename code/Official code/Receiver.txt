// Receiver

#include <ESP8266WiFi.h>

const char* ssid = "ESP8266_Master";  // Access Point SSID
const char* password = "21032002";    // Access Point Password

WiFiClient client;

const int redLEDPin = 4;   // RED LED connected to GPIO16
const int greenLEDPin = 16;  // GREEN LED connected to GPIO4
const int buzzerPin = 15;   // Buzzer connected to D4

void setup() {
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

  // Start with GREEN LED ON, RED LED OFF, and Buzzer OFF
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(redLEDPin, LOW);
  digitalWrite(buzzerPin, LOW);

  WiFi.begin(ssid, password); // Connect to the transmitter's Access Point
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Transmitter...");
  }
  Serial.println("Connected to Transmitter");
  Serial.println(WiFi.localIP());
}

void playSOS() {
  // SOS Pattern
  for (int i = 0; i < 3; i++) { // Three short beeps for "S"
    digitalWrite(buzzerPin, HIGH);
    delay(200); // Short beep (dot)
    digitalWrite(buzzerPin, LOW);
    delay(200); // Pause between beeps
  }
  for (int i = 0; i < 3; i++) { // Three long beeps for "O"
    digitalWrite(buzzerPin, HIGH);
    delay(600); // Long beep (dash)
    digitalWrite(buzzerPin, LOW);
    delay(200); // Pause between beeps
  }
  for (int i = 0; i < 3; i++) { // Three short beeps for "S"
    digitalWrite(buzzerPin, HIGH);
    delay(200); // Short beep (dot)
    digitalWrite(buzzerPin, LOW);
    delay(200); // Pause between beeps
  }
}

void loop() {
  if (!client.connected()) {
    client.connect(WiFi.gatewayIP(), 80); // Connect to the Transmitter
  }

  if (client.available()) {
    String message = client.readStringUntil('\n'); // Read signal from Transmitter
    message.trim(); // Remove any extra characters

    if (message == "RED") {
      // Turn RED LED ON, GREEN LED OFF, and play SOS sound
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);
      Serial.println("RED LED ON, GREEN LED OFF, SOS Sound Playing");
      playSOS(); // Play SOS pattern
    } else if (message == "GREEN") {
      // Turn GREEN LED ON, RED LED OFF, and Buzzer OFF
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(buzzerPin, LOW); // Ensure Buzzer is OFF
      Serial.println("GREEN LED ON, RED LED OFF, BUZZER OFF");
    }
  }
}
