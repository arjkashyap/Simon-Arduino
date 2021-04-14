

const int ledPin = 12;      // Pin where the led is connected
// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11
#define L5 A0
#define L6 A1
#define L7 A2
#define L8 A3
#define L9 A5






void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
    // LEDPins for Pattern
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
    pinMode(L9, OUTPUT);




}

void loop() 
{

    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);

    digitalWrite(L6, HIGH);
    digitalWrite(L7, HIGH);
    digitalWrite(L8, HIGH);
        digitalWrite(L9, HIGH);




  
}
