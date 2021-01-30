#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>

#include "led_ctrl.h"

void handle_sigint(int sig)
{
  printf("Caught signal %d\n", sig);
  ledCtrl_deinit();
  exit(0);
}

int main( int argc, char *argv[])
{
  printf("Hello there...\n");

  signal(SIGINT, handle_sigint);

  ledCtrl_init();
  while(1)
  {
    ledCtrl_setColor(LED_COLOR_GREEN);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_RED);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_BLUE);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_YELLOW);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_1);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_PURPLE);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_3);
    sleep(1);
    ledCtrl_setColor(LED_COLOR_OFF);
    sleep(1);
    /* waiting for signal */
  }
  
  return 0;
}
