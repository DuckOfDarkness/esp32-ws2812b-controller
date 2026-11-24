#include <WiFi.h>
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <WebServer.h>
#include "ColorOperations.h"

#define LED_PIN 5              
#define NUM_LEDS 300           

const char* ssid = "";        
const char* password = ""; 
int serverPort = 80;

WebServer server(serverPort);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
ColorOperations colorOperations(&strip, NUM_LEDS);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();            
  strip.setBrightness(50); 

  // Połączenie z WiFi
  Serial.println("\nŁączenie z Wi-Fi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nPołączono z WiFi");
  Serial.print("Adres IP: ");
  Serial.println(WiFi.localIP());

  // Uruchomienie serwera
  server.on("/", handleRoot);
  server.on("/color", handleSetColor);
  server.on("/colorIndex", handleSetColorIndex);
  server.on("/offColorIndex", handleOffColorIndex);
  server.on("/colorIndex/range", handleSetColorRange);
  server.on("/rainbow", handleRainbow);
  server.on("/off", handleOff);
  server.on("/setColorByH", handleSetColorByHex);
  server.on("/index", handleIndex);
  server.on("/colorNa", setColorsByName);
  server.on("/colorIndexOff", handleColorIndexOff);
  server.on("/printcolors", handlePrintLedColors);
  server.on("/compare/two", handleCompareTwoLEDs);
  server.on("/evenIndex", handleEvenColorLeds);
  server.on("/OddIndex", handleOddColorLeds);
  server.on("/frequency", handleFrequencyColorLeds);



  server.begin();
  Serial.println("Serwer HTTP uruchomiony.");
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Połączenie Wi-Fi utracone. Próba ponownego połączenia...");
    WiFi.disconnect();
    WiFi.reconnect();
    delay(5000);
  }

  server.handleClient();
}

// Obsługa żądań HTTP
void handleRoot() {
  server.send(200, "text/plain", "Serwer ESP32 działa!");
}

void handlePrintLedColors(){
  colorOperations.printLedColors();
}

void handleSetColor() {
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt();
  colorOperations.turnOffAllLeds();
  colorOperations.setColors(r, g, b);
  server.send(200, "text/plain", "Kolor ustawiony");
}

void handleSetColorIndex() {
  int index = server.arg("i").toInt();
  if (index >= 0 && index < NUM_LEDS) {
    int r = server.arg("r").toInt();
    int g = server.arg("g").toInt();
    int b = server.arg("b").toInt();
    colorOperations.setIndex(index, r, g, b);
    server.send(200, "text/plain", "Dioda ustawiona");
  } else {
    server.send(400, "text/plain", "Nieprawidłowy indeks");
  }
}

void setColorsByName() {
  String colorName = server.arg("me");
    colorName.toUpperCase();
    colorOperations.turnOffAllLeds();
    colorOperations.setColorsByName(colorName); 
    server.send(200, "text/plain", "Diody ustawione na: " + colorName);
}

void handleOffColorIndex() {
  int index = server.arg("i").toInt();
  if (index >= 0 && index < NUM_LEDS) {
    colorOperations.offIndex(index);
    server.send(200, "text/plain", "Dioda wyłączona");
  } else {
    server.send(400, "text/plain", "Nieprawidłowy indeks");
  }
}

void handleSetColorRange() {
  int start = server.arg("start").toInt();
  int end = server.arg("end").toInt();
  if (start >= 0 && end <= NUM_LEDS && start < end) {
    int r = server.arg("r").toInt();
    int g = server.arg("g").toInt();
    int b = server.arg("b").toInt();
    colorOperations.setRangeIndexColor(start, end, r, g, b);
    server.send(200, "text/plain", "Zakres ustawiony");
  } else {
    server.send(400, "text/plain", "Nieprawidłowy zakres");
  }
}

void handleRainbow() {
  colorOperations.setRainbow();
  server.send(200, "text/plain", "Efekt tęczy włączony");
}

void handleOff() {
  colorOperations.turnOffAllLeds();
  server.send(200, "text/plain", "LEDy wyłączone");
}

void handleColorIndexOff(){
    int index = server.arg("i").toInt();
    if (index < 0 || index > NUM_LEDS){
        server.send(400, "text/plain", "Nieprawidłowy zakres");
        return;
    }
    colorOperations.offIndex(index);
    server.send(200, "text/plain", "Dioda wylaczona");
}

void handleSetColorByHex() {
  String hex = server.arg("ex");
  if (hex.length() > 0) {
    colorOperations.setColorByHex(hex);
    server.send(200, "text/plain", "Kolor ustawiony przez HEX");
  } else {
    server.send(400, "text/plain", "Nieprawidłowy HEX");
  }
}

void handleIndex() {
  server.send(200, "text/plain", String(NUM_LEDS));
}

void handleCompareTwoLEDs(){
  int index = server.arg("index").toInt();
  if(index < 0 || index >= NUM_LEDS){
        server.send(400, "text/plain", "Out of range");
        return;
  }
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt();
  uint32_t colorToCompare = colorOperations.convertRGBtoUint32(r, g ,b);
  boolean compared = colorOperations.compareWithValueInLedColors(index, colorToCompare);
  if(compared){
     server.send(200, "text/plain", "Positive result");
  }else{
    server.send(200, "text/plain", "Negative result");
  }
}

void handleEvenColorLeds(){
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt();
  colorOperations.setEvenIndex(r, g ,b);
  server.send(200, "text/plain", "Parzyste diody ustawione na przekazany kolor");
}

void handleOddColorLeds(){
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt(); 
  colorOperations.setOddIndex(r, g ,b);
  server.send(200, "text/plain", "Nieparzyste diody ustawione na przekazany kolor");
}

void handleFrequencyColorLeds(){
  int startIndex = server.arg("i").toInt();
  int frequency = server.arg("f").toInt();
  if(startIndex < 0 || startIndex > NUM_LEDS || frequency <= 0 || frequency > NUM_LEDS){
        server.send(400, "text/plain", "Out of range");
        return;
  }
  int r = server.arg("r").toInt();
  int g = server.arg("g").toInt();
  int b = server.arg("b").toInt(); 

  colorOperations.setColorFromIndexAndByFrequency(startIndex, frequency, r, g, b);
  server.send(200, "text/plain", "Diody ustawione na przekazany kolor wg przekazanej czestotliwosci.");
}
