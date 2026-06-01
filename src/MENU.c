#include "MENU.h"
#include "LCD.h"

#define TOTAL_OPCIONES  5

static const char *opciones_menu[TOTAL_OPCIONES] = {
    "1. Tecla Presionada",
    "2. Backlight       ",
    "3. Contador        ",
    "4. Datos Alumno    ",
    "5. Datos Materia   "
};

void MENU_Init(void)
{
    LCD_clrscr();
    MENU_MostrarOpciones();
}

void MENU_MostrarOpciones(void)
{
    LCD_WriteString(0, 0, (char *)opciones_menu[0]);
    LCD_WriteString(0, 1, (char *)opciones_menu[1]);
    LCD_WriteString(0, 2, (char *)opciones_menu[2]);
    LCD_WriteString(0, 3, (char *)opciones_menu[3]);
}
