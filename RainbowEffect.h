#ifndef RAINBOW_EFFECT_H
#define RAINBOW_EFFECT_H

#include <Adafruit_NeoPixel.h> 
#include "Effect.h"

class RainbowEffect : public Effect {
  private:
    Adafruit_NeoPixel *strip; 

public:
    RainbowEffect(Adafruit_NeoPixel *ledStrip);
    void start() override;
    uint32_t Wheel(byte WheelPos);
    void stop() override;
};

#endif  // RAINBOW_EFFECT_H
