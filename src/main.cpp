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
ESP32FileService fileService;


// Time tracking for reading the file 
unsigned long lastReadTime = 0;
const unsigned long readInterval = 60000; // 1 minute in milliseconds




void setup() {

    Serial.begin(115200);
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    connectToWiFi();
    configSystem();
    configApplication();
   mqttService.setup();
  // mqttService.subscribe("test", messageReceivedCallback);
   mqttService.subscribe("machines", messageReceivedCallback);
    testFileOperations();
}

void messageReceivedCallback(String &topic, String &payload) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
     // Save received message to file
    fileService.writeFile("/received_messages.txt", payload.c_str());

    if (topic == "machines") {
        if (payload == "1") {
            digitalWrite(OUT_1, PIN_ON ); // Activate GPIO 23
            Serial.println("GPIO 13 activated.");
        } else if (payload == "0") {
            digitalWrite(OUT_1, PIN_OFF); // Deactivate GPIO 23
            Serial.println("GPIO 13 deactivated.");
        } else {
            Serial.println("Unknown payload received.");
        }
    }
    // Save received message to file
    fileService.writeFile("/received_messages.txt", payload.c_str());

}


void connectToWiFi() {
    wifiService = new WiFiService();
    wifiService->connectToWiFi("H267A_C0BE_2.4G", "xQ9Zks6N");
}

void configSystem() {
    pinMode(23, OUTPUT); 
    

    // Your implementation
}

void configApplication() {
    // Your implementation
}

void testFileOperations() {
     fileService.writeFile("/test_message.txt", "Initial content.");
    String fileContent = fileService.readFile("/test_message.txt").c_str();
    Serial.println("File Content:");
    Serial.println(fileContent);
    // Your implementation
}
void readFromFile() {
    // Read file content
    String fileContent = fileService.readFile("/received_messages.txt").c_str();
    Serial.println("Read from file:");
    Serial.println(fileContent);
}



void loop() {
    
    
      mqttService.loop();
     // mqttService.publish("test", "Hello, my server!");
      mqttService.isConnected();
      unsigned long currentTime = millis();
    if (currentTime - lastReadTime >= readInterval) {
        lastReadTime = currentTime;
        readFromFile();
    }
      delay(10000);
      

    } 

 
    

