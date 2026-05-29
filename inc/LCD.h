#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(unsigned char fila, unsigned char columna);
void LCD_WriteString(char *str);

#endif
