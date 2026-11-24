#include "RainbowEffect.h"
#include <Adafruit_NeoPixel.h>

RainbowEffect::RainbowEffect(Adafruit_NeoPixel *ledStrip){
      strip = ledStrip;
}

void RainbowEffect::start(){
    for (int j = 0; ; j++) { // n cykli
      for (int i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, Wheel(((i * 256 / strip->numPixels()) + j) & 255));
      }
      strip->show();
      delay(20);
    }
}


void RainbowEffect::stop(){
      strip->clear();
      strip->show();
      // delete this;
}
        
// Funkcja pomocnicza do generowania kolorów tęczy
uint32_t RainbowEffect::Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

// Funkcja efektu tęczy uruchamiana na oddzielnym rdzeniu
// void rainbowTask(void* parameter) {
//   while (rainbowRunning) {
//     for (int j = 0; ; j++) { // n cykli
//       if (!rainbowRunning) {
//         break; // Wyjdź, jeśli flaga została zmieniona
//       }
//       for (int i = 0; i < strip.numPixels(); i++) {
//         strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//       }
//       strip.show();
//       delay(20);
//     }
//   }
//   taskHandle = NULL; // Zresetuj wskaźnik przed zakończeniem
//   vTaskDelete(NULL); // Usuń zadanie, gdy tęcza zostanie zatrzymana
// }



// //Funkcja pomocnicza zatrzymujaca tecze
// void stopRainbow(){
//   rainbowRunning = false; // Zatrzymaj efekt tęczy
//     delay(50);              // Krótkie opóźnienie na zakończenie zadania tęczy
//     if (taskHandle != NULL) {
//       vTaskDelete(taskHandle);
//       taskHandle = NULL;
//     }
// }
