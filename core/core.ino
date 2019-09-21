// Main Module

// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11

// LED Game-state pins
#define L5 6
#define L6 7

// Push button pins
#define B1 1
#define B2 2
#define B3 3
#define B4 4

void setup() {
  Serial.begin(9600);
  
  // Push button pins
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  // LEDPins for Pattern
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  // LED Pins for game state (Correct/Game-Over)
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
}

void loop() {
  
  // Read the pushbutton values
  int b1_val = digitalRead(1), b2_val = digitalRead(2), b3_val = digitalRead(3), b4_val = digitalRead(4);

  //Serial.println(b1_val);
  
  // Turn LED High if the button is pressed
  // INPUT_PULLUP means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed
  if( b1_val == HIGH) {
    digitalWrite(L1, LOW);
  }
  else{
    digitalWrite(L1, HIGH);  
  }
  if( b2_val == HIGH) {
    digitalWrite(L2, LOW);
  }
  else{
    digitalWrite(L2, HIGH);  
  }
  if( b3_val == HIGH) {
    digitalWrite(L3, LOW);
  }
  else{
    digitalWrite(L3, HIGH);  
  }
  if( b4_val == HIGH) {
    digitalWrite(L4, LOW);
  }
  else{
    digitalWrite(L4, HIGH);  
  }

  
}









