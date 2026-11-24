  #include <Adafruit_NeoPixel.h>
  #include "ColorOperations.h"

  Colors colors;
  // Konstruktor
  ColorOperations::ColorOperations(Adafruit_NeoPixel *ledStrip, int numLeds) {
        NUM_LEDS = numLeds;
        ledColors = new uint32_t[NUM_LEDS];  
        for (int i = 0; i < NUM_LEDS; i++) {
            ledColors[i] = 0;  
        }
      strip = ledStrip;
      taskRunning = false; // Domyślnie watek nie działa
  }

  // Destruktor
  ColorOperations::~ColorOperations() {
     delete[] ledColors;
  }

  // // Konwersja RGB na HEX (0xRRGGBB)
  // uint32_t ColorOperations::rgbToHex(uint8_t red, uint8_t green, uint8_t blue) {
  //     return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
  // }

  // // Konwersja HEX (0xRRGGBB) na RGB
  // void ColorOperations::hexToRgb(uint32_t hexColor, uint8_t &red, uint8_t &green, uint8_t &blue) {
  //     red   = (hexColor >> 16) & 0xFF;
  //     green = (hexColor >> 8) & 0xFF;
  //     blue  = hexColor & 0xFF;
  // }

  // // Mieszanie dwóch kolorów w podanej proporcji (0.0 - tylko color1, 1.0 - tylko color2)
  // uint32_t ColorOperations::blendColors(uint32_t color1, uint32_t color2, float ratio) {
  //     uint8_t r1, g1, b1, r2, g2, b2;
  //     hexToRgb(color1, r1, g1, b1);
  //     hexToRgb(color2, r2, g2, b2);

  //     uint8_t r = (uint8_t)((1 - ratio) * r1 + ratio * r2);
  //     uint8_t g = (uint8_t)((1 - ratio) * g1 + ratio * g2);
  //     uint8_t b = (uint8_t)((1 - ratio) * b1 + ratio * b2);

  //     return rgbToHex(r, g, b);
  // }

  // Funkcja do ustawiania koloru na taśmie LED
  void ColorOperations::setColors(int r, int g, int b) {
    turnOffAllLeds();
    uint32_t color = convertRGBtoUint32(r, g, b);
    for (int i = 0; i < strip->numPixels(); i++) {
      strip->setPixelColor(i, color);
    }
    addOneColorToAllLedColors(color);
    strip->show();
  }

  void ColorOperations::setColorsByName(String colorName){
    turnOffAllLeds();
    uint32_t color = colors.getColorByName(colorName);

    if (color != 0) {
      int r = getRedFromUint32(color);
      int b = getBlueFromUint32(color);
      int g = getGreenFromUint32(color);
      setColors(r, g, b);
      addOneColorToAllLedColors(color);
      strip->show();
      }  
      else{
            Serial.println("wybrany kolor to 0");
      }
  }

  void ColorOperations::setColorByHex(String hexString){
      uint32_t color = hexToColor(hexString); 
      if (color != 0) {
        int r = getRedFromUint32(color);
        int b = getBlueFromUint32(color);
        int g = getGreenFromUint32(color);
        setColors(r, g, b);
        addOneColorToAllLedColors(color);
      } 
  }

  uint32_t ColorOperations::hexToColor(String hexString) {
      if (hexString.length() != 6) {
          Serial.println("Błąd: niepoprawny format HEX!");
          return 0; 
      }
      uint32_t color = strtoul(hexString.c_str(), NULL, 16); // Konwertuje HEX na uint32_t
      uint8_t r = (color >> 16) & 0xFF;
      uint8_t g = (color >> 8) & 0xFF;
      uint8_t b = color & 0xFF;
      return color; // Zwraca uint32_t reprezentujący kolor
  }

  void ColorOperations::setIndex(int index, int r, int g, int b) {
    if(taskRunning) return;
    uint32_t color = convertRGBtoUint32(r, g, b);
    strip->setPixelColor(index, color);
    addOneColorToOneLedColors(index, color);
    strip->show();
  }

  void ColorOperations::offIndex(int index){
    if(taskRunning) return;
    uint32_t blackColor = strip->Color(0, 0, 0);
    strip->setPixelColor(index, blackColor); 
    addOneColorToOneLedColors(index, blackColor);
    strip->show();
  }
      
  // Funkcja do ustawiania koloru w przekazanym zakresie indeksow na taśmie LED
  void ColorOperations::setRangeIndexColor(int start, int end, int r, int g, int b) {
    if(taskRunning) return;

    uint32_t color = convertRGBtoUint32(r, g, b);

    for (int i = start; i <= end; i++) {
      strip->setPixelColor(i, color);
    }
    addOneColorToRangeLedColors(start, end, color);
    strip->show();
  }

  // uint32_t hexToUint32(String hexString) {
  //     if (hexString.length() != 6) {
  //         Serial.println("Błąd: niepoprawny format HEX!");
  //         return 0; // Zwraca 0 w przypadku błędu
  //     }
  //     return strtoul(hexString.c_str(), NULL, 16);
  // }

  void ColorOperations::turnOffAllLeds() {
    if (taskRunning) {
        if(rainbowEffect){
            stopRainbow();
        }
        threadHandler->stopThread();
        delete threadHandler;
        
        taskRunning = false; 
      }
      for (int i = 0; i < strip->numPixels(); i++) {
          strip->setPixelColor(i, strip->Color(0, 0, 0)); 
      }
      addOneColorToAllLedColors(strip->Color(0, 0, 0));
      strip->show(); 
  }

  // ------------------------ RAINBOW  ------------------------ //

  void ColorOperations::setRainbow(){
    if (taskRunning) return;
      rainbowEffect = new RainbowEffect(strip);
      threadHandler = new ThreadHandler();
      threadHandler->startThread(rainbowEffect);
      taskRunning = true;
  }

  void ColorOperations::stopRainbow(){
    if (!taskRunning) return; 
    if (rainbowEffect) {
          rainbowEffect->stop();
          delete rainbowEffect; 
          rainbowEffect = nullptr;
      } 
  }

    void ColorOperations::addOneColorToAllLedColors(uint32_t color){
        for (int i = 0; i < NUM_LEDS; i++) {
            ledColors[i] = color;  
        }
  }

  void ColorOperations::addOneColorToOneLedColors(int index, uint32_t color){
      ledColors[index] = color;
  }

  void ColorOperations::addOneColorToRangeLedColors(int start, int end, uint32_t color){
        for(int i = start ; i <= end ; i++){
          ledColors[i] = color;
        }
  }

  void ColorOperations::setEvenIndex(int r, int g, int b){
        if(taskRunning) return;
        uint32_t color = convertRGBtoUint32(r, g, b);
        for (int i = 0; i < NUM_LEDS; i++) {
            if(i == 0 || i % 2 == 0){
                ledColors[i] = color; 
                strip->setPixelColor(i, color);
            }
        }
        strip->show();
  }

    void ColorOperations::setOddIndex(int r, int g, int b){
        if(taskRunning) return;
        uint32_t color = convertRGBtoUint32(r, g, b);
        for (int i = 0; i < NUM_LEDS; i++) {
            if(i % 2 != 0){
                ledColors[i] = color; 
                strip->setPixelColor(i, color);
            }
        }
        strip->show();
  }

void ColorOperations::setColorFromIndexAndByFrequency(int startIndex, int frequency, int r, int g, int b){
        if(taskRunning) return;
        int step = frequency;
        uint32_t color = convertRGBtoUint32(r, g, b);

        for (int i = startIndex; i < NUM_LEDS; i++) {
        if (step == frequency) {
            ledColors[i] = color;
            strip->setPixelColor(i, color);
            step = 0; 
        } else {
            step++;
        }
    }
          strip->show();
  }      

  // ------------------------ TRANSITION BETWEEN TWO COLORS  ------------------------ //

  // void ColorOperations::startTransitionBetweenTwoColors(String startHexString, String endHexString){
  //     uint32_t startColor = hexToColor(startHexString); 
  //     uint32_t endColor = hexToColor(endHexString); 
  //     transitionBetweenTwoColor(startColor, endColor, 1000);
  // }

  // void ColorOperations::hexToRGB(uint32_t hex, uint8_t &r, uint8_t &g, uint8_t &b) {
  //     r = (hex >> 16) & 0xFF;
  //     g = (hex >> 8) & 0xFF;
  //     b = hex & 0xFF;
  // }

  // // //Przenikanie meidzy 2 kolorami
  // void ColorOperations::transitionBetweenTwoColor(uint32_t startColor, uint32_t endColor, int steps) {
  //     uint8_t r1, g1, b1, r2, g2, b2;

  //     // Konwersja kolorów HEX na RGB
  //     hexToRGB(startColor, r1, g1, b1);
  //     hexToRGB(endColor, r2, g2, b2);

  //     // Obliczanie różnicy między kolorami
  //     int rStep = (r2 - r1) / steps;
  //     int gStep = (g2 - g1) / steps;
  //     int bStep = (b2 - b1) / steps;

  //     for (int i = 0; i <= steps; i++) {
  //         // Obliczanie nowych wartości kolorów
  //         uint8_t r = r1 + rStep * i;
  //         uint8_t g = g1 + gStep * i;
  //         uint8_t b = b1 + bStep * i;

  //         // Ustawienie nowego koloru na taśmie LED
  //         setColors(strip->Color(r, g, b));
  //         delay(10);  // Krótkie opóźnienie, aby efekt był płynny
  //     }
  // }

  // Funkcja konwersji HEX na RGB
  uint32_t ColorOperations::hexToRGB(uint32_t hex) {
      uint8_t r = (hex >> 16) & 0xFF;
      uint8_t g = (hex >> 8) & 0xFF;
      uint8_t b = hex & 0xFF;
      return (r << 16) | (g << 8) | b; // Sklejamy wartości RGB w uint32_t
  }

  // Convert color: ints to uint32_t
  uint32_t ColorOperations::convertRGBtoUint32(int r, int g, int b) {
    uint32_t color = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
      return color;
  }

  int ColorOperations::getRedFromUint32(uint32_t color){
    int r = (color >> 16) & 0xFF;
    return r;
  }

  int ColorOperations::getGreenFromUint32(uint32_t color){
    int g = (color >> 8) & 0xFF;
    return g;
  }

  int ColorOperations::getBlueFromUint32(uint32_t color){
    int b = color & 0xFF;
    return b;
  }

  boolean ColorOperations::compareWithValueInLedColors(int index, uint32_t colorToCompare){
    return ledColors[index] == colorToCompare;
  }

  void ColorOperations::printLedColors(){
    Serial.println("Aktualne kolory diod LED:");
    for (int i = 0; i < NUM_LEDS; i++) {
        uint32_t color = ledColors[i];
        int r = (color >> 16) & 0xFF;
        int g = (color >> 8) & 0xFF;
        int b = color & 0xFF;
        
        Serial.print("LED ");
        Serial.print(i);
        Serial.print(": R=");
        Serial.print(r);
        Serial.print(" G=");
        Serial.print(g);
        Serial.print(" B=");
        Serial.println(b);
    }
  }