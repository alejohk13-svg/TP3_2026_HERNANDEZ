#include "stm32f4xx.h"
#include "global.h"
#include "../LCD/LCD.h"
#include "../Menu/MENU.h"
#include "../Teclado/TECLADO.h"

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    sysTime_Init();
    LCD_init();
    teclado_init();
    MENU_Init();

    while (1)
    {
        char tecla_actual = teclado_getKey();
        MENU_Update(tecla_actual);
    }
}
