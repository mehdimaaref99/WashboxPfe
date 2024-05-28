#ifndef ESP32_PIN_SERVICE_HPP
#define ESP32_PIN_SERVICE_HPP

#include "../../domain/Services/PinService.hpp"

class ESP32PinService : public PinService {
public:
    bool readPin(int pin) override;
    void writePin(int pin, bool state) override;
};

#endif // ESP32_PIN_SERVICE_HPP
