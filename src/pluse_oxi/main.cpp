#include "module.h"
#include "xbm.h"  //my bitmap

#define REPORTING_PERIOD_MS     1000

PulseOximeter pox;
float Heart_rate = 0;
uint8_t Spo2 = 0;
uint32_t tsLastReport = 0;

void printHRandSPO2(bool beat);
void read_batt();

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
  printHRandSPO2(true);
}

int setup_oxi()
{
  int ret = 0;
  M5.begin();
  M5.Power.begin();
  Wire.begin();         // Wire init, adding the I2C bus.
  Serial.begin(115200); // to PC via USB
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(4);
  // Initialize sensor
  if (!pox.begin()) {
    ret = 0;
    return ret;
    for(;;);
   } else {
    ret = 1;
  }

  //pox.setIRLedCurrent(MAX30100_LED_CURR_11MA);
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  //pox.setIRLedCurrent(MAX30100_LED_CURR_4_4MA);
  
  //Register a callback for the beat detection
  pox.setOnBeatDetectedCallback(onBeatDetected);
  return ret;
}

void loop_oxi()
{
  pox.update();

  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Heart_rate = pox.getHeartRate();
    Spo2 = pox.getSpO2();
    printHRandSPO2(false);
    tsLastReport = millis();
  }
}


void printHRandSPO2(bool beat)
{
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(4);
  if (beat) {
    M5.Lcd.drawXBitmap(0, 5, hb2_bmp, 64, 32, TFT_RED);
  } else {
    M5.Lcd.drawXBitmap(0, 5, hb1_bmp, 64, 32, TFT_WHITE);
  }
  M5.Lcd.setCursor(0,70);
  M5.Lcd.print("HR:   "); M5.Lcd.println(Heart_rate);
  M5.Lcd.print("SPO2: "); M5.Lcd.println(Spo2);  
}
