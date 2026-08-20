#include <Arduino.h>
#include <fauxmoESP.h>
#include "alexa.h"
#include "tx.h"

fauxmoESP fauxmo;

void alexaInit() {
    fauxmo.createServer(true);
    fauxmo.setPort(80);
    fauxmo.enable(true);

    fauxmo.addDevice("Power");
    fauxmo.addDevice("Swing");
    fauxmo.addDevice("Fan Mode");
    fauxmo.addDevice("Speed Up");
    fauxmo.addDevice("Speed Down");
    fauxmo.addDevice("Timer");
    fauxmo.addDevice("Lock");

    fauxmo.onSetState([](unsigned char device_id, const char* device_name, bool state, unsigned char value) {
        Serial.printf("[Alexa] device= %s state=%s state=%d\n", device_name, state);

        if (!state) return; // "turn off" is meaningless for a momentary button press

        if (strcmp(device_name, "Power") == 0) sendCode(powerRaw, "Power");
        else if (strcmp(device_name, "Swing") == 0) sendCode(swingRaw, "Swing");
        else if (strcmp(device_name, "Fan Mode") == 0) sendCode(modeRaw, "Fan Mode");
        else if (strcmp(device_name, "Speed Up") == 0) sendCode(speedUpRaw, "Speed +");
        else if (strcmp(device_name, "Speed Down") == 0) sendCode(speedDownRaw, "Speed -");
        else if (strcmp(device_name, "Timer") == 0) sendCode(timerRaw, "Timer");
        else if (strcmp(device_name, "Lock") == 0) sendCode(lockRaw, "Lock");
    });
    Serial.println("[Alexa] fauxmo initialized, 7 devices registered");
}

void alexaHandle() {
    fauxmo.handle();
}