#include "MQTTService.hpp"
#include <Arduino.h>

MQTTService::MQTTService(const char* broker, int port) : broker(broker), port(port), client(256) {}

void MQTTService::setup() {
    client.begin(broker, wifiClient);
    while (!client.connect("ESP32Client")) {
        delay(1000);
        Serial.println("Connecting to MQTT Broker...");
    }
    Serial.println("Connected to MQTT Broker!");
}

void MQTTService::loop() {
    client.loop();
}

void MQTTService::publish(const char* topic, const char* message) {
    if (client.connected()) {
        client.publish(topic, message);
    } else {
        Serial.println("MQTT not connected. Cannot publish message.");
    }
}

void MQTTService::subscribe(const char* topic, MQTTClientCallbackSimple callback) {
    if (client.connected()) {
        client.onMessage(callback);
        client.subscribe(topic);
        Serial.print("Subscribed to topic: ");
        Serial.println(topic);
    } else {
        Serial.println("MQTT not connected. Cannot subscribe to topic.");
    }
}

bool MQTTService::isConnected() {
    return client.connected();
}
