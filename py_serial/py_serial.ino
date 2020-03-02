void setup() 
{ 
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    String s1 = Serial.readString();
    String s2 = "Hello Arduino";

    if((s1.compareTo(s2)) == 0)
    {
     Serial.print("Hello Python");
    }
  }      
}
