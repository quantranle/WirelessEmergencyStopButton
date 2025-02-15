# Wireless Emergency Stop Button

## Project  Overview
The Wireless Emergency Stop Button is designed to provide a reliable and immediate way to remotely halt the operation of robots, electric vehicles, or other automated systems. In this project, we use an ESP8266 microcontroller as the main component, paired with a mechanical emergency stop button. With our study case, the ESP8266 is one of wirelessly communication part in the emergency stop system of the Electrical Go-Cart.

## Key Features:
- **Mechanical Emergency Stop Button**: When pressed, the button sends an emergency signal via Wi-Fi and LoRa communication to the cart, triggering an immediate stop.

- **ESP8266 with Wireless Communication**: The ESP32 handles the wireless communication between the button and the target device, ensuring the stop signal is transmitted instantly.

- **Buzzer with alert sound**: when the mechanical button is pressed , the buzzer is activated with alert sound to make the notification for the user that emergency mode is enabled.

- **Status LEDs**: Two status LEDs provide a quick visual indication:
    - **Green LED**: Lights up when the system is in standby mode (button not pressed).

    - **Red LED**: Activates when the emergency button is pressed, confirming the stop signal has been sent.

## System Workflow:
1. **Normal Mode**: 
   - The green LED is on, indicating the system is monitoring and ready for input.
   
2. **Emergency Mode**: 
   - When the user presses the emergency stop button, the ESP8266 sends a stop signal wirelessly to the E Go-Cart.
   - Automatically, The green LED turns off and the red LED turns on, indicating the stop signal has been sent and the system is in emergency mode.

3. **Reset Mode**:
   - The system can be manually reset to resume normal operation after the emergency mode has been cancelled by holding the push button in 10 seconds.

## Components
- **ESP8266**: Handles wireless communication and the logic of the system.
- **Mechanical push button**: For triggering the emergency stop.
- **Buzzer**: Gives the alert sound when the emergency mode is activated.
- **Green and Red LEDs**: Visual indicators of the system’s status.
- **Power supply**: 4 AAA Alkaline Batteries.
- **Voltage regulator**: Regulate or step down the voltage to 3.3V.

## How to Set Up
1. **Hardware Setup**:
   - Connect the mechanical push button to one of the ESP32 GPIO pins.
   - Attach the green and red LEDs to separate GPIO pins.
   - Attach the buzzer to separate GPIO pins.
   - Power the ESP8266 with batteries connected through a voltage regulator to ESP32 GPIO pins to step down the voltage to 3.3V.

2. **Software Setup**:
   - Flash the ESP8266 with the firmware code that handles button input, LED control, wireless communication and Buzzer control.
   - Configure the cart to listen for the emergency stop signal from the ESP8266.

## How It Works
- **Step 1**: When the button is pressed, the ESP32 sends a stop signal to the E Go-Cart via Wi-Fi and LoRa communication.
- **Step 2**: The red LED lights up and the buzzer starts the sound.
- **Step 3**: The device immediately halts, ensuring a quick response to the emergency mode.
- **Step 4**: Once the emergency mode has been cancelled, the system will be reset to normal mode.