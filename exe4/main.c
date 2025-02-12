#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_RED = 5;
const int LED_BLUE = 8;
const int LED_ORANGE = 11;
const int LED_YELLOW = 15;
const int BTN = 28;


int main() {
  stdio_init_all();

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(LED_BLUE);
  gpio_set_dir(LED_BLUE, GPIO_OUT);

  gpio_init(LED_ORANGE);
  gpio_set_dir(LED_ORANGE, GPIO_OUT);

  gpio_init(LED_YELLOW);
  gpio_set_dir(LED_YELLOW, GPIO_OUT);


  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  while (true) {
    if (!gpio_get(BTN)) {
        gpio_put(LED_RED,1);
        sleep_ms(300);
        gpio_put(LED_RED,0);

        gpio_put(LED_BLUE,1);
        sleep_ms(300);
        gpio_put(LED_BLUE,0);

        gpio_put(LED_ORANGE,1);
        sleep_ms(300);
        gpio_put(LED_ORANGE,0);

        gpio_put(LED_YELLOW,1);
        sleep_ms(300);
        gpio_put(LED_YELLOW,0);
      }
    }
  }

