#ifndef BROKER_COMMUNICATION_HPP
#define BROKER_COMMUNICATION_HPP

#include "../../domain/Services/MQTTService.hpp"

class BrokerCommunication {
public:
    BrokerCommunication(MQTTService& mqttService);
    void setup();

private:
    MQTTService& mqttService;

    // Static callback function declaration
    static void mqttCallback(String &topic, String &payload);
};

#endif // BROKER_COMMUNICATION_HPP
