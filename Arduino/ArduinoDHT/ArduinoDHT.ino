#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

// Replace with your network credentials
const char *ssid = "wifi";
const char *password = "pwd";
const String host = "url";
const int httpPort = 80;

unsigned long previousMillis = 0;
unsigned long interval = 600000; // interval in milliseconds

// Pin definitions
#define DHT_PIN 2

// Initialize the DHT sensor
DHT dht(DHT_PIN, DHT11);

ESP8266WebServer server(httpPort);

void setup()
{
  // Start the serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP address: " + WiFi.localIP().toString());

  // Start the DHT sensor
  dht.begin();

  // Set up the web server
  server.on("/", []()
            {
    String message = "<html><body style='background-color:black;'><h1 style='color:white;'>Temperature and Humidity</h1>";
    message += "<p style='color:white;'>Temperature: " + String(dht.readTemperature()) + " &#8451;</p>";
    message += "<p style='color:white;'>Humidity: " + String(dht.readHumidity()) + " %</p></body></html>";
    server.send(200, "text/html", message); });
  server.begin();
  Serial.println("Web server started!");
}

void postData(String id, float temperature, float humidity, String timestamp, String location)
{
  HTTPClient http;
  WiFiClient client;
  http.begin(client, host);
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<200> doc;
  doc["Id"] = id;
  doc["Temperature"] = temperature;
  doc["Humidity"] = humidity;
  doc["Timestamp"] = timestamp;
  doc["Location"] = location;

  String payload;
  serializeJson(doc, payload);

  int httpResponseCode = http.POST(payload);
  if (httpResponseCode > 0)
  {
    Serial.println("Data sent successfully.");
  }
  else
  {
    Serial.println("Error sending data.");
  }
  http.end();
}

void loop()
{
  server.handleClient();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // You could replace delay with a call to millis() to track the time elapsed
  // between two consecutive calls to postData.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time you updated the data
    previousMillis = currentMillis;
    // post the data
    postData("3fa85f64-5717-4562-b3fc-2c963f66afa6", temperature, humidity, "2023-02-08T18:23:38Z", "lebanon");
  }
}