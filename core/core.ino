// Main Module

// current line = 104

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

  // Game starts
  level_one();
  
  
    
}

int ledResponse(){
  // Turn LED High if the button is pressed
  // INPUT_PULLUP means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed
  if( b1_val == HIGH) {
    digitalWrite(L1, LOW);
  }
  else{
    digitalWrite(L1, HIGH);
    return L1;  
  }
  
  if( b2_val == HIGH) {
    digitalWrite(L2, LOW);
  }
  else{
    digitalWrite(L2, HIGH);
    return L2;  
  }
  
  if( b3_val == HIGH) {0
    digitalWrite(L3, LOW);
  }
  else{
    digitalWrite(L3, HIGH);
    return L3;  
  }
  
  if( b4_val == HIGH) {
    digitalWrite(L4, LOW);
  }
  else{
    digitalWrite(L4, HIGH);  
    return L4;
  }
  
  return 0;
}

bool levelOne(){
  int subLvl = 3;
  int current = 0;
  bool success = true;
  while( current < sublvl ){
    int ptrn[4];        // Led pin patterns
    int limit = 4;
    // Store random led number
    for(int i = 0; i < limit; i++){
      int pin_num = random(L1, L4 + 1);
      ptrn[i] = pin_num;
    }
    disp_ptrn(ptrn, 1, limit);
    for(int i = 0; i < limit; i++){
      int btn;
      
    }
    current += 1;
  }
   
}

// Displays the Led pattern passed through array of pin numbers
void disp_ptrn(int ptrn[], int lvl){
  int delay_time;               // Varies with level
  if( lvl == 1 )  
    delay_time = 1000;
  for( int i = 0; i < limit; i++ ){
      digitalWrite(ptrn[i], HIGH);
      delay(delay_time);
  }
}








