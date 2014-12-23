#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

// any pins can be used
#define SCK 10
#define MOSI 11
#define SS 13

Adafruit_SharpMem display(SCK, MOSI, SS);

#define BLACK 0
#define WHITE 1

const int coinInt = 0; 
const int spacing = 500; 
//Attach coinInt to Interrupt Pin 0 (Digital Pin 2). Pin 3 = Interrpt Pin 1.

int counter = 0;                  
unsigned long time;

void setup()
{
  display.begin();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello There");
  display.println("Initializing");
  display.println("Piggy Bank");
  display.refresh();
  attachInterrupt(coinInt, coinInserted, RISING);   
}

void coinInserted()    
{
  counter++;
  time = millis();
}

void loop()
{
  if(0 < counter && time < (millis() - spacing))          
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(5,0);
    switch(counter) {
      case 1:
       display.println("You added a penny");
       break;
      case 2:
       display.println("You added a dime");
       break;
      case 3:
       display.println("You added 5 cents");
       break;
      case 4:
       display.println("You added 25 cents");
       break;
      default:
       display.println("Unknown amount");
       break;
    }
     display.refresh();
   counter = 0;
  }
}

