
#include <SoftwareSerial.h>
#include <dht.h>

dht DHT;
int temp;
int Analog;
int sensorValue;

SoftwareSerial mySerial(10,11); //RX,TX

void setup() {
  
  pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);  
  mySerial.begin(115200);
}


void tempcheck(){
  
  int chk = DHT.read11(7);
  temp = DHT.temperature;
  
}

void soundcheck(){

  Analog = analogRead(A0);

}

void button() {
  
  sensorValue = digitalRead(2);
  //Serial.println(sensorValue);
  delay(500);
  
}

void loop() {
  
  tempcheck();
  soundcheck();
  button();

  if (sensorValue == 0){
  
      mySerial.print("Temperature: ");
      mySerial.println(temp);
      mySerial.print("Sound: ");
      mySerial.println(Analog);

      Serial.print("Temperature: ");
      Serial.println(temp);
      Serial.print("Sound: ");
      Serial.println(Analog);
      Serial.println(sensorValue);
      delay(500);

  }
  
      

}
