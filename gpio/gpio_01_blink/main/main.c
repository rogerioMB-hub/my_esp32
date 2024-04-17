// basico
#include <stdio.h>

// freeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// esp32 - gpio
#include "driver/gpio.h"

#define led1_pin 12
#define tempo_ms 500

void app_main(void)
{
    // definir pino como gpio - reset da config do pino
    gpio_reset_pin(LED1_PIN);
    // definir direção do pino de io
    gpio_set_direction(led1_pin, GPIO_MODE_OUTPUT);
    // loop infinito
    while(1)
    {
        // escrever nivel lógico 1 no pino de io
        gpio_set_level(LED1_PIN, 1); 
        // esperar/trancar operaçoes por um tempo
        vTaskDelay(tempo_ms / portTICK_PERIOD_MS);
        // escrever nivel lógico 0 no pino de io
        gpio_set_level(LED1_PIN, 0);
        // esperar/trancar operaçoes por um tempo
        vTaskDelay(tempo_ms / portTICK_PERIOD_MS);
    }   
}
