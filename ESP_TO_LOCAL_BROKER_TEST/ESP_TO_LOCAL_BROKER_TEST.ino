#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <ThingsBoard.h> 

#define WIFI_AP "GrifW1"
#define WIFI_PASSWORD "kb,J5jQdFH(]8"

//#define TOKEN "6V5PDTFsqsHc4Wv2X6Qe"
//#define THINGSBOARD_SERVER "127.0.0.1"

//long ran;
String AnalogS;
double AnalogI;
//String ranstr;
char Analog[50];

// Function prototypes
void subscribeReceive(char* topic, byte* payload, unsigned int length);

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
ThingsBoard tb(wifiClient);


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


void setup()
{
  Serial.begin(115200); 
  InitWiFi();            
  mqttClient.setServer("192.168.1.219", 1885);   
 
  if (mqttClient.connect("ClientID")) 
  {
    Serial.println("Connection has been established, well done");
  } 
  
  else 
  {
    Serial.println("Looks like the server connection failed...");
  }
}


void vibration(){

  AnalogI = Serial.parseInt();
  //Analog = random(0,20);
  Serial.println(Analog);
  //delay(100);

}


void loop()
{
  mqttClient.loop();
  AnalogI = Serial.parseInt();
  //dtostrf(AnalogI ,1,2, AnalogS);
  AnalogS = String(AnalogI);
  AnalogS.toCharArray(Analog,AnalogS.length()+1);
  //char ranstr[8];
  //ran = random(10);
  //dtostrf(ran ,1,2, ranstr);
  //AnalogS = Serial.readString();
  //Analog = AnalogS.c_str();
  //AnalogS = Serial.readString();
  //Serial.println(AnalogS);
  //Serial.println("test");
  //AnalogS = String(Analog);
  //AnalogS.toCharArray(Analog, AnalogS.length() + 1);

  Serial.println(AnalogS); 
  
  mqttClient.subscribe("MakerIOTopic");
  
  if(mqttClient.publish("MakerIOTopic",Analog))
  {
    Serial.println("Publish message success");
  }
  else
  {
    Serial.println("Could not send message ");
  }
  //mqttClient.loop();
  delay(50);
}
