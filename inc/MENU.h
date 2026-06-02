#ifndef __MENU_H
#define __MENU_H

#ifdef __cplusplus
extern "C" {
#endif

void MENU_Init(void);
void MENU_MostrarOpciones(void);
void MENU_ProcesarTeclado(char tecla);

#ifdef __cplusplus
}
#endif

#endif
