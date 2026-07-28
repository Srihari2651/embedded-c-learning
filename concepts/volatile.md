#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>                                                   /* RCC Registers */
#define RCC_BASE        0x40021000UL
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))     /* GPIOC Registers */
#define GPIOC_BASE      0x40011000UL
#define GPIOC_CRH       (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR       (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))   /* Onboard LED */
#define LED_PIN         13U

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1
}
gpio_state_t;

void gpio_led_init(void);
void gpio_led_write(gpio_state_t state);
void gpio_led_toggle(void);

#endif
