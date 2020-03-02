#include <dht.h>

dht DHT;

void setup() {
  pinMode (A0,INPUT);
  pinMode (3, INPUT);
  Serial.begin (9600);

}

void displaytemp() {
  int chk = DHT.read11(7);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
}

void sound() {
  int Digital;
  float Analog;

  Analog = analogRead(A0);
  Serial.println(Analog);
  
  Digital = digitalRead(3);
  if (Analog >= 88)
  {
     //Serial.println(Digital);
     displaytemp();
  }
  
}

void loop() {
   sound();  
   delay(100);
}
