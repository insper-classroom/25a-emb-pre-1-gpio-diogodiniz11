#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_GREEN = 26;
const int BTN_RED = 28;
const int LED_RED = 6;
const int LED_GREEN = 4;

int main() {
    stdio_init_all();

    bool led_red_state = false;
    bool led_green_state = false;

    gpio_init(BTN_RED);
    gpio_set_dir(BTN_RED, GPIO_IN);
    gpio_pull_up(BTN_RED);

    gpio_init(BTN_GREEN);
    gpio_set_dir(BTN_GREEN, GPIO_IN);
    gpio_pull_up(BTN_GREEN);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    while (true) {
        if (!gpio_get(BTN_RED)) {
            sleep_ms(50);
            while (!gpio_get(BTN_RED)); 
            led_red_state = !led_red_state;
            gpio_put(LED_RED, led_red_state);
            printf("Botão VERDE pressionado, LED VERDE: %d\n", led_red_state);
        }
        
        if (!gpio_get(BTN_GREEN)) {
            sleep_ms(50);
            while (!gpio_get(BTN_GREEN));
            led_green_state = !led_green_state;
            gpio_put(LED_GREEN, led_green_state);
            printf("Botão VERMELHO pressionado, LED VERMELHO: %d\n", led_green_state);
        }
        
        sleep_ms(10);
    }
    
    return 0;
}
