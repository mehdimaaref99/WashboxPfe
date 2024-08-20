#include "ESP32FileService.hpp"
#include <SPIFFS.h>


ESP32FileService::ESP32FileService() {
   
}

void ESP32FileService::writeFile(const std::string& path, const std::string& message) {
    File file = SPIFFS.open(path.c_str(), FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.println(message.c_str());
    file.close();
}

std::string ESP32FileService::readFile(const char* path) {
    File file = SPIFFS.open(path, FILE_READ);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return "";
    }
    std::string content;
    while (file.available()) {
        content += static_cast<char>(file.read());
    }
    file.close();
    return content;
}
