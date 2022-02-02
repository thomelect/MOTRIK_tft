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

#define RA8875_DARKGREEN    0x54C9  ///< Dark Green Color
#define RA8875_DARKGREY     0x5B4E  ///< Dark Grey Color
#define RA8875_DARKORANGE   0x5BE9  ///< Dark Grey Color
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

/* create 15 buttons, in classic candybar phone style */
char buttonlabels[15][5] = {"ENT", "CLR", "NEXT", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ".", ">"};
uint16_t buttoncolors[15] = {RA8875_DARKGREEN, RA8875_DARKGREY, RA8875_RED,
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE,
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE,
                             RA8875_BLUE, RA8875_BLUE, RA8875_BLUE,
                             RA8875_BLUE, RA8875_BLUE, RA8875_ORANGE};
Adafruit_GFX_Button buttons[15];

char backButtonLable[1][5] = {"Back"};
uint16_t backButtonColors[1] = {RA8875_DARKGREEN};
Adafruit_GFX_Button backButton[1];

// Print something in the mini status bar with either flashstring
void status(const __FlashStringHelper *msg) {
  tft.fillRect(STATUS_X, STATUS_Y, 240, 8, RA8875_BLACK);
  tft.setCursor(STATUS_X, STATUS_Y);
  tft.setTextColor(RA8875_WHITE);
  tft.setTextSize(1);//font size on top of white box
  tft.print(msg);
}
// or charstring
void status(char *msg) {
  tft.fillRect(STATUS_X, STATUS_Y, 240, 8, RA8875_BLACK);
  tft.setCursor(STATUS_X, STATUS_Y);
  tft.setTextColor(RA8875_WHITE);
  tft.setTextSize(1);//font size on top of white box
  tft.print(msg);
}

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



  tft.displayOn(true);
  tft.GPIOX(true);                              // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_DARKORANGE);
  tft.textMode();
  tft.textTransparent(RA8875_MAGENTA);
  tft.setCursor(10, 330);
  tft.textEnlarge(1);//font size inside white box
  tft.textWrite("      MOTRIK");
  delay(1000);
  tft.fillScreen(RA8875_DARKBROWN);

  // create buttons
  tft.graphicsMode();
  for (uint8_t row=0; row<5; row++) {
    for (uint8_t col=0; col<3; col++) {
      buttons[col + row*3].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, RA8875_WHITE, buttoncolors[col+row*3], RA8875_WHITE,
                  buttonlabels[col + row*3], BUTTON_TEXTSIZE); 
      buttons[col + row*3].drawButton();
    }
  }

  // create 'text field'
  tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, RA8875_WHITE);
  tft.drawRect(TEXT_X1, TEXT_Y1, TEXT_W, TEXT_H, RA8875_WHITE);
  tft.drawRect(TEXT_X2, TEXT_Y2, TEXT_W, TEXT_H, RA8875_WHITE);

  tft.textMode();

  tft.textSetCursor((TEXT_X - 10), (TEXT_Y - 3));
  tft.textTransparent(TEXT_TCOLOR);

  tft.textWrite(" LAT:");

  tft.textSetCursor((TEXT_X1 - 10), (TEXT_Y1 - 3));
  tft.textTransparent(TEXT_TCOLOR);
  tft.setTextSize(0);//font size inside white box
  tft.print(" LONG:");

  tft.textSetCursor((TEXT_X2 - 10), (TEXT_Y2 - 3));
  tft.textTransparent(TEXT_TCOLOR);
  tft.setTextSize(1);//font size inside white box
  tft.textWrite(" AZMTH:");

  // Set a solid for + bg color ... 

  // ... or a fore color plus a transparent background 

  // Set the cursor location (in pixels) 
  // tft.textSetCursor(10, 10); 

  // Render some text! 
  
/*    char string[15] = "Hello, World! ";
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
  tft.textWrite(string);  */

  //Change the cursor location and color ... 
/*   tft.textSetCursor(100, 100);
  tft.textTransparent(RA8875_RED);
  //If necessary, enlarge the font
  tft.textEnlarge(1); */
  //... and render some more text! 
/*   tft.textWrite(string);
  tft.textSetCursor(100, 150);
  tft.textEnlarge(2);
  tft.textWrite(string);
  char stringg[8] = "Motrik ";
  tft.textWrite(string); */
}

void loop()
{
}
