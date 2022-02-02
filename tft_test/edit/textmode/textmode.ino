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

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define RA8875_DARKGREEN  0x54C9  ///< Dark Green Color
#define RA8875_DARKGREY   0x5B4E  ///< Dark Grey Color
#define RA8875_ORANGE     0xFC00  ///< Orange Color

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

/* create 15 buttons, in classic candybar phone style */
char buttonlabels[15][5] = {"ENT", "CLR", "NEXT", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ".", ">"};
uint16_t buttoncolors[15] = {RA8875_DARKGREEN, RA8875_DARKGREY, RA8875_RED, 
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE, 
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE, 
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE,
                             RA8875_BLUE, RA8875_BLUE, RA8875_ORANGE};
Adafruit_GFX_Button buttons[15];

void setup()
{
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_480x272)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_BLACK);

  /* Switch to text mode */
  tft.textMode();
  tft.cursorBlink(32);

    // create buttons
  for (uint8_t row=0; row<5; row++) {
    for (uint8_t col=0; col<3; col++) {
      buttons[col + row*3].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, RA8875_WHITE, buttoncolors[col+row*3], RA8875_WHITE,
                  buttonlabels[col + row*3], BUTTON_TEXTSIZE); 
      buttons[col + row*3].drawButton();
    }
  }


  /* Set a solid for + bg color ... */

  /* ... or a fore color plus a transparent background */


  /* Set the cursor location (in pixels) */
  tft.textSetCursor(10, 10);

  /* Render some text! */
  char string[15] = "Hello, World! ";
  tft.textTransparent(RA8875_WHITE);
  tft.textWrite(string);
  tft.textColor(RA8875_WHITE, RA8875_RED);
  tft.textWrite(string);
  tft.textTransparent(RA8875_CYAN);
  tft.textWrite(string);
  tft.textTransparent(RA8875_GREEN);
  tft.textWrite(string);
  tft.textColor(RA8875_YELLOW, RA8875_CYAN);
  tft.textWrite(string);
  tft.textColor(RA8875_BLACK, RA8875_MAGENTA);
  tft.textWrite(string);
  tft.text

  /* Change the cursor location and color ... */
  tft.textSetCursor(100, 100);
  tft.textTransparent(RA8875_RED);
  /* If necessary, enlarge the font */
  tft.textEnlarge(1);
  /* ... and render some more text! */
  tft.textWrite(string);
  tft.textSetCursor(100, 150);
  tft.textEnlarge(2);
  tft.textWrite(string);
  char stringg[8] = "Motrik ";
  tft.textWrite(string);
  Adafruit_GFX_Buttons
}

void loop()
{
}
