//<App !Start!>
// FILE: [arduino.ino]
// Created by GUIslice Builder version: [0.17.b02]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "arduino_GSLC.h"


// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemRadial1    = NULL;
gslc_tsElemRef* m_pElemRamp2_3    = NULL;
gslc_tsElemRef* m_pElemToggle1    = NULL;
gslc_tsElemRef* m_pElemXRingGauge1= NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_BTN9:
        gslc_SetPageCur(&m_gui, E_PG2);
        break;
      case E_ELEM_BTN10:
        gslc_SetPageCur(&m_gui, E_PG3);
        break;
      case E_ELEM_TOGGLE1:
        // TODO Add code for Toggle button ON/OFF state
        if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle1)) {
          ;
        }
        break;
      case E_ELEM_BTN7:
        gslc_SetPageCur(&m_gui, E_PG1);
        break;
      case E_ELEM_BTN8:
        gslc_SetPageCur(&m_gui, E_PG3);
        break;
      case E_ELEM_BTN5:
        gslc_SetPageCur(&m_gui, E_PG1);
        break;
      case E_ELEM_BTN6:
        gslc_SetPageCur(&m_gui, E_PG2);
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
// KeyPad Input Ready callback
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {
//<Keypad Enums !Start!>
//<Keypad Enums !End!>
//<Keypad Enums !End!>
      case E_ELEM_NUMINPUT1:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemVal1, pvData);
	    gslc_PopupHide(&m_gui);
        break;
//<Keypad Enums !End!>
      case E_ELEM_NUMINPUT2:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemVal1_2, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUMINPUT1:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemVal1, pvData);
	    gslc_PopupHide(&m_gui);
        break;

//<Keypad Enums !End!>
      default:
        break;
    }
  } else if (nState == XKEYPAD_CB_STATE_CANCEL) {
    // User escaped from popup, so don't update values
    gslc_PopupHide(&m_gui);
  }
  return true;
}
// Spinner Input Ready callback
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem = gslc_GetElemFromRef(pGui,pElemRef);

  // NOTE: pvData is NULL
  if (nState == XSPINNER_CB_STATE_UPDATE) {
    // From the element's ID we can determine which input field is ready.
    switch (pElem->nId) {
//<Spinner Enums !Start!>

//<Spinner Enums !End!>
      default:
        break;
    }
  }
}
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();

}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
    
}

