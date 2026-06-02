#include "MENU.h"
#include "LCD.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define TOTAL_OPCIONES  5
#define LINEAS_DISPLAY  4

typedef enum {
    PANTALLA_PRINCIPAL,
    PANTALLA_TECLA,
    PANTALLA_BACKLIGHT
} modo_pantalla_t;

static modo_pantalla_t modo_actual = PANTALLA_PRINCIPAL;
static uint8_t opcion_seleccionada = 0;
static uint8_t ventana_inicio = 0;
static uint8_t backlight_encendido = 1;

static const char *opciones_menu[TOTAL_OPCIONES] = {
    "1.Tecla Presionada ",
    "2.Backlight        ",
    "3.Contador         ",
    "4.Datos Alumno     ",
    "5.Datos Materia    "
};

void MENU_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_SetBits(GPIOD, GPIO_Pin_8);
    backlight_encendido = 1;

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
    if (tecla == '#')
    {
        backlight_encendido = 1;
        GPIO_SetBits(GPIOD, GPIO_Pin_8);
        if (modo_actual == PANTALLA_BACKLIGHT)
        {
            LCD_WriteString(11, 0, "ON ");
        }
    }
    else if (tecla == '*')
    {
        backlight_encendido = 0;
        GPIO_ResetBits(GPIOD, GPIO_Pin_8);
        if (modo_actual == PANTALLA_BACKLIGHT)
        {
            LCD_WriteString(11, 0, "OFF");
        }
    }

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
            else if (opcion_seleccionada == 1)
            {
                modo_actual = PANTALLA_BACKLIGHT;
                LCD_clrscr();
                LCD_WriteString(0, 0, "Backlight: ");
                if (backlight_encendido)
                {
                    LCD_WriteString(11, 0, "ON ");
                }
                else
                {
                    LCD_WriteString(11, 0, "OFF");
                }
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
        else if (tecla != '#' && tecla != '*')
        {
            LCD_gotoxy(7, 0);
            LCD_putc(tecla);
            LCD_putc(' ');
        }
    }
    else if (modo_actual == PANTALLA_BACKLIGHT)
    {
        if (tecla == 'D')
        {
            modo_actual = PANTALLA_PRINCIPAL;
            LCD_clrscr();
            MENU_MostrarOpciones();
        }
    }
}
