#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>
#include "secrets.h"

// Wifi credentials
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

bool otaInProgress = false;

void otaInit() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("Conntecting to Wifi...");
    }
    Serial.println("Connected! IP: " + WiFi.localIP().toString());

    ArduinoOTA.setHostname(OTA_HOSTNAME);
    ArduinoOTA.setPassword(OTA_PASSWORD);

    ArduinoOTA.onStart([]() {
        String type = (ArduinoOTA.getCommand() == U_FLASH) ? "sketch" : "filesystem";
        Serial.println("Start updating " + type);
        otaInProgress = true;
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("\nUpdate Complete");
        otaInProgress = false;
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        static int lastBucket = -1;
        unsigned int percent = progress / (total / 100);
        int bucket = percent / 10; // groups 0-9%, 10-19%, ... into one print each
        if (bucket != lastBucket) {
        Serial.printf("Progress: %u%%\r\n", percent);
        lastBucket = bucket;
        }
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        otaInProgress = false;
        if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

    ArduinoOTA.begin();
    MDNS.end();
    Serial.println("OTA Ready");
}

void otaHandler() {
    ArduinoOTA.handle();
}