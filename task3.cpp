#include <Arduino.h>
#include "task3.h"
#include "events.h"

static bool compareKeys(BUTTONS *pSecret, BUTTONS *pKey)
{
    bool correct = true;
    for (uint8_t i = 0; i < 7; i++)
    {
        if (pSecret[i] != pKey[i]){
            correct = false;
            break;
        }
    }

    return correct;
}

void task3(){
     enum class TaskStates
    {
        INIT,
        WAIT_CONFIG,
        
    };

    static TaskStates taskState = TaskStates::INIT;
    const uint8_t led = 25;
    const uint32_t LEDINTERVAL = 1000U;
    const uint32_t LEDCOUNTERINTERVAL = 500U;

    static BUTTONS secret[5] = {BUTTONS::BTN_1, BUTTONS::BTN_1,
                                BUTTONS::BTN_2, BUTTONS::BTN_2,
                                BUTTONS::BTN_1
                                };

    static BUTTONS disarmKey[5] = {BUTTONS::NONE};

        switch (taskState)
    {
    case TaskStates::INIT:
    {

        pinMode(led, OUTPUT);
        digitalWrite(led, HIGH);
        taskState = TaskStates::WAIT_CONFIG;
        break;
    }
    }



}
