#include <Arduino.h>
#include "tx.h"
#include "ota.h"

void setup() {
  Serial.begin(115200);
  otaInit(); // OTA Initialization
  txinit(); // Transmitter Initialization
}

void loop() {
  commandLogics(); // Sending command with logic
  otaHandler(); // OTA Handling
}