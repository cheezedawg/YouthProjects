#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid     = "SheldonYM";

AsyncWebServer server(80);

void setup() {
  Serial.begin(9600);
  while (! Serial) {
    delay(1);
  }
  Serial.println("Initialize");

  Serial.print("Setting up an access point");
  WiFi.softAP(ssid);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Hello Sheldon YM!");
  });

  server.begin();
}

void loop() {
}

