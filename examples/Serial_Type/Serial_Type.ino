#include <Adafruit_GFX.h>
#include <Linksprite_EP2P04.h>
        
#define MONO 0
#define FOURTONE 1
#define BLACK 1
#define WHITE 0

//These are the argument for the constructor, default pins (printed on the PCB), are 8,9,10,11,12,13 respectively
//Linksprite_EP2P04(uint8_t DC, uint8_t STAT, uint8_t CS, uint8_t DA, uint8_t RS, uint8_t SCK, uint8_t MODE);
//MODE determines what size memory buffer to use:
// 0 =  MONOCHROME (1.5K buffer for use on Atmega 328 (Arduino Uno)
// 1 =  4 COLOR GRAYSCALE (3k buffer for anything beefier)
// 2 = Half Screen Color Display

// The UNO cannot hold full color in memory, however it can display images stored in PROGRMEM,
// Holding the monochrome buffer also takes most of the memory, with little room left for sketch variables

Linksprite_EP2P04 display(8,9,10,11,12,13,MONO);

//Flag for if we've written to display
bool written;
 
void setup() {

 Serial.begin(9600);
 display.begin();
 display.clearDisplay();
 display.image_display();
 display.refresh();
 
 delay(1000);
 display.clearDisplay();
 display.setTextColor(BLACK);
 display.setCursor(0,0);
 display.print("Begin Typing:"); 
 //I am not sure why we need to call refresh twice at this point, but it's working
 display.refresh();
 display.refresh();
}

void loop() {
 while (Serial.available() > 0){
  char c = Serial.read();
  display.print(c);
  written = true;
 }
 if (written){
  display.refresh();
  written = false; 
 }
}

