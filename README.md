# Temperature and Humidity Sensor

This project uses an Arduino Uno and a DHT22 sensor to measure temperature and humidity and send the data to a web API.

## Hardware components
- Arduino Uno
- DHT22 sensor
- Breadboard
- Jumper wires
- USB cable

## Software components
- Arduino Integrated Development Environment (IDE)
- DHT sensor library

## Connection diagram
The connection diagram shows how to connect the DHT22 sensor to the Arduino Uno:
- Connect the VCC pin of the sensor to 3.3V on the Arduino.
- Connect the GND pin of the sensor to GND on the Arduino.
- Connect the data pin of the sensor to digital pin 2 on the Arduino.

## Code
The code for this project consists of two parts: the setup function and the loop function.
- The setup function initializes the serial communication, the DHT sensor and the API endpoint.
- The loop function reads the temperature and humidity values from the DHT sensor, sends the data to the API endpoint and logs the response to the serial monitor.

## Installation
- Install the Arduino IDE from the official website.
- Connect the hardware components as shown in the connection diagram.
- Download the DHT sensor library and install it in the Arduino IDE.
- Download the code for this project and open it in the Arduino IDE.
- Update the API endpoint and other variables in the code as needed.
- Upload the code to the Arduino Uno.
- Open the serial monitor in the Arduino IDE to view the log messages.

## Contributing
If you have any suggestions or improvements for this project, feel free to open a pull request on GitHub.
