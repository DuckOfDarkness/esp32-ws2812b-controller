#ifndef PULSE_EFFECT_H
#define PULSE_EFFECT_H

#include <Adafruit_NeoPixel.h> 
#include "Effect.h"

class PulseEffect : public Effect {
  private:
    Adafruit_NeoPixel *strip; 
    uint16_t ledCount;
    int centerIndex;
    int speed;
    uint32_t color1;
    uint32_t color2;

public:
    PulseEffect(Adafruit_NeoPixel *ledStrip, uint32_t color1, uint32_t color2, int speed);
    void start() override;
    void stop() override;

};

#endif  // PULSE_EFFECT_H
