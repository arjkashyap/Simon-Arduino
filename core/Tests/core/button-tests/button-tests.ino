
const int btnPin = 8;

void setup() 
{
  Serial.begin(9600);

  pinMode(btnPin, INPUT_PULLUP);

}

void loop() 
{
  bool btn_val = digitalRead(btnPin);
  Serial.println(btn_val);

}
