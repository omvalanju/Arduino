#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "GrifW1"
#define wifi_password "kb,J5jQdFH(]8"
//#define mqtt_server "192.1.68.1.219"
#define mqtt_server "demo.thingsboard.io"
#define username "QDObIVFbdxEmx2z62reS"
#define password NULL
String temp = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  reconnect();

}

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void reconnect() {
  
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", username, password)) {
      Serial.println("connected");
    
    }
    
    else {
      
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    
    }
  
  }

}


void loop() {

  /*if (!client.connected()) {
    reconnect();
  }
  client.loop();
  */
  
  //client.loop();

  //String newTemp = Serial.readString();
  //String newTemp = 
  //Serial.println(temp.c_str());
  client.publish("v1/devices/me/telemetry", "{\"TESTESP\":\"ESP\")");
  delay(1000);

}
