//
// Created by pc on 4/1/2017.
//

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
#ifdef __AVR
#include <avr/pgmspace.h>
#elif defined(ESP8266)
#include <pgmspace.h>
#endif

// LCD Dimensions
#define EP2P04_LCDWIDTH       (172)
#define EP2P04_LCDHEIGHT      (72)

class Linksprite_EP2P04 : public Adafruit_GFX {
public:
    //Linsprite_EP2P04(uint8_t DC, uint8_t CS, uint8_t SDA, SCLK, RSR);
    Linksprite_EP2P04(byte mono);
    char *mem_buffer_ptr;

    void begin(void);
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void drawPixel_mono (int16_t x, int16_t y, uint16_t color);
    uint8_t getPixel(uint16_t x, uint16_t y);
    void clearDisplay();
    void refresh(void);

    //LinkSprite functions
    void entersleep();
    void image_display();
    void write_buffer();
    void write_buffer_mono();
    void write_buffer_color();

private:
//    uint8_t _ss, _clk, _mosi;
//    volatile uint8_t *dataport, *clkport;
//    uint8_t _EP2P04_vcom, datapinmask, clkpinmask;

//    void sendbyte(uint8_t data);
//    void sendbyteLSB(uint8_t data);

    void SPI4W_WRITECOM(unsigned char INIT_COM);
    void SPI4W_WRITEDATA(unsigned char INIT_DATA);
    void SPI4W_WRITEDATA_MONO(unsigned char INIT_DATA);
    void WRITE_LUT();
    void RESET();
    void INIT_SPD2701();
    void DELAY_mS(int delaytime);
    byte mem_type;
};
