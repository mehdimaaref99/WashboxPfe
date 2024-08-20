#ifndef FILE_SERVICE_HPP
#define FILE_SERVICE_HPP

#include <string>

class FileService {
public:
    virtual void writeFile(const std::string& path, const std::string& message) = 0;
    virtual std::string readFile(const char* path) = 0; // Ensure this method is virtual and matches
};

#endif
