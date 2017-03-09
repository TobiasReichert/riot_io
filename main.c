#include <unistd.h>
#include <stdio.h>
#include "periph/gpio.h"


bool b;

void callback(void){
    printf("INT callback bool: %i\n",b);
    b = !b;
}

int main(void){
  b = true;
  gpio_init_int(GPIO_PIN(PA,28), GPIO_IN_PU, GPIO_FALLING, (gpio_cb_t)callback, NULL);
  gpio_init (GPIO_PIN(PA,19), GPIO_OUT);
  for(;;){
    if(b){
      gpio_set(GPIO_PIN(PA,19));
      usleep(500000);
      gpio_clear(GPIO_PIN(PA,19));
      printf("abc\n");
    }
    usleep(500000);
  }
  return 0;
}
