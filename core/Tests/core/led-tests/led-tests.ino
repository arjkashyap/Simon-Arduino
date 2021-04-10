

const int ledPin = 12;      // Pin where the led is connected

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop() 
{

//  Serial.println("works ?");
    digitalWrite(ledPin, HIGH);
  
}
