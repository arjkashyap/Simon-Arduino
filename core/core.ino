// Main Module

// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11

// LED Game-state pins
#define L5 6            // Red
#define L6 7           // Green

// Push button pins
#define B1 2
#define B2 3
#define B3 4
#define B4 5


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
  bool b1_val = digitalRead(B1), b2_val = digitalRead(B2), b3_val = digitalRead(B3), b4_val = digitalRead(B4);
  Serial.println("Game begins");
  Serial.println(b1_val);
 
  if(levelOne()){
    Serial.println("All correct Buttons pressed");    
  }

  delay(800);
  
  exit(0);
}

// Level one pattern display and match check
bool levelOne(){
  // Display Led pattern for level one
   
   int limit = 4, correctButton = 0;
   int ptrn[limit];
   displayPattern(1, ptrn, limit);
   for(int i = 0; i < limit; i++){
    Serial.println(ptrn[i]);
    correctButton = buttonMatch(ptrn[i]);           // Stores the correct choice for button
    
    // Check if the incorrect button is pressed
    // Set Wait for button press
    while(1){
       // Serial.println(correctButton);         
        if(checkButton(correctButton))
          break;
        
     }
     Serial.println("Correct Button Pressed");
     
     delay(800);    // Delay time to register single button pressing multiple times
     resetLeds();
   }
   return true;
}

// Displays Led blink pattern for a level
void displayPattern(int lvl, int ptrn[], int limit){
  Serial.println("Function displayPattern");
  int delayTime;
  int correctButton;
  if(lvl == 1){
    delayTime = 500;
  }
 
  for( int i = 0; i < limit; i++ ){
    int pin = random(L1, L4 + 1);         // Choose a random led pin
    Serial.println(pin);
    ptrn[i] = pin;
    digitalWrite(pin, HIGH);              
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
  Serial.println("Pattern complete");
  
  return;
}

// Finds the button required to be pressed for a led pin passed as variable
int buttonMatch(int ledPin){
  if(ledPin == L1)
    return B1;
  else if ( ledPin == L2 )
    return B2;
  else if (ledPin == L3)
    return B3;
  else if ( ledPin == L4 )
    return B4;
}

// Helper function to check correct button is pressed
bool checkButton(int btn){
  bool b1_val = digitalRead(B1), b2_val = digitalRead(B2), b3_val = digitalRead(B3), b4_val = digitalRead(B4);
  if(B1 == btn and b1_val == LOW){
    Serial.println("Passed");
    Serial.println(b1_val);
    digitalWrite(L1, HIGH);
    return true;
  }

  if(B2 == btn and b2_val == LOW){
    Serial.println("Passed");
    Serial.println(b2_val);
    digitalWrite(L2, HIGH);
    return true;
  }

  if(B3 == btn and b3_val == LOW){
    digitalWrite(L3, HIGH);
    return true;
  }

  if(B4 == btn and b4_val == LOW){
    Serial.println("Passed");
    Serial.println(b4_val);
    digitalWrite(L4, HIGH);
    
    return true;
  }

  if( b1_val == HIGH || b2_val == HIGH || b3_val == HIGH || b4_val == HIGH )
    return false;
}

// Helper function for turning off all Leds at once
void resetLeds(){
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);  
}
