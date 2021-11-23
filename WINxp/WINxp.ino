#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#include "error2.h"
#include "welcome.h"
#include "bsod.h"
#include "frame.h"

TFT_eSPI tft = TFT_eSPI();

const int pwmFreq = 5000;
const int pwmResolution = 8;
const int pwmLedChannelTFT = 5;

void setup() {
  
  
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    tft.setSwapBytes(true);

   ledcSetup(pwmLedChannelTFT, pwmFreq, pwmResolution);
  ledcAttachPin(17, pwmLedChannelTFT);
  ledcWrite(pwmLedChannelTFT, 80);
   
   
}

void loop() 
{
 
 for(int i=0;i<9;i++)
    for(int i=0;i<12;i++){
      tft.pushImage(52,56,150,151,frame[i]); 
       delay(80);}

    tft.pushImage(0,0,240,240,welcome);
    delay(5200);
    tft.fillScreen(TFT_BLACK);
    tft.pushImage(40,50,160,102,error2);
    delay(4000);
    tft.pushImage(0,0,240,240,bsod); 
    delay(7000);
    tft.fillScreen(TFT_BLACK);
    }
