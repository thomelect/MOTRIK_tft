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

unsigned long startMillis; // some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 250; // the value is a number of milliseconds
const byte ledPin = 13;           // using the built in LED
int valTest = 0;
char valTestMsg[4];
int increment = 1;
int randomNum;

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef *m_pElemCounter1 = NULL;
gslc_tsElemRef *m_pElemCounter1_7 = NULL;
gslc_tsElemRef *m_pElemCounter2 = NULL;
gslc_tsElemRef *m_pElemRadial1 = NULL;
gslc_tsElemRef *m_pElemRamp2_3 = NULL;
gslc_tsElemRef *m_pElemToggle1 = NULL;
gslc_tsElemRef *m_pElemXRingGauge1 = NULL;
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
    pinMode(LED_BUILTIN, OUTPUT);
    startMillis = millis(); // initial start time

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

    Serial.print(gslc_GetPageCur(&m_gui));
    switch (gslc_GetPageCur(&m_gui))
    {
    case 0:
        currentMillis = millis();                  // get the current "time" (actually the number of milliseconds since the program started)
        if (currentMillis - startMillis >= period) // test whether the period has elapsed
        {
            digitalWrite(ledPin, !digitalRead(ledPin)); // if so, change the state of the LED.  Uses a neat trick to change the state
            startMillis = currentMillis;                // IMPORTANT to save the start time of the current LED state.
            ///////////////////////////////////////////////////////////////////////////////////////////
            randomNum = random(0, 100);
            gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge1, randomNum); // Set initial value
            gslc_ElemXRadialSetVal(&m_gui, m_pElemRadial1, randomNum);
            sprintf(valTestMsg, "%u%%", randomNum);
            gslc_ElemSetTxtStr(&m_gui, m_pElemCounter1, valTestMsg);
            gslc_ElemSetVisible(&m_gui, m_pElemCounter1, 1);
        }
        break;
    case 1:
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    case 2:
        currentMillis = millis();                  // get the current "time" (actually the number of milliseconds since the program started)
        if (currentMillis - startMillis >= period) // test whether the period has elapsed
        {
            digitalWrite(ledPin, !digitalRead(ledPin)); // if so, change the state of the LED.  Uses a neat trick to change the state
            startMillis = currentMillis;                // IMPORTANT to save the start time of the current LED state.
            ///////////////////////////////////////////////////////////////////////////////////////////
            randomNum = random(0, 100);
            gslc_ElemXRampSetVal(&m_gui, m_pElemRamp2_3, randomNum);
            sprintf(valTestMsg, "%u%%", randomNum);
            gslc_ElemSetTxtStr(&m_gui, m_pElemCounter2, valTestMsg);
            gslc_ElemSetVisible(&m_gui, m_pElemCounter2, 1);
        }
        break;
    }

    // TODO - Add update code for any text, gauges, or sliders

    // ------------------------------------------------
    // Periodically call GUIslice update function
    // ------------------------------------------------
    gslc_Update(&m_gui);
}