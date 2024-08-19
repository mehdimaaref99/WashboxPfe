#include "BrokerCommunication.hpp"

BrokerCommunication::BrokerCommunication(MQTTService& mqttService) : mqttService(mqttService) {}

void BrokerCommunication::setup() {
    // Subscribe with the static callback function
    mqttService.subscribe("connexion", mqttCallback);
}

// Static callback function definition
void BrokerCommunication::mqttCallback(String &topic, String &payload) {
    Serial.print("Received message on topic: ");
    Serial.println(topic);
    Serial.print("Message payload: ");
    Serial.println(payload);
    // Handle the received message as needed
}
