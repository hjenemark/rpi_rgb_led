#ifndef LEDCTRL_H_
#define LEDCTRL_H_

typedef enum {
  LED_COLOR_GREEN,
  LED_COLOR_RED,
  LED_COLOR_BLUE,
  LED_COLOR_YELLOW,
  LED_COLOR_1,
  LED_COLOR_PURPLE,
  LED_COLOR_3,
  LED_COLOR_OFF
}ledCtrl_color_t;

int ledCtrl_init(void);

int ledCtrl_deinit(void);

void ledCtrl_setColor(ledCtrl_color_t color);

#endif /* LEDCTRL_H_ */

