// bibliotecas básicas
#include <stdio.h>
#include <string.h>

// bibliotecas do freeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// bibliotecas do ESP32
#include "driver/gpio.h"
#include "esp_log.h"


//Definido pino do led a ser usado
#define tempo_ms 1000


//Definindo variáveis
bool status_led = 1;
uint8_t i=0, j=0;
uint16_t leds_pin[] =  {12,13,14};              //pins of the leds
char *led_names[]= { "blue","green","red" };    //name of the leds

void app_main(void)
{
    for (i=0; i<3; i++)                         //for each led
    {
        gpio_reset_pin(leds_pin[i]);                       //resets the GPIO pin to its default state.
        gpio_set_direction(leds_pin[i], GPIO_MODE_OUTPUT); //configures the GPIO pin as an output.
        gpio_set_level(leds_pin[i], 0);                    //sets the output level of the GPIO pin.
    }
    i=0;
    while(1)
    {
        for (j=0; j<2; j++)                      //blink 2 times each led
        {
            gpio_set_level(leds_pin[i], status_led);            //sets the output level of the GPIO pin.
            printf ("Led %s: %d\n", led_names[i], status_led);  //prints the name of the led and its status

            vTaskDelay(tempo_ms / portTICK_PERIOD_MS);          //delay for 1 second

            status_led=!status_led;                             //change the status of the led
        }

        i++;                                                    //change the led
        i=i%3;                                                  //to a maximum of 3-1
        
    }
}
