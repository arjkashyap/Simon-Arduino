// Main Module

// LED pins
int L1 = 8, L2 = 9, L3 = 10, L4 = 11;   // Pattern LEDs pins
int L5 = 6, L6 = 7;                     // Game State LEDs pins

int B1 = 1, B2 = 2, B3 = 3, B4 = 4;   // Push button pins

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

  serial.println(b1_val);
  
  // Turn LED High if the button is pressed
  // INPUT_PULLUP means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed
  
  if( b1_val == HIGH) {
    digitalWrite()
  }
  
}









