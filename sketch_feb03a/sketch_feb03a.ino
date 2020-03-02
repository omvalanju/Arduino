#include <ESP8266WiFiType.h>
#include <CertStoreBearSSL.h>
#include <WiFiClient.h>
#include <ESP8266WiFiAP.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiClientSecureBearSSL.h>
#include <ESP8266WiFiScan.h>
#include <WiFiClientSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiUdp.h>
#include <WiFiServer.h>
#include <BearSSLHelpers.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiServerSecure.h>
#include <ESP8266WiFiSTA.h>

       // Include the Wi-Fi library

const char* ssid     = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "PASSWORD";     // The password of the Wi-Fi network

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() { }
