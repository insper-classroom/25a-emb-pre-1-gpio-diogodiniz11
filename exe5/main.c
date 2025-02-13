#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int BT1 = 7;
int BT2 = 26;

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
            while (!gpio_get(BT1));
            bt1_contagem +=1 ;
            sleep_ms(50);
            printf("Botão 1 pressionado %d vezes\n", bt1_contagem);
        }

        if (!gpio_get(BT2)) {
            while (!gpio_get(BT2));
            bt2_contagem +=1 ;
            sleep_ms(50);
            printf("Botão 2 pressionado %d vezes\n", bt2_contagem);
        }

        sleep_ms(10);
    }
    
    return 0;
}
