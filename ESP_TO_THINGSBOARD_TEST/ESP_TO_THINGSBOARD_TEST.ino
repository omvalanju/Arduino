#include <ESP8266WiFi.h>
#include <ThingsBoard.h>

//#define WIFI_AP "GrifW1"
//#define WIFI_PASSWORD "kb,J5jQdFH(]8"

#define WIFI_AP "Om’s iPhone"
#define WIFI_PASSWORD "qwerty123"


#define TOKEN "QDObIVFbdxEmx2z62reS"

//char thingsboardServer[] = "demo.thingsboard.io";
#define THINGSBOARD_SERVER  "demo.thingsboard.io"

String AnalogS;
int Analog;

WiFiClient wifiClient;
ThingsBoard tb(wifiClient);

int status = WL_IDLE_STATUS;
unsigned long lastSend;

void setup() {
  Serial.begin(115200);
  InitWiFi();
  reconnect();
  lastSend = 0;
}

void InitWiFi()
{
  
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");

}

void reconnect() {
  // Loop until we're reconnected
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

  //AnalogS = Serial.readString();
  Analog = Serial.parseInt();
  //Serial.println(AnalogS);
  //Analog = atoi(AnalogS.c_str());
  Serial.println(Analog);

}
  
void loop() {
  //{
  //if ( !tb.connected() ) {
    //reconnect();
  //}
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  }

  if (!tb.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }
  
  vibration();
  Serial.println(Analog);
  //if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    tb.sendTelemetryInt("Vibration",Analog);
    //lastSend = millis();
  //}
  //tb.sendTelemetryInt("temperature", Analog);

  tb.loop();
}
