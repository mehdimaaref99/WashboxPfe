#ifndef ESP32_FILE_SERVICE_HPP
#define ESP32_FILE_SERVICE_HPP


#include "../../domain/Services/FileService.hpp"
#include <FS.h>
#include <SPIFFS.h>
#include <string>

class ESP32FileService : public FileService {
public:
    ESP32FileService();
    std::string readFile(const char* path) override;
    void writeFile(const char* path, const std::string& content) override;
};

#endif // ESP32_FILE_SERVICE_HPP 
