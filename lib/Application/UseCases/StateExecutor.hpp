#ifndef STATE_EXECUTOR_HPP
#define STATE_EXECUTOR_HPP

#include "../../../include/BspWash.hpp"
#include "../../domain/Services/PinService.hpp"


class StateExecutor {
public:
    StateExecutor(PinService& pinService) : pinService(pinService) {}

    void activatePort(int outputPin);
    void deactivatePort(int outputPin);
    void disablePort(int outputPin);

private:
    PinService& pinService;
};

#endif // STATE_EXECUTOR_HPP
