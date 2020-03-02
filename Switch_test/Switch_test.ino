#include <dht.h>

dht DHT;

void setup() {
  pinMode (A0,INPUT);
  pinMode (3, INPUT);
  pinMode (2,INPUT_PULLUP);
  //pinMode (11,INPUT);
  Serial.begin (9600);

}

void loop() {
  int sensorvalue = digitalRead(2);
  //Serial.println(sensorvalue);
  if (sensorvalue != 1){
        float Analog = analogRead(A0);
        int chk = DHT.read11(7);
        Serial.print("Analog: ");
        Serial.println(Analog);
        Serial.print("Temperature: ");
        Serial.println(DHT.temperature);
        Serial.println("********************");
    }
  delay(200);

}
