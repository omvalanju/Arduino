#include <dht.h>

dht DHT;

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(7);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  delay(1000);
}
