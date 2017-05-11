//Contains code from Adafruit/Limor Fried GFX Library
//Authored Michael Niemi, mvniemi@github
//BSD License

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
// This sketch currently adds delays before refreshes pending fixes to the library
Linksprite_EP2P04 display(8,9,10,11,12,13,MONO);

void setup() {
  Serial.begin(9600);
  display.begin();
  
  display.image_display();
  display.refresh();
  delay(1000);
  
  display.clearDisplay();
  testdrawchar();
  
  display.clearDisplay();
  testdrawrect(BLACK);
  
  //Kind of a crazy pattern going on here
  display.clearDisplay();
  testdrawcircle();
}


void loop() {
  // put your main code here, to run repeatedly:
}

void testdrawrect(int color) {
  for (uint8_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, color);
    display.refresh();
  }
}

void testdrawcircle(void) {
  for (uint8_t i=0; i<display.height(); i+=2) {
    display.drawCircle(display.width()/2-5, display.height()/2-5, i, BLACK);
    display.refresh();
  }
}

void PrintHex8(uint8_t *data, uint8_t length) // prints 8-bit data in hex with leading zeroes
{
     char tmp[16];
       for (int i=0; i<length; i++) { 
         sprintf(tmp, "0x%.2X",data[i]); 
         Serial.print(tmp); Serial.print(",");
       }
}

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
//Limit the column length
//    if ((i > 0) && (i % 14 == 0))
//      display.println();
  }    
  delay(2000);
  display.refresh();
}
