#include <Arduino.h>
#include "../include/BspWash.hpp"
#include "../lib/application/UseCases/PinController.hpp"
#include "../lib/application/UseCases/StateExecutor.hpp"
#include "../lib/domain/Entities/PinPair.hpp"
#include "../lib/infrastructure/Hardware/ESP32PinService.hpp"
#include "../lib/domain/Services/PinService.hpp"

// Function declarations
void configSystem();
void configApplication();

// Global instances
ESP32PinService pinService;
PinController* pinController;
StateExecutor* stateExecutor;

void setup() {
    Serial.begin(115200);

    configSystem();
    configApplication();
}

void loop() {
    // Main loop code
    // Update pin states, handle events, etc.
    delay(100); // Adjust delay as needed
    // State Executor
      if (Serial.available()) {
        char command = Serial.read();
        switch (command) {
            case 'a': // Activate a port (example)
                stateExecutor->activatePort(PIN_O1);
                break;
            case 'd': // Deactivate a port (example)
                stateExecutor->deactivatePort(PIN_O1);
                break;
            case 'x': // Disable a port (example)
                stateExecutor->disablePort(PIN_O1);
                break;
            default:
                break;
        }
    }
}

void configSystem() {
    // Define initial pin pairs (input pin, output pin)
    std::vector<PinPair> pinPairs = {
        PinPair(PIN_I1, PIN_O1),
        PinPair(PIN_I2, PIN_O2),
        PinPair(PIN_I3, PIN_O3),
        PinPair(PIN_I4, PIN_O4),
        PinPair(PIN_I5, PIN_O5)
    };

    // Initialize pins
    for (const auto &pinPair : pinPairs) {
        pinMode(pinPair.getInputPin(), INPUT);
        pinMode(pinPair.getOutputPin(), OUTPUT);
    }
}

void configApplication() {
   // ESP32PinService pinService;

    // Define initial pin pairs (input pin, output pin)
    std::vector<PinPair> pinPairs = {
        PinPair(PIN_I1, PIN_O1),
        PinPair(PIN_I2, PIN_O2),
        PinPair(PIN_I3, PIN_O3),
        PinPair(PIN_I4, PIN_O4),
        PinPair(PIN_I5, PIN_O5)
    };

   // PinController pinController(pinService, pinPairs);
    pinController = new PinController(pinService, pinPairs);
    stateExecutor = new StateExecutor(pinService);

    // Example of dynamically updating pin pairs (this could be triggered by some event or command)
    // Remove a pin pair
    pinController->removePinPair(PIN_I2);

    // Add a new pin pair
    pinController->addPinPair(PinPair(PIN_I4, PIN_O2));

    // Update an existing pin pair
    pinController->updatePinPair(PIN_I5, PinPair(PIN_I5, PIN_O4));
}
