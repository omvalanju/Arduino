int Analog;

void vibration(){

  Analog = analogRead(A0);

}
void setup() {
    Serial.begin(9600);  
}

void loop() {
  vibration();
  Serial.println(Analog);
  delay(100);
}
