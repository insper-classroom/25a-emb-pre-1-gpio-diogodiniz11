#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN =26;
const int  BTN_PIN2 =27;
const int  LED_PIN= 5;
const int  LED_PIN2= 6;

int main() {
    stdio_init_all();

    bool estado1 = false;
    bool estado2 = false;

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN2);
    gpio_set_dir(BTN_PIN2, GPIO_IN);
    gpio_pull_up(BTN_PIN2);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(LED_PIN2);
    gpio_set_dir(LED_PIN2, GPIO_OUT);

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            sleep_ms(50);
            while (!gpio_get(BTN_PIN)); 
            estado1 = !estado1;
            gpio_put(LED_PIN, estado1);
        }
        
        if (!gpio_get(BTN_PIN2)) {
            sleep_ms(50);
            while (!gpio_get(BTN_PIN2));
            estado2 = !estado2;
            gpio_put(LED_PIN2, estado2);
        }
        
        sleep_ms(10);
    }
    
    return 0;
}
