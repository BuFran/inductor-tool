#ifndef LEDS_H_INCLUDED
#define LEDS_H_INCLUDED

void leds_init(void);

#define LED0    GPIO12
#define LED1    GPIO13
#define LED2    GPIO14
#define LED3    GPIO15

#define LED_ALL    (GPIO12 | GPIO13 | GPIO14 | GPIO15)

#define LED_ON(led)     gpio_clear(GPIOD, (led))
#define LED_OFF(led)    gpio_set(GPIOD, (led))
#define LED_TGL(led)    gpio_toggle(GPIOD, (led))



#endif // LEDS_H_INCLUDED
