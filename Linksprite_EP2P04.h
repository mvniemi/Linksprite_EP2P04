/*********************************************************************
Arduino Library for the LinkSprite 2.04" E-Paper Display
Written by Michael Niemi / mvniemi  http://github.com/mvniemi
Implements the Adafruit GFX Class , Adapted from the Sharp Memory display library written by Limor Fried/Ladyada for Adafruit Industries.
*********************************************************************/

//#ifndef LINKSPRITE_EP2P04_H
//#define LINKSPRITE_EP2P04_H
//
//#endif //LINKSPRITE_EP2P04_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_GFX.h>

#if defined(ESP32)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif
#if defined(ESP8266)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif
//#include <util/delay.h>
#ifdef __avr__
  #include <util/delay.h>
#endif

// LCD Dimensions
#define EP2P04_LCDWIDTH       (172)
#define EP2P04_LCDHEIGHT      (72)


class Linksprite_EP2P04 : public Adafruit_GFX {
public:
    //Linsprite_EP2P04(uint8_t DC, uint8_t CS, uint8_t SDA, SCLK, RSR);
    Linksprite_EP2P04(uint8_t DC, uint8_t STAT, uint8_t CS, uint8_t DA, uint8_t RS, uint8_t SCK, uint8_t MODE);
    void 
        begin(void),
        drawPixel(int16_t x, int16_t y, uint16_t color),
        clearDisplay(),
        entersleep(void),
        write_buffer_mono(char buffer[]),
        write_buffer_color(char buffer[]),
        image_display(char image[] = NULL),
        fillBlack(),
        setBounds(uint16_t w, uint16_t h),
        RESET(int delay = NULL), INIT();

    bool refresh(int timeout_thresh = NULL);
    //not implemented
    uint8_t getPixel(uint16_t x, uint16_t y);

    int buffsize;
    char* mem_buffer;
private:
    uint8_t _dc, _stat, _cs, _da, _rs, _sck, _mode;
//    volatile uint8_t *dataport, *clkport;
//    uint8_t _EP2P04_vcom, datapinmask, clkpinmask;

//    void sendbyte(uint8_t data);
//    void sendbyteLSB(uint8_t data);
    void
        SPI4W_WRITECOM(unsigned char INIT_COM),
        SPI4W_WRITEDATA(unsigned char INIT_DATA),
        SPI4W_WRITEDATA_MONO(unsigned char INIT_DATA),
        WRITE_LUT(),
        DELAY_mS(int delaytime);
    byte mem_type;
};
