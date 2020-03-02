#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(115200);
  Serial.begin(115200);
}

void recieve() {
  String fromESP = mySerial.readString();
  if (fromESP != "\0")
  {
   //Serial.println("Recieving Data");
   Serial.print(fromESP);
  }
  else
  {
   int j = 1; 
  }
}

void loop() {
  recieve();
}
