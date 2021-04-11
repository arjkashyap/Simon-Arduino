



// Analogue pins specify progress bar
int progressBarSize = 6;
int progressBar[6] = {14, 15, 16, 17, 18, 19};

void setup() 
{

  Serial.begin(9600);

//  level indicators
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
}

void loop() 
{
    int lvl = 6;
    Serial.println("Start");
    setProgressBar(lvl);
    delay(2000);
    resetProgressBar();
}

// Function lights the leds asper the level on bar
void setProgressBar(int currentLevel)
{
   Serial.println("Progress Bar setting function run . . .");
   int i = 0;
   while(i < currentLevel && i < progressBarSize){
      Serial.println(i);
       digitalWrite(progressBar[i], HIGH);     // switch on led
   
       i++;
   }
}

// function switches off all the lights on progress bar 
void resetProgressBar()
{
  for(int i = 0; i < progressBarSize; i++){
      digitalWrite(progressBar[i], LOW);  
  }
}
