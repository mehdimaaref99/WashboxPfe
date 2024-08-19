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
    testFileOperations();
    
   
   
}
void messageReceivedCallback(char* test, char* payload) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
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
    
    // Update pin states, handle events, etc.
      mqttService.loop();
      mqttService.publish("test", "Hello, my server!");
      void MQTTService::subscribe("test");
      mqttService.isConnected();
      delay(10000);
      
/*
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
        }*/
    } 

 
    

/*void configSystem() {

    // init all infrastructure services
    //1- timer
    //2- digital pins
    //3- file
    //4- network
    //5- tasks
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
    } }*/
    


   



  



/*void configApplication() {
  brokerComms.setup(); 
   
   //lecture des fichiers de configuration
   
    // Define initial pin pairs (input pin, output pin)
    std::vector<PinPair> pinPairs = {
        PinPair(PIN_I1, PIN_O1),
        PinPair(PIN_I2, PIN_O2),
        PinPair(PIN_I3, PIN_O3),
        PinPair(PIN_I4, PIN_O4),
        PinPair(PIN_I5, PIN_O5)
    };

    //PinController pinController(pinService, pinPairs);
    pinController = new PinController(pinService, pinPairs);
    stateExecutor = new StateExecutor(pinService, fileService);

    // Example of dynamically updating pin pairs (this could be triggered by some event or command)
    // Remove a pin pair
    pinController->removePinPair(PIN_I2);

    // Add a new pin pair
    pinController->addPinPair(PinPair(PIN_I4, PIN_O2));

    // Update an existing pin pair
    pinController->updatePinPair(PIN_I5, PinPair(PIN_I5, PIN_O4));
     
}*/


/*void testFileOperations() {
    // Write to the file
    fileService.writeFile("/test", "Hello, ESP32!");

    // Read from the file
    std::string content = fileService.readFile("/test");
    Serial.println("File Content:");
    Serial.println(content.c_str());
}*/
