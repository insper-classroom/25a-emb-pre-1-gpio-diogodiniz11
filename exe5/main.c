#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int BT1 = 26;
int BT2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BT1);
    gpio_set_dir(BT1, GPIO_IN);
    gpio_pull_up(BT1);

    gpio_init(BT2);
    gpio_set_dir(BT2, GPIO_IN);
    gpio_pull_up(BT2);

    int bt1_contagem = 0;
    int bt2_contagem = 0;

    while (true) {
        if (!gpio_get(BT1)) {
            printf("Botao 1: %d\n", bt1_contagem++);
            sleep_ms(300);
        }

        if (!gpio_get(BT2)) {
            printf("Botao 2: %d\n", bt2_contagem++);
            sleep_ms(300);
        }

    }
}
