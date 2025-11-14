#include "stm32f3xx.h"

void delay(volatile uint32_t t)
{
    while(t--) __asm__("nop");
}

int main(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    RCC->AHBENR |= RCC_AHBENR_GPIODEN;

    GPIOD->MODER &= ~(0xFF << (12 * 2));
    GPIOD->MODER |=  (0x55 << (12 * 2));

    GPIOA->MODER &= ~(3 << (0 * 2));
    GPIOA->PUPDR &= ~(3 << (0 * 2));

    GPIOD->ODR |= (1 << 12);
    GPIOD->ODR |= (1 << 13);
    GPIOD->ODR |= (1 << 14);
    GPIOD->ODR |= (1 << 15);

    while (1)
    {
        if (GPIOA->IDR & 1)
        {
            delay(50000);

            if (GPIOA->IDR & 1)
            {
                GPIOD->ODR &= ~(1 << 12);
                GPIOD->ODR &= ~(1 << 13);
                GPIOD->ODR &= ~(1 << 14);
                GPIOD->ODR &= ~(1 << 15);
            }
        }
    }
}
