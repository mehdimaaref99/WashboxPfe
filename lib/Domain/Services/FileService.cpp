#include "FileService.hpp"
#include "SPIFFS.h"

void FileService::writeFile(const std::string& path, const std::string& message) {
    File file = SPIFFS.open(path.c_str(), FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.println(message.c_str());
    file.close();
}
