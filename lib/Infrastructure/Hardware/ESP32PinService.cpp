#include "ESP32PinService.hpp"
#include <Arduino.h>

bool ESP32PinService::readPin(int pin) {
    return digitalRead(pin);
}

void ESP32PinService::writePin(int pin, bool state) {
    digitalWrite(pin, state);
}
