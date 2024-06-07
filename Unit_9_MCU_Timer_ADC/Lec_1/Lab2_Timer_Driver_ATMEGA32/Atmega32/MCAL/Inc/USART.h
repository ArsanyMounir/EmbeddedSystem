/*
 * USART.h
 *
 *  Created on: Apr 17, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_USART_H_
#define MCAL_INC_USART_H_

//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32_GPIO_Driver.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------
#define STRING_STOP 							'\r'


//========================================================
//				Configuration Structure
//========================================================


typedef struct
{
	uint8_t USART_MODE ; 		//Specifies the USART Mode (Synchronous / Asynchronous)
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_MODE_Define

	uint32_t BaudRate ;			//Specifies the UART communication Baud rate
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_BaudRate_Define

	uint8_t Data_Length ; 	 	//Specifies number of data bits in frame
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_Data_Legth_Define


	uint8_t Parity;				//Specifies Parity Bits mode
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_Parity_Define

	uint8_t Stop_Bits;			//Specifies Number of Stop Bits
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_Stop_Bits_Define


	uint8_t IRQ_Enable;			//Enables Or Disable USART IRQ Tx/Rx
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_USART_IRQ_Define


	void (* Ptr_IRQ_CallBack)(void); //Set C function to be called once IRQ Happens



}USART_Config_t;



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			Macros Configuration References
//========================================================

//@ref USART_MODE_Define

#define  USART_MODE_Synchronous 							1
#define  USART_MODE_Asynchronous 							0

//------------------------------------------
//@ref USART_BaudRate_Define
//Based on TRM table for Fclk = 16Mhz
//with Asynchronous Mode , U2X = 0

#define  USART_BaudRate_2400 						416
#define  USART_BaudRate_4800 						207
#define  USART_BaudRate_9600 						103
#define  USART_BaudRate_14400 						68
#define  USART_BaudRate_19200 						51
#define  USART_BaudRate_28800 						34
#define  USART_BaudRate_38400 						25
#define  USART_BaudRate_57600 						16
#define  USART_BaudRate_76800 						12
#define  USART_BaudRate_115200 						8
#define  USART_BaudRate_230400 						3
#define  USART_BaudRate_250000						3
#define  USART_BaudRate_500000						1
#define  USART_BaudRate_1000000						0



//------------------------------------------
//@ref USART_Data_Legth_Define

#define  USART_DATA_LEGNTH_5BIT						0
#define  USART_DATA_LEGNTH_6BIT						1
#define  USART_DATA_LEGNTH_7BIT						2
#define  USART_DATA_LEGNTH_8BIT						3
#define  USART_DATA_LEGNTH_9BIT						4



//------------------------------------------
//@ref USART_Parity_Define
#define USART_PARITY_NONE							0
#define USART_PARITY_ODD							1
#define USART_PARITY_EVEN							2



//------------------------------------------
//@ref USART_Stop_Bits_Define
#define USART_StopBits_1							0
#define USART_StopBits_2							1


//------------------------------------------
//@ref USART_USART_IRQ_Define
#define USART_IRQ_DISABLED							0		//No IRQ Enabled
#define USART_IRQ_EN_TXCIE							1 		//Tx Complete Interrupt Enable
#define USART_IRQ_EN_RXCIE							2 		//Rx Complete Interrupt Enable
#define USART_IRQ_EN_TXCIE_RXCIE					3 		//Tx & Rx Complete Interrupt Enable

typedef enum
{
	Polling_ENABLED,
	Polling_DISABLED
}Polling_Mechanism_t;

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "MCAL UART DRIVER"
//========================================================


void MCAL_USART_Init(USART_Config_t* USART_Config);

void MCAL_USART_SEND(uint8_t TxBuffer , Polling_Mechanism_t Polling);
uint16_t MCAL_USART_RECEIVE (Polling_Mechanism_t Polling);

void MCAL_USART_SendString(uint8_t* PtrTxBuffer);
void MCAL_USART_ReceiveString(uint8_t* PtrRxBuffer);


#endif /* MCAL_INC_USART_H_ */
