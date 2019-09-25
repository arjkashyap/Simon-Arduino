// Main Module

// Start debuging from lvl 1 function line 97
// Wire for Buttons is not there
// Led response does not reset to low.


// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11

// LED Game-state pins
#define L5 6            // Red
#define L6 7           // Green

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
  int b1_val = digitalRead(B1), b2_val = digitalRead(B2), b3_val = digitalRead(B3), b4_val = digitalRead(B4);
  Serial.println("Game begins");
  
  Serial.println(levelOne());
  delay(800);
  exit(0);
}

// Level one pattern display and match check
bool levelOne(){
  // Display Led pattern for level one
   displayPattern(1);    
   return true;
}

// Displays Led blink pattern for a level
void displayPattern(int lvl){
  int limit, delayTime;
  if(lvl == 1){
    limit = 4;
    delayTime = 500;
  }
  int ptrn[limit];
  for( int i = 0; i < limit; i++ ){
    int pin = random(L1, L4 + 1);         // Choose a random led pin
    Serial.println(pin);
    digitalWrite(pin, HIGH);              
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
  Serial.println("Pattern complete");
  return;
}





