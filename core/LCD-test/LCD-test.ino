#include <LiquidCrystal.h> 
int Contrast=75;

const int D7 = 12;
const int D6 = A5;
const int D5 = A4;
const int D4 = A3;
const int E = A2;
const int RS = A1;
const int Vo = A0;
 
 LiquidCrystal lcd(RS, E, D4, D5, D6, D7);  

 void setup()
 {
    analogWrite(Vo,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
     lcd.setCursor(0, 0);
     lcd.print("Only Innovative");
   
    lcd.setCursor(0, 1);
     lcd.print("Subscribe");
 }
