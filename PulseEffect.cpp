#include "PulseEffect.h"
#include <Adafruit_NeoPixel.h>

PulseEffect::PulseEffect(Adafruit_NeoPixel *ledStrip, uint32_t color1, uint32_t color2, int speed){
  strip = ledStrip;
  ledCount = strip->numPixels();
  this->color1 = color1;
  this->color2 = color2;

  this->speed = speed;
  centerIndex = ledCount/2;
}

void PulseEffect::start(){
      for(int i = 0 ; i <= centerIndex ; i++){
        strip->setPixelColor(i, color1);
        strip->setPixelColor(ledCount-1-i, color1);
        strip->show();
        delay(speed);
      }
      delay(speed);
      for(int i = centerIndex ; i >= 0 ; i--){
        strip->setPixelColor(i, color2);
        strip->setPixelColor(ledCount-1-i, color2);
        strip->show();
        delay(speed);
      }
}

void PulseEffect::stop(){
  strip->clear();
  strip->show();
}