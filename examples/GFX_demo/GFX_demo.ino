#include <Adafruit_GFX.h>
#include <Linksprite_EP2P04.h>
#include "Arduino.h"

#define MONO 0
#define FOURTONE 1

Linksprite_EP2P04 display(1);
#define BLACK 1
#define WHITE 0
void setup() {
    Serial.begin(9600);
    display.begin();
 //display.write_buffer_mono();
 //display.image_display();
//// display.clearDisplay();
//////  display.write_buffer_mono();
// display.refresh();
 display.clearDisplay();
// display.fillBlack();
 for(int i =0; i<72; i++){
 display.drawPixel(i, i, i%4); 
 }
// display.refresh();
////    delay(3000);
//    display.refresh();
//    testdrawrect(1);
//    delay(1000);
//    display.refresh();
//    display.clearDisplay();
//   testdrawchar();
   display.write_buffer_color();
//    display.refresh();
//    delay(2000);
//    display.clearDisplay();
//    display.fillBlack();
//    display.refresh();
//    delay(1000);
    //te0stdrawrect(BLACK);
//    display.refresh();
//    delay(100);
//    display.clearDisplay();
//    display.fillBlack();
//    //testdrawrect(0);
//    display.refresh();
}


void printbuffer(char buf[]){
  for (int i=0 ; i < (72*172/8); i++){
    PrintHex8(&buf[i],1);
  }
  Serial.println("");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  


}

void testdrawrect(int color) {
  for (uint8_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()/2-2*i, display.height()-2*i, color);
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
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    //if ((i > 0) && (i % 14 == 0))
      //display.println();
  }    
  display.refresh();
}
