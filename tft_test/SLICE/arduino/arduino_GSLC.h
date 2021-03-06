//<File !Start!>
// FILE: [arduino_GSLC.h]
// Created by GUIslice Builder version: [0.17.b02]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "XRadial.h"
#include "XRamp.h"
#include "XRingGauge.h"
#include "XTogglebtn.h"
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if defined(DRV_DISP_TFT_ESPI)
  #error Project tab->Target Platform should be tft_espi
#endif
#include <Adafruit_GFX.h>
#include "Fonts/FreeSansBold12pt7b.h"
#include "Fonts/FreeSansBold18pt7b.h"
#include "Fonts/FreeSansBold9pt7b.h"
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG1,E_PG2,E_PG3};
enum {E_ELEM_BOX1,E_ELEM_BOX2,E_ELEM_BOX3,E_ELEM_BOX4,E_ELEM_BOX5
      ,E_ELEM_BOX6,E_ELEM_BOX7,E_ELEM_BTN10,E_ELEM_BTN5,E_ELEM_BTN6
      ,E_ELEM_BTN7,E_ELEM_BTN8,E_ELEM_BTN9,E_ELEM_RADIALGAUGE1
      ,E_ELEM_RAMPGAUGE3,E_ELEM_RINGGAUGE1,E_ELEM_TEXT1,E_ELEM_TEXT2
      ,E_ELEM_TEXT3,E_ELEM_TEXT7,E_ELEM_TEXT8,E_ELEM_TEXT9
      ,E_ELEM_TOGGLE1};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN5X8,E_FREESANSBOLD12,E_FREESANSBOLD18,E_FREESANSBOLD9
      ,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                3

#define MAX_ELEM_PG1 7 // # Elems total on page
#define MAX_ELEM_PG1_RAM MAX_ELEM_PG1 // # Elems in RAM

#define MAX_ELEM_PG2 11 // # Elems total on page
#define MAX_ELEM_PG2_RAM MAX_ELEM_PG2 // # Elems in RAM

#define MAX_ELEM_PG3 5 // # Elems total on page
#define MAX_ELEM_PG3_RAM MAX_ELEM_PG3 // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui m_gui;
gslc_tsDriver m_drv;
gslc_tsFont m_asFont[MAX_FONT];
gslc_tsPage m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG1_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG1];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG2_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG2];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG3_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG3];
gslc_tsXRingGauge               m_sXRingGauge1;
gslc_tsXTogglebtn               m_asXToggle1;
gslc_tsXRadial                  m_sXRadialGauge1;
gslc_tsXRamp                    m_sXRampGauge3;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemCounter1;
extern gslc_tsElemRef* m_pElemCounter2;
extern gslc_tsElemRef* m_pElemCounter3;
extern gslc_tsElemRef* m_pElemRadial1;
extern gslc_tsElemRef* m_pElemRamp2_3;
extern gslc_tsElemRef* m_pElemToggle1;
extern gslc_tsElemRef* m_pElemXRingGauge1;
extern gslc_tsElemRef* m_pile1_6;
extern gslc_tsElemRef* m_pile2_6;
extern gslc_tsElemRef* m_pile3_6;
extern gslc_tsElemRef* m_pile4_6;
extern gslc_tsElemRef* m_pile5_6;
extern gslc_tsElemRef* m_pile6_6;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY);
bool CbCheckbox(void *pvGui, void *pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void *pvGui, void *pvElemRef, gslc_teRedrawType eRedraw);
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId);
bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos);
bool CbSpinner(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbTickScanner(void *pvGui, void *pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef *pElemRef = NULL;

  if (!gslc_Init(&m_gui, &m_drv, m_asPage, MAX_PAGE, m_asFont, MAX_FONT))
  {
    return;
  }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
  //<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD12,GSLC_FONTREF_PTR,&FreeSansBold12pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD18,GSLC_FONTREF_PTR,&FreeSansBold18pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD9,GSLC_FONTREF_PTR,&FreeSansBold9pt7b,1)) { return; }
  //<Load_Fonts !End!>

  //<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG1,m_asPage1Elem,MAX_ELEM_PG1_RAM,m_asPage1ElemRef,MAX_ELEM_PG1);
  gslc_PageAdd(&m_gui,E_PG2,m_asPage2Elem,MAX_ELEM_PG2_RAM,m_asPage2ElemRef,MAX_ELEM_PG2);
  gslc_PageAdd(&m_gui,E_PG3,m_asPage3Elem,MAX_ELEM_PG3_RAM,m_asPage3ElemRef,MAX_ELEM_PG3);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG1);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,((gslc_tsColor){25,70,153}));

  // -----------------------------------
  // PAGE: E_PG1
  

  // Create ring gauge E_ELEM_RINGGAUGE1 
  static char m_sRingText1[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_RINGGAUGE1,E_PG1,&m_sXRingGauge1,
          (gslc_tsRect){200,75,400,400},
          (char*)m_sRingText1,11,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 100);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  m_pElemXRingGauge1 = pElemRef;
  
  // create E_ELEM_BTN9 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN9,E_PG1,
    (gslc_tsRect){10,420,80,40},(char*)"PAGE #2",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create E_ELEM_BTN10 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN10,E_PG1,
    (gslc_tsRect){100,420,80,40},(char*)"PAGE #3",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT1,E_PG1,(gslc_tsRect){347,10,99,30},
    (char*)"Page #1",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,1);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){75,120,205}),((gslc_tsColor){25,70,153}),((gslc_tsColor){75,120,205}));
  
  // Create toggle button E_ELEM_TOGGLE1
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE1,E_PG1,&m_asXToggle1,
    (gslc_tsRect){680,410,100,50},GSLC_COL_GRAY,GSLC_COL_BLUE_DK1,GSLC_COL_GRAY_LT3,
    true,false,&CbBtnCommon);
  m_pElemToggle1 = pElemRef;

  // Create progress bar E_ELEM_RADIALGAUGE1 
  pElemRef = gslc_ElemXRadialCreate(&m_gui,E_ELEM_RADIALGAUGE1,E_PG1,&m_sXRadialGauge1,
    (gslc_tsRect){360,230,80,80},0,100,0,GSLC_COL_GREEN);
  gslc_ElemXRadialSetIndicator(&m_gui,pElemRef,GSLC_COL_GREEN,20,3,false);
  gslc_ElemXRadialSetTicks(&m_gui,pElemRef,GSLC_COL_GRAY,8,5);
  m_pElemRadial1 = pElemRef;
  
  // Create E_ELEM_TEXT7 runtime modifiable text
  static char m_sDisplayText7[5] = "100%";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT7,E_PG1,(gslc_tsRect){710,5,85,28},
    (char*)m_sDisplayText7,5,E_FREESANSBOLD18);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,((gslc_tsColor){25,70,153}),((gslc_tsColor){25,70,153}));
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElemCounter1 = pElemRef;

  // -----------------------------------
  // PAGE: E_PG2
  
  
  // create E_ELEM_BTN7 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN7,E_PG2,
    (gslc_tsRect){10,420,80,40},(char*)"PAGE #1",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create E_ELEM_BTN8 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN8,E_PG2,
    (gslc_tsRect){100,420,80,40},(char*)"PAGE #3",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_ELEM_TEXT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT2,E_PG2,(gslc_tsRect){347,10,99,30},
    (char*)"Page #2",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,1);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){75,120,205}),((gslc_tsColor){25,70,153}),((gslc_tsColor){75,120,205}));
   
  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX1,E_PG2,(gslc_tsRect){370,170,60,94});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN,GSLC_COL_BLACK,GSLC_COL_BLACK);
   
  // Create E_ELEM_BOX2 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX2,E_PG2,(gslc_tsRect){387,174,26,10});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN,GSLC_COL_GREEN,GSLC_COL_GREEN);
  m_pile6_6 = pElemRef;
   
  // Create E_ELEM_BOX3 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX3,E_PG2,(gslc_tsRect){374,189,52,10});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){102,255,0}),((gslc_tsColor){102,255,0}),((gslc_tsColor){102,255,0}));
  m_pile5_6 = pElemRef;
   
  // Create E_ELEM_BOX4 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX4,E_PG2,(gslc_tsRect){374,204,52,10});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){204,255,0}),((gslc_tsColor){204,255,0}),((gslc_tsColor){204,255,0}));
  m_pile4_6 = pElemRef;
   
  // Create E_ELEM_BOX5 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX5,E_PG2,(gslc_tsRect){374,219,52,10});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_YELLOW,GSLC_COL_YELLOW,GSLC_COL_YELLOW);
  m_pile3_6 = pElemRef;
   
  // Create E_ELEM_BOX6 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX6,E_PG2,(gslc_tsRect){374,234,52,10});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){255,153,0}),((gslc_tsColor){255,153,0}),((gslc_tsColor){255,153,0}));
  m_pile2_6 = pElemRef;
   
  // Create E_ELEM_BOX7 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX7,E_PG2,(gslc_tsRect){374,249,52,10});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){255,51,0}),((gslc_tsColor){255,51,0}),((gslc_tsColor){255,51,0}));
  m_pile1_6 = pElemRef;
  
  // Create E_ELEM_TEXT9 runtime modifiable text
  static char m_sDisplayText9[5] = "100%";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT9,E_PG2,(gslc_tsRect){710,5,83,28},
    (char*)m_sDisplayText9,5,E_FREESANSBOLD18);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,((gslc_tsColor){25,70,153}),((gslc_tsColor){25,70,153}));
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElemCounter2 = pElemRef;

  // -----------------------------------
  // PAGE: E_PG3
  
  
  // create E_ELEM_BTN5 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN5,E_PG3,
    (gslc_tsRect){10,420,80,40},(char*)"PAGE #1",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create E_ELEM_BTN6 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN6,E_PG3,
    (gslc_tsRect){100,420,80,40},(char*)"PAGE #2",0,E_FREESANSBOLD9,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_GRAY_DK2);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_LT4,GSLC_COL_GREEN_DK1);
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_ELEM_TEXT3 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT3,E_PG3,(gslc_tsRect){347,10,99,30},
    (char*)"Page #3",0,E_FREESANSBOLD12);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,1);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){75,120,203}),((gslc_tsColor){25,70,153}),((gslc_tsColor){75,120,203}));

  // Create progress bar E_ELEM_RAMPGAUGE3 
  pElemRef = gslc_ElemXRampCreate(&m_gui,E_ELEM_RAMPGAUGE3,E_PG3,&m_sXRampGauge3,
    (gslc_tsRect){300,170,200,80},0,100,
    100,GSLC_COL_YELLOW,false);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,((gslc_tsColor){25,70,153}),GSLC_COL_BLACK);
  m_pElemRamp2_3 = pElemRef;
  
  // Create E_ELEM_TEXT8 runtime modifiable text
  static char m_sDisplayText8[5] = "100%";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT8,E_PG3,(gslc_tsRect){710,5,83,28},
    (char*)m_sDisplayText8,5,E_FREESANSBOLD18);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,((gslc_tsColor){25,70,153}),((gslc_tsColor){25,70,153}));
  gslc_ElemSetTxtEnc(&m_gui,pElemRef,GSLC_TXT_ENC_UTF8);
  m_pElemCounter3 = pElemRef;
  //<InitGUI !End!>

  //<Startup !Start!>
  //<Startup !End!>
}

#endif // end _GUISLICE_GEN_H
