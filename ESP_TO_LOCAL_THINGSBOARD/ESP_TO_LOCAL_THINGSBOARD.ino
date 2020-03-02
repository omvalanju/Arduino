#include <ESP8266WiFi.h>
#include <ThingsBoard.h>

#define WIFI_AP "GrifW1"
#define WIFI_PASSWORD "kb,J5jQdFH(]8"

//#define TOKEN "4iL5XiWfKlIfZAd2g1Cv"
#define TOKEN "jrQ6quFO7tb3Vaxweikg"
//#define THINGSBOARD_SERVER  "cloud.thingsboard.io"
#define THINGSBOARD_SERVER  "192.168.1.219"

int Analog;

int status = WL_IDLE_STATUS;
unsigned long lastSend;

WiFiClient wifiClient;
ThingsBoard tb(wifiClient);

void setup() {
  Serial.begin(115200);
  InitWiFi();
  reconnect();
  //lastSend = 0;
}

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

  //bool status;
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

  Analog = Serial.parseInt();
  //Analog = random(0,20);
  Serial.println(Analog);
  //delay(100);

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

  vibration();
  Serial.println(Analog);
    tb.sendTelemetryInt("Vibration",Analog);
  tb.loop();
}
