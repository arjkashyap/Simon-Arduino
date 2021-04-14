#include <EEPROM.h>


// LED Pattern pins
#define L1 8
#define L2 9
#define L3 10
#define L4 11

// LED Solution checker pins
#define L5 6            // Red
#define L6 7           // Green

// Push button pins
#define B1 2
#define B2 3
#define B3 4
#define B4 5

#define stateBtn 12     // push button for changing game state to play


const int highScoreAddress = 0; // memory address of high score 
int highScore = 0;
//int highScore = EEPROM.read(highScoreAddress);

int gameState = 0;      // 1 -> being played, 0 -> at rest

int score = 0;
int currentLevel = 0;

// Analogue pins specify progress bar
int progressBarSize = 5;
int progressBar[5] = {14, 15, 16, 17, 19};

void setup() {
  Serial.begin(9600);

//  EEPROM.write(highScoreAddress, 1);    // Store 0 as high score, run this only once
  highScore = EEPROM.read(highScoreAddress);

Serial.println("High scroe");
Serial.println(highScore);
  
  // Push button pins
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  pinMode(stateBtn, INPUT_PULLUP);

  // LEDPins for Pattern
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  // LED Pins for game state (Correct/Game-Over)
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);

  //  level indicators
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  // psedo random seq initialize
  randomSeed(analogRead(0));
}

void loop() {
  //  Serial.println(digitalRead(stateBtn));
  handleGameState();
  setHighScoreDisp();
  if (gameState == HIGH) {
    resetProgressBar();
    delay(2000);
    setProgressBar(currentLevel);
    // Read the pushbutton values
    bool b1_val = digitalRead(B1), b2_val = digitalRead(B2), b3_val = digitalRead(B3), b4_val = digitalRead(B4);

    Serial.println("Game begins");
    Serial.println(b1_val);

    int startLevel = 1;          // Game starts at level 1
    int startLimit = 4;         // Number of led blinks at level 1


    while (1) {
      if (levelDesign(startLevel, startLimit)) {
        // set progress indicator
        setProgressBar(currentLevel);
        digitalWrite(L6, HIGH);
        delay(1200);
        digitalWrite(L6, LOW);
        delay(1000);
        startLevel ++;
        startLimit += 2;
        score += 10;

        // game complete
        if (currentLevel == 5)
          break;

      }
      else {
        // Incorrect answer
        break;
      }

    }

    
    if(currentLevel > highScore){
        highScore = currentLevel;
        EEPROM.write(highScoreAddress, highScore);  // update high score 
    }
    
    // If the game is not complete
    if (currentLevel != 5)
      digitalWrite(L5, HIGH);

    Serial.print("Score: ");
    Serial.println(score);
    delay(2000);

    resetProgressBar();

    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);

    gameState = 0;
  }
}

// Show high score on progress bar
void setHighScoreDisp()
{
  for(int i = 0; i < highScore; i++)
      digitalWrite(progressBar[i], HIGH);
}

// listens to the game start button and changes the state
void handleGameState()
{
  if (digitalRead(stateBtn) == LOW) {
    Serial.println("Game state change button pushed");
    Serial.println("Changing Game state . . . .");
    gameState = 1;
    Serial.println(gameState);
  }



}

// Function lights the leds asper the level on bar
void setProgressBar(int currentLevel)
{
  Serial.println("Progress Bar setting function run . . .");
  int i = 0;
  while (i < currentLevel && i < progressBarSize) {
    Serial.println(i);
    digitalWrite(progressBar[i], HIGH);     // switch on led

    i++;
  }
}


void gameEndEffect(int level)
{
  // Function runs a blink effect on
  // the progress bar
  int k = 0;
  while (k < 7) {
    for (int i = 0; i < level; i++) {
      digitalWrite(progressBar[i], LOW);
      delay(100);
    }
    for (int i = 0; i < level; i++) {
      digitalWrite(progressBar[i], HIGH);
      delay(100);
    }
    k += 1;
  }
}

// function switches off all the lights on progress bar
void resetProgressBar()
{
  Serial.println("Reset progress bar");
  gameEndEffect(currentLevel);
  for (int i = 0; i < progressBarSize; i++) {
    digitalWrite(progressBar[i], LOW);
  }
  currentLevel = 0;
}

// Level one pattern display and match check
bool levelDesign(int level, int limit) {
  // Display Led pattern for level one
  // int limit = 4;
  int correctButton = 0;

  int ptrn[limit];
  displayPattern(level, ptrn, limit);
  for (int i = 0; i < limit; i++) {
    Serial.println(ptrn[i]);
    correctButton = buttonMatch(ptrn[i]);           // Stores the correct choice for button

    // Check if the incorrect button is pressed
    // Set Wait for button press
    while (1) {
      // Serial.println(correctButton);
      int btnVar = checkButton(correctButton);
      if ( btnVar == 1 )      // Correct button is pressed
        break;
      if ( btnVar == 2 )      // Incorrect Button pressed
        return false;
    }
    Serial.println("Correct Button Pressed");

    delay(800);    // Delay time to register single button pressing multiple times
    resetLeds();
  }
  limit += 2;
  currentLevel += 1; // level is cleared
  return true;
}

// Displays Led blink pattern for a level
void displayPattern(int lvl, int ptrn[], int limit) {
  Serial.println("Function displayPattern");
  int delayTime;
  int correctButton;
  if (lvl == 1) {
    delayTime = 500;
  }

  for ( int i = 0; i < limit; i++ ) {
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
int buttonMatch(int ledPin) {
  if (ledPin == L1)
    return B1;
  else if ( ledPin == L2 )
    return B2;
  else if (ledPin == L3)
    return B3;
  else if ( ledPin == L4 )
    return B4;
}

// Helper function to check correct button is pressed
// Returns 1 if correct button is pressed
// Returns 2 if button pressed is incorrect
// Returns 0 by default
int checkButton(int btn) {
  bool b1_val = digitalRead(B1), b2_val = digitalRead(B2), b3_val = digitalRead(B3), b4_val = digitalRead(B4);
  if (B1 == btn and b1_val == LOW) {
    Serial.println("Passed");
    Serial.println(b1_val);
    digitalWrite(L1, HIGH);
    return 1;
  }

  if (B2 == btn and b2_val == LOW) {
    Serial.println("Passed");
    Serial.println(b2_val);
    digitalWrite(L2, HIGH);
    return 1;
  }

  if (B3 == btn and b3_val == LOW) {
    digitalWrite(L3, HIGH);
    return 1;
  }

  if (B4 == btn and b4_val == LOW) {
    Serial.println("Passed");
    Serial.println(b4_val);
    digitalWrite(L4, HIGH);

    return 1;
  }
  // Wrong button pressed
  if ( B1 != btn && b1_val == LOW || B2 != btn && b2_val == LOW || B3 != btn && b3_val == LOW || B4 != btn && b4_val == LOW)
    return 2;

  return 0;
}

// Helper function for turning off all Leds at once
void resetLeds() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
}
