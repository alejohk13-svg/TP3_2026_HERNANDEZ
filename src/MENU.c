#include "MENU.h"
#include "LCD.h"

#define TOTAL_OPCIONES  5
#define LINEAS_DISPLAY  4

typedef enum {
    PANTALLA_PRINCIPAL,
    PANTALLA_TECLA
} modo_pantalla_t;

static modo_pantalla_t modo_actual = PANTALLA_PRINCIPAL;
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
    modo_actual = PANTALLA_PRINCIPAL;
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
    if (modo_actual == PANTALLA_PRINCIPAL)
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
                LCD_clrscr();
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
                LCD_clrscr();
                MENU_MostrarOpciones();
            }
        }
        else if (tecla == 'C')
        {
            if (opcion_seleccionada == 0)
            {
                modo_actual = PANTALLA_TECLA;
                LCD_clrscr();
                LCD_WriteString(0, 0, "Tecla: --");
            }
        }
    }
    else if (modo_actual == PANTALLA_TECLA)
    {
        if (tecla == 'D')
        {
            modo_actual = PANTALLA_PRINCIPAL;
            LCD_clrscr();
            MENU_MostrarOpciones();
        }
        else
        {
            LCD_gotoxy(7, 0);
            LCD_putc(tecla);
            LCD_putc(' ');
        }
    }
}
