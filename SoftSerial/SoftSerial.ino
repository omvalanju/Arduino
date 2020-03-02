#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(115200);
  Serial.begin(115200);
}

/*void recievemessage() {
  String fromESP = Serial.readString();
  if (fromESP != "\0")
  {
   mySerial.println("Recieved: " + fromESP);
  } 
  else
  {
    //mySerial.println("Else Satisfied:Nothing RX");
    //delay(1000);
    int j = 0;
  }
}*/

void sendmessage() {
  String fromArduino = mySerial.readString();
  if (fromArduino != "\0")
  {
   mySerial.print("Transmitted: " + fromArduino);
   Serial.print(fromArduino);
  }
  else
  {
   int j = 1; 
  }
}

void loop() {
  //recievemessage();
  //while(Serial.read() >= 0) ;
  sendmessage();
  
}
