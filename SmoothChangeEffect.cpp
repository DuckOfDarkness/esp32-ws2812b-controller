#include "SmoothChangeEffect.h"
#include "SmoothChangeEffect.h"
#include <Adafruit_NeoPixel.h>

static uint8_t color_index = 0; 

SmoothChangeEffect::SmoothChangeEffect(Adafruit_NeoPixel *ledStrip, int speed, uint8_t currentBrightness){
  strip = ledStrip;
  ledCount = strip->numPixels();
  this->currentBrightness = currentBrightness;
  this->speed = speed;
}

void SmoothChangeEffect::start(){
   // Deklarujemy zmienną 'hue' jako statyczną, 
    // aby zachowała swoją wartość między wywołaniami funkcji.
    static uint16_t hue = 0; 

    // Generujemy jeden, jednolity kolor dla całego paska
    // saturation i value ustawione na max, aby uzyskać czyste, jasne kolory
    uint32_t color = strip->ColorHSV(hue, 255, currentBrightness); 
    
    // Ustawiamy ten sam kolor dla WSZYSTKICH diod na pasku
    for(int i = 0; i < ledCount; i++){
        strip->setPixelColor(i, color); 
    }
    strip->show();

    // Zwiększamy 'hue' o małą wartość, aby w następnej iteracji
    // uzyskać nieznacznie inny kolor. 
    // Pełne koło barw HSV ma 65536 stopni (0-65535).
    hue += 256; 
    delay(speed);
}

void SmoothChangeEffect::stop(){
    strip->clear();
    strip->show();
}

uint32_t SmoothChangeEffect::Wheel(byte WheelPos){
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}