#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(19200);
  Serial.begin(19200);
}

int wait = 0;

void loop() {
  //while(Serial.read() >= 0) ;
  String fromPython = Serial.readString();
  //mySerial.println("Recieved: " + fromPyhton);

  //if (fromPython == "\0")
  //{
   //int i = 1;
  //}

  //else
  //{
  mySerial.println("Recieved: " + fromPython);
  //}

  //mySerial.println("Input Message");
  //delay(4);
  delay(1);
  String fromArduino = Serial.readString();
  //mySerial.println(wait);
  if (fromArduino == "\0")
  {
   //mySerial.println("No Message to transmit");  
  }
    
  else
  {
   mySerial.println("Transmitting: " + fromArduino);
   Serial.println("TEST" + fromArduino);
   wait = 0;
  }

  while(Serial.read() >= 0) ;

  wait = wait + 1;
}
