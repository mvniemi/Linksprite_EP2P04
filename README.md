# Linksprite_EP2P04
An arduino library for the Linksprite 2.04" EPaper Display using the Adafruit GFX library, intended to make this display much easier to work with in the Arduino environment.
Printing text and primitive graphics are made with simple function
calls, and all display work is done "behind the scenes"

Bugs are likely, please raise an issue if you have any problems or question.

If you're using an Atmel328 or similar (Arduino Uno or similar), you won't have enough memory to buffer the whole display in 4-tone, and will only be able to use monochrome. I have not been able to test full 4-tone yet (I've been able to test run half display on the uno), I will verify it's implemented right once I get ahold of a chip with more memory.

I am currently working on an updated version that uses the onboard display memory, solving this issue and taking
full advantage of this chip/
# Usage:
##Installation:
Both this library and the Adafruit_GFX library must be installed.
To install this one, download this repository as a zip and extract it in your Arduino/Libraries folder.
You should than be able to find it under the Examples menu.

For the Adafruit_GFX libary, use the Arduino library manager.
##Initialization:
First, you must include both Linksprite_EP2P04.h and Adafruit_GFX.h
```
#include <Adafruit_GFX.h>
#include <Linksprite_EP2P04.h>
```
The constructor is:  
`Linksprite_EP2P04(uint8_t DC, uint8_t STAT, uint8_t CS, uint8_t DA, uint8_t RS, uint8_t SCK, uint8_t MODE)`

`MODE` defines whether the display will be monochrome or four tone grayscale. Mono = 0, Four tone = 1. Mono will take up arount 1.5k of memory, and four tone 3.

For example, the constructor call to intialize it as `epaper display` with the default pinouts and monochrome is:  
`Linksprite_EP2P04 epaper_display(8,9,10,11,12,13,0);`
##Functions:
Because this library implements the display as a Adafruit_GFX object, most of the GFX functions should work. Checkout the [GFX Documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives) for in depth description of the available functions. However, here are
few of the most important functions, along with ones that differ from normal GFX usage:

`bool refresh(), refresh(int timeout)`  
This writes the display buffer (stored on the arduino), to the display. It is called when you want to display any changes made to the buffer. 
`int timeout` is an optional parameter that defines how long an attempt to write
to the display should be made, as the display has been observed to block as much as 100ms. 200ms is
the default value, it is important to change this if your code is time sensitive.
Returns `True` if refresh successful, `False` if timed out.


`void image_display()`  
Displays the default buffer stored in the library.
This does not make any call through the GFX Library, so it is useful for testing the
most basic functionality of the display.  

`void clearDisplay()`
This fills the entrie buffer with white. Used to clear the canvas.

####GFX Functions:  
Refer to Adafruit for the full documentation.

Printing Text:  
```
void setCursor(uint16_t x0, uint16_t y0);
void setTextColor(uint16_t color);
void setTextColor(uint16_t color, uint16_t backgroundcolor);
void setTextSize(uint8_t size);
void setTextWrap(boolean w);
```
These functions set your text color, size, position, etc. Colors in this libray are modulus 4 with four-tone or binary with monochrome.
```
print("Your Message");
println("Hello World");
```
The GFX library allows you to print to the display as if it were a serial object. 
Remember that these functions are all prototypes, and in real usage you are calling them
on your initialized display object, i.e. `epaper_display.print("Hi!);`
