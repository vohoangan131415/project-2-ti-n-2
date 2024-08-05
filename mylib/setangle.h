#ifndef SETANGLE_H
#define SETANGLE_H
#include "stm32f1xx.h"
#include "uarthandle.h"
extern angleRead_t angle;
extern UART_HandleTypeDef *huart;
void setgoc0();
extern uint8_t time_read;
void send_command(UART_HandleTypeDef *huart);

#endif