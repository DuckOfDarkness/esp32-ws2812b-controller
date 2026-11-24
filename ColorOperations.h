#ifndef COLOR_OPERATIONS_H
#define COLOR_OPERATIONS_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "RainbowEffect.h"
#include "ThreadHandler.h"
#include "Colors.h"

extern Colors colors;

class ColorOperations {
public:
    int NUM_LEDS;
    uint32_t *ledColors;  
     ColorOperations(Adafruit_NeoPixel *ledStrip, int numLeds);
    ~ColorOperations();
    void printLedColors();

    void addOneColorToAllLedColors(uint32_t color);
    void addOneColorToOneLedColors(int index, uint32_t color);
    void addOneColorToRangeLedColors(int start, int end, uint32_t color);

    void setEvenIndex(int r, int g, int b);
    void setOddIndex(int r, int g, int b);
    void setColorFromIndexAndByFrequency(int startIndex, int frequency, int r, int g, int b);


    boolean compareWithValueInLedColors(int index, uint32_t colorToCompare);
    // // Metody do operacji na kolorach
    // uint32_t rgbToHex(uint8_t red, uint8_t green, uint8_t blue);
    // void hexToRgb(uint32_t hexColor, uint8_t &red, uint8_t &green, uint8_t &blue);
    // uint32_t blendColors(uint32_t color1, uint32_t color2, float ratio);
    void setColors(int r, int g, int b);
    void setColorsByName(String colorName);
    void setIndex(int index, int r, int g, int b);
    void offIndex(int index);

    void setRangeIndexColor(int start, int end, int r, int g, int b);

    void setColorByHex(String hexString);
    uint32_t hexToColor(String hexString);
    uint32_t hexToRGB(uint32_t hex);
    void hexToRGB(uint32_t hex, uint8_t &r, uint8_t &g, uint8_t &b);

    void setRainbow();
    void stopRainbow();

    // void startTransitionBetweenTwoColors(String startHexString, String endHexString);
    // void transitionBetweenTwoColor(uint32_t startColor, uint32_t endColor, int steps);

    void turnOffAllLeds();

    uint32_t convertRGBtoUint32(int r, int g, int b);

    int getRedFromUint32(uint32_t color);
    int getGreenFromUint32(uint32_t color);
    int getBlueFromUint32(uint32_t color);


private:
    Adafruit_NeoPixel *strip;   
    // TaskHandle_t* taskHandle = nullptr;      // Wskaźnik do taskHandle, jeśli potrzebujesz zarządzać wątkiem
    RainbowEffect* rainbowEffect = nullptr;
    ThreadHandler* threadHandler;
    bool taskRunning;       
};

#endif  // COLOR_OPERATIONS_H

