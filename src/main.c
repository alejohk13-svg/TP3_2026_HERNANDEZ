#include "stm32f4xx.h"
#include "LCD.h"
#include "MENU.h"
#include "teclado.h"

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
    uint32_t last_tick_teclado = 0;
    char tecla_actual = 0;

    if (SysTick_Config(SystemCoreClock / 1000))
    {
        while (1);
    }

    LCD_init();
    teclado_init(); // Configura puertos A, C y E para el teclado matricial
    MENU_Init();

    while (1)
    {
        if ((msTicks - last_tick_teclado) >= 1)
        {
            last_tick_teclado = msTicks;
            teclado_update();
        }

        tecla_actual = teclado_getKey();

        if (tecla_actual != 0)
        {
            MENU_ProcesarTeclado(tecla_actual);
        }
    }
}
