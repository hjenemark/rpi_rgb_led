
#ifndef GPIO_H_
#define GPIO_H_

typedef enum {
  GPIO_HIGH,
  GPIO_LOW
}gpio_state_t;

typedef enum {
  GPIO_OUTPUT,
  GPIO_INPUT
}gpio_dir_t;

/** Initializes a pin with direction and initial state
 * @parm pinNo BCM pin number
 * @parm dir direction of data
 * @parm state initial state of the pin
 *
 * @return 0 on success
 * */

uint8_t gpio_init(int pinNo, gpio_dir_t dir, gpio_state_t state);

/** DeInitializes specific pin
 * @parm pinNo BCM pin number
 *
 * @return 0 on success
 * */
uint8_t gpio_deinit(int pinNo);

/** Set a pin high
 * @parm pinNo BCM pin number
 * */
void gpio_setHigh(int pinNo);

/** Sets a pin low
 * @parm pinNo BCM pin number
 * */
void gpio_setLow(int pinNo);

#endif /* GPIO_H_ */
