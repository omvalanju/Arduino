void setup() {
   Serial.begin(115200);
}

void loop() {
   while(Serial.available()) {
          char b = Serial.read();
          Serial.print(b);
          delay(1);
   }
}
