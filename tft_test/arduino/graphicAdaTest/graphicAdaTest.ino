/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Examples for ER-TFTM050-3 
Hardware SPI,4-Wire SPI Interface,5V Power Supply

The slight modified  test for his libraries
adapted (easily) for this one, shows how simple is deal with it.
Tested and worked with:
Teensy3,Teensy3.1,Arduino UNO,Arduino YUN,Arduino Leonardo,Stellaris
Works with Arduino 1.6.0 IDE
****************************************************/


#include <SPI.h>
#include "RA8875.h"

//Arduino DUE,Arduino mega2560,Arduino UNO
#define RA8875_INT 4
#define RA8875_CS 10 

#define RA8875_RESET 9

//#if defined(NEEDS_SET_MODULE)//Energia, this case is for stellaris/tiva

//RA8875 tft = RA8875(3);//select SPI module 3
/*
for module 3 (stellaris)
SCLK:  PD_0
MOSI:  PD_3
MISO:  PD_2
SS:    PD_1
*/
//#else

RA8875 tft = RA8875(RA8875_CS,RA8875_RESET);//Teensy3/arduino's

//#endif

float p = 3.1415926;

uint16_t ccolor = RA8875_BLACK;
uint16_t cccolor = RA8875_BLUE;

void mediabuttons() {
  // play
  tft.fillScreen(RA8875_BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, RA8875_WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, RA8875_RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, RA8875_WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, RA8875_GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, RA8875_GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, RA8875_BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, RA8875_RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, RA8875_RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, RA8875_GREEN);
}


void tftPrintTest() {
  //tft.setTextWrap(false);
  tft.changeMode(TEXT);
  tft.fillScreen(RA8875_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(RA8875_RED);
  tft.setFontScale(1);
  tft.println("www.buydisplay.com");
  tft.setTextColor(RA8875_YELLOW);
  tft.setFontScale(2);
  tft.println("www.buydisplay.com");
  tft.setTextColor(RA8875_GREEN);
  tft.setFontScale(3);
  tft.println("www.buydisplay.com");
  tft.setTextColor(RA8875_BLUE);
  tft.setFontScale(2);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(RA8875_BLACK);
  tft.setTextColor(RA8875_WHITE);
  tft.setFontScale(0);
  tft.println("Hello World!");
  tft.setFontScale(1);
  tft.setTextColor(RA8875_GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(RA8875_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(RA8875_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(RA8875_WHITE);
  tft.print(" seconds.");
  tft.changeMode(GRAPHIC);
}

void testroundrects() {
  tft.fillScreen(RA8875_BLACK);
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = 127;
    int h = 159;
    for(i = 0 ; i <= 24; i+=1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}





void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft.height(); y+=radius*2) {
      tft.fillCircle(x, y, radius, color);
    }
  }
}


void setup() 
{
  Serial.begin(9600);
  //while (!Serial) {;}
  Serial.println("RA8875 start");

  tft.begin(RA8875_800x480);

  uint16_t time = millis();
  tft.fillScreen(RA8875_BLACK);
  time = millis() - time;

  
  
  
  

}

void loop(){
  ccolor = random(RA8875_BLUE,RA8875_WHITE);
  cccolor = random(RA8875_BLUE,RA8875_WHITE);
  testfillcircles(10, cccolor);
  testdrawcircles(10, ccolor);
}
