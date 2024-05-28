#ifndef PIN_SERVICE_HPP
#define PIN_SERVICE_HPP

#include "../Entities/PinPair.hpp"

class PinService {
public:
    virtual bool readPin(int pin) = 0;
    virtual void writePin(int pin, bool state) = 0;
};

#endif // PIN_SERVICE_HPP
