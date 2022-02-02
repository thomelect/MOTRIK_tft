/******************************************************************
 This is an example for the Adafruit RA8875 Driver board for TFT displays
 ---------------> http://www.adafruit.com/products/1590
 The RA8875 is a TFT driver for up to 800x480 dotclock'd displays
 It is tested to work with displays in the Adafruit shop. Other displays
 may need timing adjustments and are not guanteed to work.

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source hardware
 by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, check license.txt for more information.
 All text above must be included in any redistribution.
 ******************************************************************/

#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

/*** UI details */
#define BUTTON_X 40
#define BUTTON_Y 140
#define BUTTON_W 60
#define BUTTON_H 30
#define BUTTON_SPACING_X 20
#define BUTTON_SPACING_Y 10
#define BUTTON_TEXTSIZE 2

/* Back Button details */
#define BACK_BUTTON_X 40
#define BACK_BUTTON_Y 40

#define RA8875_DARKGREEN    0x54C9  ///< Dark Green Color
#define RA8875_DARKGREY     0x5B4E  ///< Dark Grey Color
#define RA8875_DARKORANGE   0xA2E5  ///< Dark Grey Color
#define RA8875_LIGHTGREY    0xA513  ///< Dark Grey Color
#define RA8875_DARKBROWN    0x4A27  ///< Dark Grey Color
#define RA8875_ORANGE       0xFC00  ///< Orange Color

// text box where numbers go,position the text box/rectangle
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_X1 10
#define TEXT_Y1 50
#define TEXT_X2 10
#define TEXT_Y2 90
#define TEXT_W 220
#define TEXT_H 30
#define TEXT_TSIZE 3
#define TEXT_TCOLOR RA8875_MAGENTA

char STATUS_X;
char STATUS_Y;

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

void setup()
{
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480))
  {
    Serial.println("RA8875 Not Found!");
    while (1)
      ;
  }



  tft.begin(RA8875_800x480);
  tft.fillScreen(RA8875_DARKORANGE);
  tft.setCursor(10, 330);
  tft.write("      MOTRIK");
  delay(1000);
  tft.fillScreen(RA8875_DARKBROWN);

  
}

void loop()
{
}
