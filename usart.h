#ifndef USART_H
#define USART_H
#include "gd32e23x.h"
#include <stdio.h>
#include "gd32e230c_eval.h"

void com_gpio_init(void);
void com_usart_init(void);
int fputc(int ch, FILE *f);


		
#endif

