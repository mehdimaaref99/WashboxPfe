#ifndef MQTT_SERVICE_HPP
#define MQTT_SERVICE_HPP

#include <WiFi.h>
#include <MQTT.h>

class MQTTService {
public:
    MQTTService(const char* broker, int port);
    void setup();
    void loop();
    void publish(const char* topic, const char* message);
    void subscribe(const char* topic, MQTTClientCallbackSimple callback);
    bool isConnected();

private:
    const char* broker;
    int port;
    WiFiClient wifiClient;
    MQTTClient client;
};

#endif // MQTT_SERVICE_HPP

