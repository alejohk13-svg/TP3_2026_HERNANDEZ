#include "MENU.h"
#include "LCD.h"

#define TOTAL_OPCIONES  5
#define LINEAS_DISPLAY  4

static uint8_t opcion_seleccionada = 0;
static uint8_t ventana_inicio = 0;

static const char *opciones_menu[TOTAL_OPCIONES] = {
    "1.Tecla Presionada ",
    "2.Backlight        ",
    "3.Contador         ",
    "4.Datos Alumno     ",
    "5.Datos Materia    "
};

void MENU_Init(void)
{
    LCD_clrscr();
    MENU_MostrarOpciones();
}

void MENU_MostrarOpciones(void)
{
    uint8_t i;
    uint8_t indice_opcion;

    for (i = 0; i < LINEAS_DISPLAY; i++)
    {
        indice_opcion = ventana_inicio + i;

        LCD_gotoxy(0, i);

        if (indice_opcion == opcion_seleccionada)
        {
            LCD_putc('>');
        }
        else
        {
            LCD_putc(' ');
        }

        LCD_puts((char *)opciones_menu[indice_opcion]);
    }
}

void MENU_ProcesarTeclado(char tecla)
{
    if (tecla == 'A')
    {
        if (opcion_seleccionada > 0)
        {
            opcion_seleccionada--;

            if (opcion_seleccionada < ventana_inicio)
            {
                ventana_inicio = opcion_seleccionada;
            }

            MENU_MostrarOpciones();
        }
    }
    else if (tecla == 'B')
    {
        if (opcion_seleccionada < (TOTAL_OPCIONES - 1))
        {
            opcion_seleccionada++;

            if (opcion_seleccionada >= (ventana_inicio + LINEAS_DISPLAY))
            {
                ventana_inicio++;
            }

            MENU_MostrarOpciones();
        }
    }
}
