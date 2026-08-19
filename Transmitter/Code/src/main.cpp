#include <Arduino.h>
#include "tx.h"
#include "ota.h"
#include "alexa.h"

void setup() {
  Serial.begin(115200);
  otaInit(); // OTA Initialization
  alexaInit(); // Alexa Initialization
  txinit(); // Transmitter Initialization
}

void loop() {
  commandLogics(); // Sending command with logic
  otaHandler(); // OTA Handling
  alexaHandle(); // Alexa Handling
}