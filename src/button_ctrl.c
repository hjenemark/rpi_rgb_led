#include <stdio.h>
#include <stdint.h>

#include "gpio.h"
#include "led_ctrl.h"
#include "button_ctrl.h"
/*
typedef struct {
  ledCtrl_color_t base_color;
  int bcmPinNo;
}led_map_t;

static const led_map_t led_map[] = 
{
  {LED_COLOR_GREEN, 17},
  {LED_COLOR_RED,   27},
  {LED_COLOR_BLUE,  18}
};
*/
int btnCtrl_init(void)
{
  gpio_init(22, GPIO_INPUT, GPIO_HIGH);

  return 0;
}

int ledCtrl_deinit(void)
{
  gpio_deinit(led_map[0].bcmPinNo);
  gpio_deinit(led_map[1].bcmPinNo);
  gpio_deinit(led_map[2].bcmPinNo);

  return 0;
}

void ledCtrl_setColor(ledCtrl_color_t color)
{
  switch (color) 
  {
    case LED_COLOR_GREEN:
      gpio_setHigh(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_RED:
      gpio_setLow(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_BLUE:
      gpio_setLow(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_YELLOW:
      gpio_setHigh(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_1:
      gpio_setHigh(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_PURPLE:
      gpio_setLow(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_3:
      gpio_setHigh(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setHigh(led_map[LED_COLOR_BLUE].bcmPinNo);
      break;
    case LED_COLOR_OFF:
    default:
      gpio_setLow(led_map[LED_COLOR_GREEN].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_RED].bcmPinNo);
      gpio_setLow(led_map[LED_COLOR_BLUE].bcmPinNo);
    break;
  }
}


