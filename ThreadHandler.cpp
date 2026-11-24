#include "ThreadHandler.h"

ThreadHandler::ThreadHandler(){
  taskHandle = NULL;
  threadRunning = false;
}

ThreadHandler::~ThreadHandler() {
    stopThread(); 
}

void ThreadHandler::startThread(Effect* effect) {
    if (!threadRunning) {  
       currentEffect = effect;
        xTaskCreatePinnedToCore(
            taskFunction,  // Funkcja zadania
            "EffectTask",   // Nazwa zadania
            2048,           // Rozmiar stosu
            effect,         // Przekazanie obiektu efektu
            1,              // Priorytet
            &taskHandle,    // Uchwyty zadania
            1);             // Rdzeń, na którym ma działać zadanie (0 dla PRO_CPU, 1 dla APP_CPU)

        threadRunning = true;  // Ustawiamy threadRunning na true po uruchomieniu wątku
    }
}

void ThreadHandler::stopThread() {
    if (taskHandle != NULL) {
        if (currentEffect != nullptr) { 
            currentEffect->stop();  
        }

        vTaskDelete(taskHandle);  // Usuwamy wątek
        taskHandle = nullptr;
        threadRunning = false;
        currentEffect = nullptr;  // Czyścimy wskaźnik
    }
}

void ThreadHandler::taskFunction(void* pvParameters) {
    Effect* effect = static_cast<Effect*>(pvParameters);  

    while (true) {
        effect->start();  
        vTaskDelay(pdMS_TO_TICKS(100));  
    }
}


