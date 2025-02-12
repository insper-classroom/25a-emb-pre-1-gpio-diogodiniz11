#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN_PIN2 =27;

const int LED_PIN = 5;
const int LED_PIN2 = 6;


int main() {
  stdio_init_all();

  int contador1 = 1;
  int contador2 = 1;

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      contador1 +=1 ;

    while (contador1%2 == 0) {
        gpio_put(LED_PIN, 1);
        sleep_ms(300);

        if (!gpio_get(BTN_PIN2)) {
          contador2 +=1 ;

        while (contador2%2 == 0) {
            gpio_put(LED_PIN2, 1);
            sleep_ms(300);
            if (!gpio_get(BTN_PIN)){
              gpio_put(LED_PIN, 0);
              sleep_ms(300);
              contador1 +=1 ; }

            if (!gpio_get(BTN_PIN2)){
              gpio_put(LED_PIN2, 0);
              sleep_ms(300);
              contador2 +=1 ;}}}

        if (!gpio_get(BTN_PIN)){
          gpio_put(LED_PIN, 0);
          sleep_ms(300);
          contador1 +=1 ; }}}

  if (!gpio_get(BTN_PIN2)) {
    contador2 +=1 ;

  while (contador2%2 == 0) {
      gpio_put(LED_PIN2, 1);
      sleep_ms(300);

      if (!gpio_get(BTN_PIN)) {
        contador1 +=1 ;

      while (contador1%2 == 0) {
          gpio_put(LED_PIN, 1);
          sleep_ms(300);
          if (!gpio_get(BTN_PIN2)){
            gpio_put(LED_PIN2, 0);
            sleep_ms(300);
            contador2 +=1 ;}

          if (!gpio_get(BTN_PIN)){
            gpio_put(LED_PIN, 0);
            sleep_ms(300);
            contador1 +=1 ;
          }    
      }
      }
      if (!gpio_get(BTN_PIN2)){
        gpio_put(LED_PIN2, 0);
        sleep_ms(300);
        contador2 +=1 ;}}}}
      return 0;}
  
