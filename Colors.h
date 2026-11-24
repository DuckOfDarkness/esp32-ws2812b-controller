// COLORS.h
#ifndef COLORS_H
#define COLORS_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Colors {

public:
    Colors();
    uint32_t getColorByName(const String& name);
//    uint32_t ALLCOLORS[]; // Deklaracja tablicy
    // uint32_t ALLCOLORS[]; 

 //   typedef struct {
  //      const char* name;
  //      uint32_t color;
  //   } ColorMapping;

//ColorMapping colorMappings[];

private:

struct ColorMapping {
        const char* name;
        uint32_t color;
    };

  uint32_t colors[61];
  ColorMapping colorMappings[61];  
  uint32_t ALLCOLORS[61];

  //  const ColorMapping colorMappings[];

};

#endif // COLORS_H

