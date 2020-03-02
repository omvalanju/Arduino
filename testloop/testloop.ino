#include<stdlib.h>
#include<stdio.h>

void setup() {
 Serial.begin(9600);
 //Serial.println("Check");
}

char buffer[10];
char str[10];

void loop() {
 Serial.println("TEST");
 delay(1000);
 while (Serial.available() > 0){
  //Serial.write(a);
  for (i=1,i=4,i++) {
  str = Serial.read();
  }
  //Serial.println("---------");
  Serial.print("--"+str);
  //Serial.println("---------");
 }
}
