void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  //pinMode(13, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(2);
  Serial.println(sensorValue);
  delay(500);
}
