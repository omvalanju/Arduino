#include <dht.h>

dht DHT;

void setup() {
  pinMode (7,INPUT);
}

void loop() {
  int chk = DHT.read11(7);
  Serial.println(DHT.temperature);
  delay(500);
}
