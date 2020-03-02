#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <ThingsBoard.h>

#define WIFI_AP "GrifW1"
#define WIFI_PASSWORD "kb,J5jQdFH(]8"

#define TOKEN "jrQ6quFO7tb3Vaxweikg"

#define THINGSBOARD_SERVER "192.168.1.219"

int Analog;

int status = WL_IDLE_STATUS;

WiFiClient wifiClient;
WiFiClient wifiClient2;

ThingsBoard tb(wifiClient);
PubSubClient client(THINGSBOARD_SERVER,1885,wifiClient2);

void InitWiFi()
{
  
  Serial.println("Connecting to AP ...");
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");

}

void reconnect() {

  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      
      delay(500);
      Serial.print(".");
    
    }
    Serial.println("Connected to AP");
  }
  
}


void vibration(){

  //Analog = Serial.parseInt();
  Analog = random(0,20);
  Serial.println(Analog);
  delay(100);

}


void setup() {
  
   Serial.begin(11520);
   InitWiFi();
   reconnect();
   client.connect((char*)121221);

}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  }

  if (!tb.connected()) {
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      delay(1000);
      return;
    }
  }

  client.publish("test", "hello from ESP8266");

  vibration();
  Serial.println(Analog);
    tb.sendTelemetryInt("Vibration",Analog);
  tb.loop();
}
