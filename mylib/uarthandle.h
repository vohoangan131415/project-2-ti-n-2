#ifndef UARTHANDLE_H
#define UARTHANDLE_H

#include "stdint.h"
#include "stm32f1xx.h"

typedef struct
{
	float x;
	float y;
	float z;
}angleRead_t;

void data_receive(uint8_t data);
short data_handle(uint8_t dataH, uint8_t dataL);
void uart_handle(angleRead_t *angle);
void uart_init();


#endif


