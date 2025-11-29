# Introduction

This code is an IoT project that monitors temperature and humidity using the ESP8266 Wi-Fi module and a DHT11 sensor. The data is displayed on a web server running on the ESP8266 and can be sent to a remote server using HTTP POST requests.

  [![Build Status](https://img.shields.io/github/forks/YoussofKhawaja/IoT-Climate-Tracker.svg)](https://github.com/YoussofKhawaja/IoT-Climate-Tracker)
  [![Build Status](https://img.shields.io/github/stars/YoussofKhawaja/IoT-Climate-Tracker.svg)](https://github.com/YoussofKhawaja/IoT-Climate-Tracker)
  [![License](https://img.shields.io/github/license/YoussofKhawaja/IoT-Climate-Tracker.svg)](https://github.com/YoussofKhawaja/IoT-Climate-Tracker)
  ![Arduino](https://github.com/YoussofKhawaja/IoT-Climate-Tracker/actions/workflows/Arduino.yml/badge.svg)
  ![ASP Core](https://github.com/YoussofKhawaja/IoT-Climate-Tracker/actions/workflows/dotnet.yml/badge.svg)

## Preview for web server and api
- Web server from ESP8266 not public its local use only.
- [API](https://localweather-api.youssofkhawaja.com/api/DHTData) (Get everything in database saved)
- [API](https://localweather-api.youssofkhawaja.com/api/DHTData/last) (Last data from database by Datetime)

## Requirements

- ESP8266 Wi-Fi module
- DHT11 sensor
- Arduino IDE
- ESP8266 Libraries (ESP8266WiFi, WiFiClient, ESP8266WebServer, ESP8266HTTPClient, and DHT)
- .Net 7
- postgreSQL

## Installation

1. Install the required libraries in the Arduino IDE:
    - ESP8266WiFi
    - WiFiClient
    - ESP8266WebServer
    - ESP8266HTTPClient
    - DHT
2. Clone or download the repository to your local machine.
3. Open the .ino file in the Arduino IDE and replace the placeholder values for ssid, password, and host with your Wi-Fi credentials and the URL of the remote server.
4. Connect the ESP8266 module and the DHT11 sensor to the board following the pin assignments in the code.
5. Upload the code to the board and check the serial monitor for the IP address of the web server.
6. Install .NET Core 7 on your local machine.
7. Open the solution in Visual Studio and edit the appsettings.json file to include the connection string for your PostgreSQL Server database.
8. Build and run the solution.

## Connection diagram
The connection diagram shows how to connect the DHT11 sensor to the ESP8266:
- Connect the VCC pin of the sensor to 3.3V on the ESP8266.
- Connect the GND pin of the sensor to GND on the ESP8266.
- Connect the data pin of the sensor to digital pin 2 (D4) on the ESP8266.

## Usage

Once the code is uploaded and the board is connected to the Wi-Fi network, you can access the web page displaying the temperature and humidity data by visiting the IP address of the ESP8266 in a web browser. The data will be sent to the remote server at regular intervals specified in the code.

## Contributing

If you would like to contribute to this project, you can submit a pull request or open an issue on the GitHub repository.
