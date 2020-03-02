void setup() {
  Serial.begin(115200);

}

void recieve() {
  String fromArduino = Serial.readString();
  if (fromArduino != "\0")
  {
   //Serial.println("Recieving Data");
   Serial.println(fromArduino);
  }
  else
  {
   int j = 1; 
  }
}

void loop() {
  recieve();
}
