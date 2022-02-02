#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
#include "Math.h"

MCUFRIEND_kbv tft;

#include "Temperature.h"

#define PI 3.1415926535897932384626433832795

int a = 1000, b = 3500;
int n, f;
int j, j2 , lj;
int i, i2 , li;
int pct = 0;
int d[5] = {20, 20, 20, 20, 20};
uint16_t col[5] = {0x7006, 0xF986, 0x6905, 0x7FF7, 0x024D};

void setup() {
  tft.reset();
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.invertDisplay(true);
  tft.setTextSize(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  tft.fillScreen(0xffff);
  tft.setRotation(1);
  tft.drawBitmap(350, 70, Temp, 70, 180, 0x0000);
  tft.fillCircle(385, 213, 25, tft.color565(255, 0, 0));

  for (int p = 0; p < 4000; p++) {
    j = 120 * (sin(PI * p / 2000));
    i = 120 * (cos(PI * p / 2000));
    j2 = 110 * (sin(PI * p / 2000));
    i2 = 110 * (cos(PI * p / 2000));
    tft.drawLine(i2 + 160, j2 + 160, i + 160, j + 160, tft.color565(100, 100, 100));
  }
  if (b > a) {
    while (a < b) {
      j = 120 * (sin(PI * a / 2000));
      i = 120 * (cos(PI * a / 2000));
      j2 = 110 * (sin(PI * a / 2000));
      i2 = 110 * (cos(PI * a / 2000));
      tft.drawLine(i2 + 160, j2 + 160, i + 160, j + 160, tft.color565(255, 0, 0));
      tft.fillCircle(160, 150, 50, 0xffff);
      tft.setTextSize(4);
      tft.setTextColor(0x0000);
      tft.setCursor(135, 145);
      tft.print(a / 40); tft.print("%"); delay(20);

      for (uint16_t c = 0; c < 13; c++) {
        tft.drawLine(378 + c, 213, 378 + c, (200 - a / 40), tft.color565(255, 0, 0));
      }       //200=0 & 100=100
      for (uint16_t c = 0; c < 13; c++) {
        tft.drawLine(378, 213 + c, 378, (200 - a / 40) + c, tft.color565(255, 0, 0));
      }
      a++;
    }
    b = 0;
  }

  //////////////////////////////////////////////////////////////////

  while (b < a) {
    j = 120 * (sin(PI * a / 2000));
    i = 120 * (cos(PI * a / 2000));
    j2 = 110 * (sin(PI * a / 2000));
    i2 = 110 * (cos(PI * a / 2000));
    tft.drawLine(i2 + 160, j2 + 160, i + 160, j + 160, tft.color565(100, 100, 100));
    tft.fillCircle(160, 150, 50, 0xffff);
    tft.setTextSize(4);
    tft.setTextColor(0x0000);
    tft.setCursor(135, 145);
    tft.print(a / 40); tft.print("%"); delay(50);

    for (uint16_t c = 0; c < 13; c++) {
      tft.drawLine(378 + c, (200 - a / 40), 378 + c, 100, tft.color565(0, 0, 0));
    }       //200=0 & 100=100
    for (uint16_t c = 0; c < 13; c++) {
      tft.drawLine(378, (200 - a / 40) + c, 378, 100 + c, tft.color565(0, 0, 0));
    }
    a--;
  }

  ////////////////////////////////////////////////////////////////////
  while (1);
}
