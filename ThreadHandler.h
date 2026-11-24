#ifndef THREADHANDLER_H
#define THREADHANDLER_H

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Effect.h"

class ThreadHandler {
private:
    TaskHandle_t taskHandle; 
    bool threadRunning;
    Effect* currentEffect;

public:
    ThreadHandler(); 

    ~ThreadHandler();

    void startThread(Effect* effect);
    void stopThread();
    static void taskFunction(void* pvParameters);

};

#endif  
