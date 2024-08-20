#include "ESP32PinService.hpp"
#include <Arduino.h>

bool ESP32PinService::readPin(int pin) {
    return digitalRead(pin);
}

void ESP32PinService::writePin(int pin, bool state) {
    digitalWrite(pin, state);
}
void ESP32PinService::setPinMode(int pin, int mode) {
    pinMode(pin, mode);
}
void ESP32PinService::initializePins() {
    pinMode(13, OUTPUT);  // Example: Initialize GPIO 13 as output
    // Initialize other pins as needed
}
