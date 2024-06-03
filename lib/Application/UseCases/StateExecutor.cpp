#include "StateExecutor.hpp"


void StateExecutor::activatePort(int outputPin) {
    pinService.writePin(outputPin,  LIGHTON);
}

void StateExecutor::deactivatePort(int outputPin) {
    pinService.writePin(outputPin, LIGHTOFF);
}

void StateExecutor::disablePort(int outputPin) {
    pinService.setPinMode(outputPin, LIGHTOFF);
}
