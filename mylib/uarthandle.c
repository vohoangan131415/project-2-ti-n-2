#include "uarthandle.h"
#include "string.h"
#define DATA_LEN 11

#define DATA_LEN 11

uint8_t buff[DATA_LEN];
static uint8_t uart_len = 0;
static uint8_t uart_flag = 0;
static uint8_t receive_flag = 0;


//Receive and storage data from uart protocol
void data_receive(uint8_t data)
{
	if(data == 0x55 && uart_len == 0)
	{
		receive_flag = 1;
	}
	
	if(receive_flag)
	{
		if(uart_len == 10)
		{
			buff[uart_len] = data;
			uart_flag = 1;
			receive_flag = 0;
		}
		else
		{
			buff[uart_len++] = data;
		}

	}
}
//==============================================//
// handling hex data to the angle of x, y, z


short data_handle(uint8_t dataH, uint8_t dataL)
{
	   short Adata = ((short)dataH<<8|dataL); // accurate value of data 
		 return Adata;
}
//---------------------------------------------//
void uart_handle(angleRead_t *angle)
{
	
	if(uart_flag)
{
	// X value
			angle->x = (float)(data_handle(buff[3], buff[2]))/ 32768*180;			
	// Y value		
			
			angle->y = (float)(data_handle(buff[5], buff[4]))/ 32768*180;
	// z value		
			angle->z = (float)(data_handle(buff[7], buff[6]))/ 32768*180;
		
	
	uart_flag = 0; // flag reset
	uart_len = 0; // length reset
	
	
}
}

//====================================//



