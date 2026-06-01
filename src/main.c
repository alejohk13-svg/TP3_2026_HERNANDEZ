#include "stm32f4xx.h"
#include "LCD.h"
#include "MENU.h"

volatile uint32_t msTicks = 0;

void SysTick_Handler(void)
{
    msTicks++;
}

void delay_ms(uint32_t ms)
{
    uint32_t currentTicks = msTicks;
    while ((msTicks - currentTicks) < ms);
}

int main(void)
{

    if (SysTick_Config(SystemCoreClock / 1000))
    {
        while (1);
    }

    LCD_init();

    MENU_Init();

    while (1)
    {
    }
}
