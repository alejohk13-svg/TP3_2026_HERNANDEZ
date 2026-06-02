#ifndef __MENU_H
#define __MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

void MENU_Init(void);
void MENU_MostrarOpciones(void);
void MENU_ProcesarTeclado(char tecla);
void MENU_ActualizarContador(uint32_t seg);

#ifdef __cplusplus
}
#endif

#endif
