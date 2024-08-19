#include "ESP32FileService.hpp"
#include <Arduino.h>

ESP32FileService::ESP32FileService() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
    }
}

std::string ESP32FileService::readFile(const char* path) {
    File file = SPIFFS.open(path, FILE_READ);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return "";
    }
    std::string content = "";
    while (file.available()) {
        content += (char)file.read();
    }
    file.close();
    return content;
}

void ESP32FileService::writeFile(const char* path, const std::string& content) {
    File file = SPIFFS.open(path, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.print(content.c_str());
    file.close();
}
