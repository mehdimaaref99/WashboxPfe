#include <Arduino.h>
#include "../include/BspWash.hpp"
#include "../lib/application/UseCases/PinController.hpp"
#include "../lib/application/UseCases/StateExecutor.hpp"
#include "../lib/domain/Entities/PinPair.hpp"
#include "../lib/infrastructure/Hardware/ESP32PinService.hpp"
#include "../lib/infrastructure/Filesystem/ESP32FileService.hpp"
#include "../lib/infrastructure/Network/BrokerCommunication.hpp"
#include "../lib/domain/Services/PinService.hpp"
#include "../lib/domain/Services/FileService.hpp"
#include "../lib/domain/Services/MQTTService.hpp"
#include "../lib/domain/Services/WifiService.hpp"

#include "SPIFFS.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <MQTT.h>
#include <WiFi.h>


// Function declarations
void configSystem();
void configApplication();
void testFileOperations();
//void brokerCommunication();
void connectToWiFi();
void messageReceivedCallback(String &topic, String &payload);


// Global instances
//ESP32PinService pinService;
//ESP32FileService fileService;
//PinController* pinController;
//StateExecutor* stateExecutor;
WiFiService* wifiService;
MQTTService mqttService("192.168.100.72", 1883);
BrokerCommunication brokerComms(mqttService); 

void setup() {

    Serial.begin(115200);
    connectToWiFi();
    configSystem();
    configApplication();
   mqttService.setup();
   mqttService.subscribe("test", messageReceivedCallback);
    testFileOperations();
}
void messageReceivedCallback(String &topic, String &payload) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
}
void connectToWiFi() {
    wifiService = new WiFiService();
    wifiService->connectToWiFi("H267A_C0BE_2.4G", "xQ9Zks6N");
}

void configSystem() {
    // Your implementation
}

void configApplication() {
    // Your implementation
}

void testFileOperations() {
    // Your implementation
}



void loop() {
    
    
      mqttService.loop();
      mqttService.publish("test", "Hello, my server!");
      mqttService.isConnected();
      delay(10000);
      

    } 

 
    

