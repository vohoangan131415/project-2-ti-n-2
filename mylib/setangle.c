#include "setangle.h"
uint8_t unlock[] = {0xFF, 0XAA, 0X69, 0X88,0XB5}; 
uint8_t save[] = {0xFF, 0XAA, 0X00, 0X00, 0X00};
UART_HandleTypeDef *huart;
angleRead_t angle;
uint8_t time_read = 0;
void send_command(UART_HandleTypeDef *huart)
{
	// step 1
	HAL_UART_Transmit(huart, unlock, 1, 100);
	time_read = HAL_GetTick();
	HAL_Delay(1000);
	// step 2
	
	setgoc0();
	HAL_Delay(1000);
	

	// step 3
	HAL_UART_Transmit(huart, save, 1, 100);
	HAL_Delay(1000);
}
void setgoc0()
{
	uart_handle(&angle);
	angle.z = 0;
	
}

