#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

// Replace with your network credentials
const char *ssid = "name";
const char *password = "pwd";
const String host = "url host";
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
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started!");
}

void handleRoot()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  String html = "<html><head><title>Tempreature and Humidity</title><style>body {background: linear-gradient(-45deg, #ff0000, #0000ff, #ff0000, #23d5ab);background-size: 400% 400%;animation: gradient 15s ease infinite;height: 100%;} .container {height: 100vh;display: flex;flex-direction: column;justify-content: center;align-items: center;} .header {color: rgba(255, 255, 255, 0.5);font-size: 10vw;} .subheader {color: rgba(255, 255, 255, 0.5);font-size: 7vw;} .refresh-button {margin-top: 10px;font-size: 5vw;animation: gradient 15s ease infinite;border: transparent;background-size: 400% 400%;background-image: linear-gradient(to right, #ff0000, #0000ff);border-radius: 10px;color: white;padding: 10px 20px;cursor: pointer;transition: 0.5s;} @media (min-width: 600px) {.header {font-size: 50px;} .subheader {font-size: 25px;} .refresh-button {font-size: 25px;}} @keyframes gradient {0% {background-position: 0% 50%;} 50% {background-position: 100% 50%;} 100% {background-position: 0% 50%;}}</style></head><body><div class='container'><div class='header'>IoT Climate Tracker</div><div style='text-align: center;'><div class='subheader'>Location: Lebanon - Tripoli</div><div class='subheader'>Temperature: <span id='temperature'>" + String(temperature) + "&#8451</span></div><div class='subheader'>Humidity: <span id='humidity'>" + String(humidity) + "%</span></div></div></body></html>";
  server.send(200, "text/html", html);
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