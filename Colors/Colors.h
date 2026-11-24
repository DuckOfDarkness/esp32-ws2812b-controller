// COLORS.h
#ifndef COLORS_H
#define COLORS_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//struct ColorMapping {
//    const char* name;
//    uint32_t color;
//};

class Colors {

public:
    Colors();
    uint32_t getColorByName(const String& name);
//    uint32_t ALLCOLORS[]; // Deklaracja tablicy
    static const uint32_t ALLCOLORS[]; // Poprawiona deklaracja

 //   typedef struct {
  //      const char* name;
  //      uint32_t color;
  //   } ColorMapping;

//ColorMapping colorMappings[];

private:

// Definicje kolorów jako stałe


  //  const ColorMapping colorMappings[];

};

#endif // COLORS_H

