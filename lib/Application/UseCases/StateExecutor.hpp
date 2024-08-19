#ifndef STATE_EXECUTOR_HPP
#define STATE_EXECUTOR_HPP

#include "../../../include/BspWash.hpp"
#include "../../domain/Services/PinService.hpp"
#include "../../domain/Services/FileService.hpp"


class StateExecutor {
public:
    
    
    StateExecutor(PinService& pinService, FileService& fileService)
        : pinService(pinService), fileService(fileService) {}

    void activatePort(int outputPin);
    void deactivatePort(int outputPin);
    void disablePort(int outputPin);
     std::string readTestFile();

private:
    PinService& pinService;
    FileService& fileService;

};

#endif // STATE_EXECUTOR_HPP
