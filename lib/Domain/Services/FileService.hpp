#ifndef FILE_SERVICE_HPP
#define FILE_SERVICE_HPP

#include <string>

class FileService {
public:
    virtual ~FileService() {}
    virtual std::string readFile(const char* path) = 0;
    virtual void writeFile(const char* path, const std::string& content) = 0;
};

#endif // FILE_SERVICE_HPP
