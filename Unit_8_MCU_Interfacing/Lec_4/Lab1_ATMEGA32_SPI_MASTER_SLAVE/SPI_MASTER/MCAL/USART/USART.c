/*
 * USART.c
 *
 *  Created on: Apr 17, 2024
 *      Author: Arsany
 */


#include "USART.h"




USART_Config_t *GL_USART_Config ;

/**================================================================
 * @Fn			-MCAL_USART_Init
 * @brief		-Initializes the USART  according to the specified parameters of USART_Config
 * @param [in]	-USART_Config : Pointer to USART_Config_t which contains the configuration info for  UART
 * @retval 		-None
 * Note 		-Supports Asynch mode only , 16Mhz clk
 */

void MCAL_USART_Init(USART_Config_t* USART_Config)
{
	GL_USART_Config = USART_Config;
	//Set BaudRate
	USART->UBRRL = USART_Config->BaudRate;
	//U2X Normal mode , U2X=0
	USART->UCSRA &= ~(1<<1);

	//----Enable Peripheral
	//Enable Receiver
	USART->UCSRB |= (1<<4);
	//Enable Transmitter
	USART->UCSRB |= (1<<3);

	//----Frame
	//Configure Parity Mode
	switch (USART_Config->Parity)
	{
//	 Bit 5:4 – UPM1:0: Parity Mode
//	 UPM1	UPM0	Parity Mode
//	 0		0		Disabled
//	 0		1		Reserved
//	 1		0		Enabled,Even Parity
//	 1		1		Enabled,Odd Parity
//
	case USART_PARITY_NONE:
		UCSRC |= (1<<7);		//The URSEL must be one when writing the UCSRC
		UCSRC &= ~(0b11<<4);
		break;
	case USART_PARITY_ODD:
		UCSRC |= (1<<7);
		UCSRC |= (0b11<<4);
		break;
	case USART_PARITY_EVEN:
		UCSRC |= (1<<7);
		UCSRC &= ~(1<<4);
		UCSRC |=  (1<<5);
		break;
	}
	//Configure Data size
	switch(USART_Config->Data_Length)
	{
//	 Bit 2:1 – UCSZ1:0: Character Size
//	 UCSZ2(UCSRB)	UCSZ1	UCSZ0	Bits
//	 	 0			  0		  0		5-Bits
//	 	 0			  0		  1		6-Bits
//	 	 0			  1		  0		7-Bits
//	 	 0			  1		  1		8-Bits
//	 	 1			  1		  1		9-Bits

	case USART_DATA_LEGNTH_5BIT:
		UCSRC |= (1<<7);
		USART->UCSRB &= ~(1<<2);
		UCSRC &= ~(1<<1);
		UCSRC &= ~(1<<2);
		break;

	case USART_DATA_LEGNTH_6BIT:
		UCSRC |= (1<<7);
		USART->UCSRB &= ~(1<<2);
		UCSRC |= (1<<1);
		UCSRC &= ~(1<<2);
		break;

	case USART_DATA_LEGNTH_7BIT:
		UCSRC |= (1<<7);
		USART->UCSRB &= ~(1<<2);
		UCSRC &= ~(1<<1);
		UCSRC |= (1<<2);
		break;

	case USART_DATA_LEGNTH_8BIT:
		UCSRC |= (1<<7);
		USART->UCSRB &= ~(1<<2);
		UCSRC |= (1<<1);
		UCSRC |= (1<<2);
		break;

	case USART_DATA_LEGNTH_9BIT:
		UCSRC |= (1<<7);
		USART->UCSRB |= (1<<2);
		UCSRC |= (1<<1);
		UCSRC |= (1<<2);
		break;

	}
	//Configure Stop Bits
	switch (USART_Config->Stop_Bits)
	{
//	Bit 3 – USBS: Stop Bit Select
//	0 : 1 Bit
//	1 : 2 Bit
	case USART_StopBits_1:
		UCSRC |= (1<<7);
		UCSRC &= ~(1<<3);
		break;

	case USART_StopBits_2:
		UCSRC |= (1<<7);
		UCSRC |= (1<<3);
		break;
	}
	//Choose Mode
	if(USART_Config->USART_MODE == USART_MODE_Synchronous )
	{
		UCSRC |= (1<<7);
		UCSRC |= (1<<6);
	}
	else if (USART_Config->USART_MODE == USART_MODE_Asynchronous )
	{
		UCSRC |= (1<<7);
		UCSRC &= ~(1<<6);
	}

	//Configure Interrupt
	switch (USART_Config->IRQ_Enable)
	{
	case USART_IRQ_DISABLED:
		USART->UCSRB &= ~(1<<7);
		USART->UCSRB &= ~(1<<6);
		DISABLE_GLOBAL_INTERRUPT();
		break;
	case USART_IRQ_EN_RXCIE:
		USART->UCSRB |= (1<<7);
		USART->UCSRB &= ~(1<<6);
		ENABLE_GLOBAL_INTERRUPT();
		break;
	case USART_IRQ_EN_TXCIE:
		USART->UCSRB &= ~(1<<7);
		USART->UCSRB |= (1<<6);
		ENABLE_GLOBAL_INTERRUPT();
		break;
	case USART_IRQ_EN_TXCIE_RXCIE:
		USART->UCSRB |= (1<<7);
		USART->UCSRB |= (1<<6);
		ENABLE_GLOBAL_INTERRUPT();
		break;

	}



}



/**================================================================
 * @Fn			-MCAL_USART_SEND
 * @brief		-Send data through Tx
 * @param [in] 	-TxBuffer : Data to be send
 * @param [in] 	-Polling : Polling Mode
 * @retval 		-None
 * Note 		-None
 */
void MCAL_USART_SEND(uint8_t TxBuffer , Polling_Mechanism_t Polling)
{
	//while((USART->UCSRA & (1<<6)));
	if(Polling)
	{
		while(!(USART->UCSRA & (1<<5)));

	}
	if((USART->UCSRB>>2)&1)
		{
	//		Bit 0 – TXB8: Transmit Data Bit 8
	//		TXB8 is the ninth data bit in the character to be transmitted when operating with serial frames
	//		with nine data bits. Must be written before writing the low bits to UDR.
			USART->UCSRB &=((TxBuffer & (1<<8))>>8);
			USART->UDR = ((uint8_t)TxBuffer);
		}
		else
		{
			USART->UDR = ((uint8_t)TxBuffer);
		}


}

/**================================================================
 * @Fn			-MCAL_USART_RECEIVE
 * @brief		-Receive data through Rx
 * @param [in] 	-Polling : Polling Mode
 * @retval 		-None
 * Note 		-None
 */

uint16_t MCAL_USART_RECEIVE (Polling_Mechanism_t Polling)
{
	uint16_t RxBuffer = 0;
	if (Polling)
	{
		while(!(USART->UCSRA & (1<<7)));
	}

	if((USART->UCSRB>>2)&1)
	{
//		Bit 1 – RXB8: Receive Data Bit 8
//		RXB8 is the ninth data bit of the received character when operating with serial frames with nine
//		data bits. Must be read before reading the low bits from UDR.
		RxBuffer |= ((USART->UCSRB>>1)<<8);
		RxBuffer |= USART->UDR;

	}
	else
	{
		RxBuffer |= USART->UDR;
	}
	return RxBuffer;


}


/**================================================================
 * @Fn			-MCAL_USART_SendString
 * @brief		-Send String through Tx
 * @param [in] 	-PtrTxBuffer : Pointer to string to be sent
 * @retval 		-None
 * Note 		-None
 */

void MCAL_USART_SendString(uint8_t* PtrTxBuffer)
{
	while (*PtrTxBuffer != '\0')
	{
		while(!((USART->UCSRA>>5)&1));
		MCAL_USART_SEND(*PtrTxBuffer,Polling_DISABLED);
		PtrTxBuffer++;
	}
	while(!((USART->UCSRA>>5)&1));
	USART->UDR = '\r';

}
/**================================================================
 * @Fn			-MCAL_USART_ReceiveString
 * @brief		-Recieve String through Rx
 * @param [in] 	-PtrRxBuffer : Pointer to string to be Recieved
 * @retval 		-None
 * Note 		-None
 */
void MCAL_USART_ReceiveString(uint8_t* PtrRxBuffer)
{
	while(1)
	{
		while(!((USART->UCSRA>>7)&1));
		*PtrRxBuffer = USART->UDR;
		if(*PtrRxBuffer == '\r')
		{
			break;
		}
		else
		{
			PtrRxBuffer++;
		}
	}
}






ISR(USART_RXC_vect)
{
	GL_USART_Config->Ptr_IRQ_CallBack();
}


