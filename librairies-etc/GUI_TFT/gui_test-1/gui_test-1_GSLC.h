//<File !Start!>
// FILE: [gui_test-1_GSLC.h]
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
#include "elem/XGraph.h"
#include "elem/XProgress.h"
#include "elem/XRingGauge.h"
#include "elem/XSeekbar.h"
#include "elem/XTogglebtn.h"
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
enum {E_PG_MAIN};
enum {E_ELEM_BTN1,E_ELEM_BTN2,E_ELEM_GRAPH1,E_ELEM_PROGRESS1
      ,E_ELEM_RINGGAUGE1,E_ELEM_SEEKBAR1,E_ELEM_TOGGLE1};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN5X8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                1

#define MAX_ELEM_PG_MAIN 7 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsXSeekbar                 m_sXSeekbar1;
gslc_tsXProgress                m_sXBarGauge1;
gslc_tsXTogglebtn               m_asXToggle1;
gslc_tsXRingGauge               m_sXRingGauge1;
gslc_tsXGraph                   m_sGraph1;
int16_t                         m_anGraphBuf1[0]; // NRows=0

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemGraph1;
extern gslc_tsElemRef* m_pElemProgress1;
extern gslc_tsElemRef* m_pElemSeekbar1;
extern gslc_tsElemRef* m_pElemToggle1;
extern gslc_tsElemRef* m_pElemXRingGauge1;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // create E_ELEM_BTN1 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN1,E_PG_MAIN,
    (gslc_tsRect){10,50,80,40},(char*)"",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BTN2 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN2,E_PG_MAIN,
    (gslc_tsRect){450,100,80,40},(char*)"",0,E_BUILTIN5X8,&CbBtnCommon);

  // Create seekbar E_ELEM_SEEKBAR1 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_ELEM_SEEKBAR1,E_PG_MAIN,&m_sXSeekbar1,
    (gslc_tsRect){280,390,80,30},0,100,0,
    4,2,8,GSLC_COL_BLUE,GSLC_COL_GRAY,GSLC_COL_BLUE_DK2,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,GSLC_COL_BLUE_LT4,false,GSLC_COL_GRAY,
    0,10,GSLC_COL_GRAY);
  m_pElemSeekbar1 = pElemRef;

  // Create progress bar E_ELEM_PROGRESS1 
  pElemRef = gslc_ElemXProgressCreate(&m_gui,E_ELEM_PROGRESS1,E_PG_MAIN,&m_sXBarGauge1,
    (gslc_tsRect){460,230,50,12},0,100,0,GSLC_COL_GREEN,false);
  m_pElemProgress1 = pElemRef;
  
  // Create toggle button E_ELEM_TOGGLE1
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE1,E_PG_MAIN,&m_asXToggle1,
    (gslc_tsRect){460,160,35,20},GSLC_COL_GRAY,GSLC_COL_BLUE_DK1,GSLC_COL_GRAY_LT3,
    true,false,&CbBtnCommon);
  m_pElemToggle1 = pElemRef;

  // Create ring gauge E_ELEM_RINGGAUGE1 
  static char m_sRingText1[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_RINGGAUGE1,E_PG_MAIN,&m_sXRingGauge1,
          (gslc_tsRect){240,140,100,100},
          (char*)m_sRingText1,11,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 100);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  m_pElemXRingGauge1 = pElemRef;

  // Create graph E_ELEM_GRAPH1
  pElemRef = gslc_ElemXGraphCreate(&m_gui,E_ELEM_GRAPH1,E_PG_MAIN,
    &m_sGraph1,(gslc_tsRect){480,310,180,120},E_BUILTIN5X8,(int16_t*)&m_anGraphBuf1,
        0,((gslc_tsColor){255,200,0}));
  gslc_ElemXGraphSetStyle(&m_gui,pElemRef, GSLCX_GRAPH_STYLE_DOT, 5);
  m_pElemGraph1 = pElemRef;
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
