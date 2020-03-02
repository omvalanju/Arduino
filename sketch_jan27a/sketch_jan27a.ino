
void setup() 
{
    Serial.begin(9600); 
    //Serial.print("TEST\n");
}

String s1;

void loop() 
{
    Serial.println("TEST");
    delay(500);
    
    if (Serial.available() > 0){
     String s1 = Serial.readString();
     Serial.println("Recieved "+s1);
     s1 = "";
     delay(500);
    }
    while(Serial.read() >= 0) ;
}  
