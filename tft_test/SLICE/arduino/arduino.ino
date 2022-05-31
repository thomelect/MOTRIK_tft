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

#define MAX_MESSAGE_LENGTH 4

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "arduino_GSLC.h"

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

int valNum = 0;
char valNumMsg[4];
int batValTbl[6] = {0, 17, 33, 50, 66, 83};

void gestionPile(int val);

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef *m_pElemCounter1 = NULL;
gslc_tsElemRef *m_pElemCounter2 = NULL;
gslc_tsElemRef *m_pElemCounter3 = NULL;
gslc_tsElemRef *m_pElemRadial1 = NULL;
gslc_tsElemRef *m_pElemRamp2_3 = NULL;
gslc_tsElemRef *m_pElemToggle1 = NULL;
gslc_tsElemRef *m_pElemXRingGauge1 = NULL;
gslc_tsElemRef *m_pile1_6 = NULL;
gslc_tsElemRef *m_pile2_6 = NULL;
gslc_tsElemRef *m_pile3_6 = NULL;
gslc_tsElemRef *m_pile4_6 = NULL;
gslc_tsElemRef *m_pile5_6 = NULL;
gslc_tsElemRef *m_pile6_6 = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch)
{
  if (ch == (char)'\n')
    Serial.println("");
  else
    Serial.write(ch);
  return 0;
}

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

  if (eTouch == GSLC_TOUCH_UP_IN)
  {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId)
    {
      //<Button Enums !Start!>
    case E_ELEM_BTN9:
      gslc_SetPageCur(&m_gui, E_PG2);
      break;
    case E_ELEM_BTN10:
      gslc_SetPageCur(&m_gui, E_PG3);
      break;
    case E_ELEM_TOGGLE1:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle1))
      {
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
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
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
  // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

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

  gslc_tsElemRef *pElemRef = NULL;

  // Check to see if anything is available in the serial receive buffer
  while (Serial.available() > 0)
  {
    // Create a place to hold the incoming message
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;

    // Read the next available byte in the serial receive buffer
    char inByte = Serial.read();

    // Message coming in (check not terminating character) and guard for over message size
    if (inByte != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1))
    {
      // Add the incoming byte to our message
      message[message_pos] = inByte;
      message_pos++;
    }
    // Full message received...
    else
    {
      // Add null character to string
      message[message_pos] = '\0';

      // Print the message (or do other things)
      Serial.println(message);

      // Or convert to integer and print
      valNum = atoi(message);
      Serial.println(valNum);

      // Reset for the next message
      message_pos = 0;
    }
  }
  // randomNum = random(0, 10);
  gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge1, valNum); // Set initial value
  gslc_ElemXRadialSetVal(&m_gui, m_pElemRadial1, valNum);
  gestionPile(valNum);
  gslc_ElemXRampSetVal(&m_gui, m_pElemRamp2_3, valNum);

  sprintf(valNumMsg, "%u%%", valNum);
  gslc_ElemSetTxtStr(&m_gui, m_pElemCounter1, valNumMsg);
  gslc_ElemSetTxtStr(&m_gui, m_pElemCounter2, valNumMsg);
  gslc_ElemSetTxtStr(&m_gui, m_pElemCounter3, valNumMsg);

  gslc_ElemSetVisible(&m_gui, m_pElemCounter1, 1);
  gslc_ElemSetVisible(&m_gui, m_pElemCounter2, 1);
  gslc_ElemSetVisible(&m_gui, m_pElemCounter3, 1);

  // TODO - Add update code for any text, gauges, or sliders

  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
}

void gestionPile(int val)
{
  if (val > batValTbl[0])
  {
    gslc_ElemSetCol(&m_gui, m_pile1_6, ((gslc_tsColor){255, 51, 0}), ((gslc_tsColor){255, 51, 0}), ((gslc_tsColor){255, 51, 0}));
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile1_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));

  if (val > batValTbl[1])
  {
    gslc_ElemSetCol(&m_gui, m_pile2_6, ((gslc_tsColor){255, 153, 0}), ((gslc_tsColor){255, 153, 0}), ((gslc_tsColor){255, 153, 0}));
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile2_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));

  if (val > batValTbl[2])
  {
    gslc_ElemSetCol(&m_gui, m_pile3_6, GSLC_COL_YELLOW, GSLC_COL_YELLOW, GSLC_COL_YELLOW);
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile3_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));

  if (val > batValTbl[3])
  {
    gslc_ElemSetCol(&m_gui, m_pile4_6, ((gslc_tsColor){204, 255, 0}), ((gslc_tsColor){204, 255, 0}), ((gslc_tsColor){204, 255, 0}));
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile4_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));

  if (val > batValTbl[4])
  {
    gslc_ElemSetCol(&m_gui, m_pile5_6, ((gslc_tsColor){102, 255, 0}), ((gslc_tsColor){102, 255, 0}), ((gslc_tsColor){102, 255, 0}));
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile5_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));

  if (val > batValTbl[5])
  {
    gslc_ElemSetCol(&m_gui, m_pile6_6, GSLC_COL_GREEN, GSLC_COL_GREEN, GSLC_COL_GREEN);
  }
  else
    gslc_ElemSetCol(&m_gui, m_pile6_6, ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}), ((gslc_tsColor){128, 128, 128}));
}
