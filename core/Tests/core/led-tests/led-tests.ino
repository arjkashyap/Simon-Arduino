

const int ledPin = 12;      // Pin where the led is connected
// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11


void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
    // LEDPins for Pattern
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
}

void loop() 
{

  Serial.println("works ?");
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
  
}
