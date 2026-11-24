#ifndef SMOOTH_CHANGE_EFFECT_H
#define SMOOTH_CHANGE_EFFECT_H

#include <Adafruit_NeoPixel.h> 
#include "Effect.h"

class SmoothChangeEffect : public Effect {
  private:
    Adafruit_NeoPixel *strip; 
    int speed;
    uint16_t ledCount;
    uint8_t currentBrightness;

public:
    SmoothChangeEffect(Adafruit_NeoPixel *ledStrip, int speed, uint8_t currentBrightness);
    void start() override;
    void stop() override;
    uint32_t Wheel(byte WheelPos);

};

#endif  // SMOOTH_CHANGE_EFFECT_H
