
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11); //RX,TX

int Analog;

void vibration(){

  Analog = analogRead(A0);

}

void setup() {
  
  Serial.begin(9600);  
  mySerial.begin(115200);

}

void loop() {
  vibration();
  mySerial.println(Analog);

  Serial.println(Analog);
}
