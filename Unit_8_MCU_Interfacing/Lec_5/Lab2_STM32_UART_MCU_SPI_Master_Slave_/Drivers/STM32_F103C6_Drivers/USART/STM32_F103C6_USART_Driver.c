/*
 * STM32_F103C6_USART_Driver.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Arsany
 */
//========================================================
//						Includes
//========================================================



#include "STM32_F103C6_USART_Driver.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//					Generic Variables
//========================================================
USART_Config_t * GL_UART_Config[3];





/**================================================================
 * @Fn			-MCAL_UART_Init
 * @brief		-Initializes the USARTx  according to the specified parameters of UART_Config
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in]	-UART_Config : Pointer to USART_Config_t which contains the configuration info for specified UART
 * @retval 		-None
 * Note 		-Supports Asynch mode only , 8Mhz clk
 */
void MCAL_UART_Init(USART_TypeDef *USARTx, USART_Config_t* UART_Config )
{
	uint32_t PCLK , BRR;




	//Enable Clock for given USART Peripheral
	if(USARTx == USART1 )
	{
		GL_UART_Config[0]=UART_Config;
		RCC_USART1_CLK_EN();
	}
	else if (USARTx == USART2)
	{
		GL_UART_Config[1]=UART_Config;
		RCC_USART2_CLK_EN();
	}
	else if (USARTx == USART3)
	{
		GL_UART_Config[2]=UART_Config;
		RCC_USART3_CLK_EN();
	}

	//Enable UART Module
	//	Bit 13 UE: USART enable
	//	When this bit is cleared the USART prescalers and outputs are stopped and the end of the current
	//	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	//	0: USART prescaler and outputs disabled
	//	1: USART enabled
	USARTx->CR1 |= 1<<13;

	//Tx / Rx Enable according to config
	USARTx->CR1 |= UART_Config->USART_MODE;

	//Data length
	USARTx->CR1 |= UART_Config->Data_Length;

	//Config Parity
	USARTx->CR1 |= UART_Config->Parity;

	//Config Stop Bits
	USARTx->CR2 |= UART_Config->Stop_Bits;

	//Config Flow Control
	USARTx->CR3 |= UART_Config->FlowCtrl;

	//Config of Baud rate Register
	if(USARTx == USART1)
	{
		PCLK = MCAL_RCC_GET_PCLK2();
	}
	else
	{
		PCLK = MCAL_RCC_GET_PCLK1();
	}

	BRR = UART_BRR_Reg(PCLK,UART_Config->BaudRate);

	USARTx->BRR = BRR;

	//Enable / Disable IRQ

	if (UART_Config->IRQ_Enable != USART_IRQ_EN_NONE)
	{

		USARTx->CR1 |= UART_Config->IRQ_Enable ;
		if(USARTx == USART1)
		{
			NVIC_IRQ37_USART1_Enable();
		}
		else if (USARTx == USART2)
		{
			NVIC_IRQ38_USART2_Enable();
		}
		else if (USARTx == USART3)
		{
			NVIC_IRQ39_USART3_Enable();
		}



	}



}


/**================================================================
 * @Fn			-MCAL_UART_Reset
 * @brief		-Resets the USARTx Registers
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-Supports Asynch mode only , 8Mhz clk
 */
void MCAL_UART_Reset(USART_TypeDef *USARTx )
{
	if(USARTx==USART1)
	{
		RCC_USART1_CLK_RESET();
		NVIC_IRQ37_USART1_Disable();
	}
	else if(USARTx==USART2)
	{
		RCC_USART2_CLK_RESET();
		NVIC_IRQ38_USART2_Disable();
	}
	else if(USARTx==USART3)
	{
		RCC_USART3_CLK_RESET();
		NVIC_IRQ39_USART3_Disable();
	}

}

/**================================================================
 * @Fn			-MCAL_UART_GPIO_Set_Pins
 * @brief		-Configure GPIO Pins to work as USART
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef *USARTx )
{
	GPIO_PinConfig_t PinConfig;
	if(USARTx==USART1)
	{
		//PA9 	Tx
		PinConfig.GPIO_PinNumber = GPIO_PIN_9;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		//PA10	Rx
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		//PA11	CTS
		if(GL_UART_Config[0]->FlowCtrl == USART_FlowCtrl_CTS || GL_UART_Config[0]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
		{
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


		//PA12	RTS
		{
			if (GL_UART_Config[0]->FlowCtrl == USART_FlowCtrl_RTS || GL_UART_Config[0]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
			{
				PinConfig.GPIO_PinNumber = GPIO_PIN_12;
				PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
				MCAL_GPIO_Init(GPIOA, &PinConfig);
			}
		}


	}
	else if (USARTx==USART2)
	{
		//PA2 	Tx
		PinConfig.GPIO_PinNumber = GPIO_PIN_2;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		//PA3	Rx
		PinConfig.GPIO_PinNumber = GPIO_PIN_3;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		//PA0	CTS
		if(GL_UART_Config[1]->FlowCtrl == USART_FlowCtrl_CTS || GL_UART_Config[1]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
		{
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


		//PA1	RTS
		{
			if (GL_UART_Config[1]->FlowCtrl == USART_FlowCtrl_RTS || GL_UART_Config[1]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
			{
				PinConfig.GPIO_PinNumber = GPIO_PIN_1;
				PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
				MCAL_GPIO_Init(GPIOA, &PinConfig);
			}
		}


	}
	else if(USARTx==USART3)
	{
		//PB10 	Tx
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
		MCAL_GPIO_Init(GPIOB, &PinConfig);


		//PB11	Rx
		PinConfig.GPIO_PinNumber = GPIO_PIN_11;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOB, &PinConfig);


		//PB13	CTS
		if(GL_UART_Config[2]->FlowCtrl == USART_FlowCtrl_CTS || GL_UART_Config[2]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
		{
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}


		//PB14	RTS
		{
			if (GL_UART_Config[2]->FlowCtrl == USART_FlowCtrl_RTS || GL_UART_Config[2]->FlowCtrl == USART_FlowCtrl_RTS_CTS)
			{
				PinConfig.GPIO_PinNumber = GPIO_PIN_14;
				PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
				MCAL_GPIO_Init(GPIOB, &PinConfig);
			}
		}


	}



}


/**================================================================
 * @Fn			-MCAL_UART_SendData
 * @brief		-Send data through Tx
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in] 	-TxDataBuffer : pointer to data to be sent
 * @param [in] 	-PollingEN : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_SendData(USART_TypeDef *USARTx,uint16_t * TxDataBuffer, Polling_Mechanism_t PollingEN)
{
	if (PollingEN == enable)
	{
		while (!(USARTx->SR & (1<<7)));
	}
	if(USARTx== USART1)
	{
		if (GL_UART_Config[0]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0x01FF);
		}
		else
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0xFF);
		}


	}
	else if(USARTx== USART2)
	{
		if (GL_UART_Config[1]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0x01FF);
		}
		else
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0xFF);
		}


	}
	else if(USARTx== USART3)
	{
		if (GL_UART_Config[2]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0x01FF);
		}
		else
		{
			USARTx->DR = (*TxDataBuffer & (uint16_t)0xFF);
		}


	}

}

/**================================================================
 * @Fn			-MCAL_UART_ReceiveData
 * @brief		-Receive data through Rx
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in] 	-RxDataBuffer : pointer to data to be sent
 * @param [in] 	-Polling_Mechanism : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_ReceiveData(USART_TypeDef *USARTx,uint16_t * RxDataBuffer, Polling_Mechanism_t PollingEN)
{
	if(PollingEN == enable)
	{
		while(! (USARTx->SR & (1<<5)));
	}

	if(USARTx == USART1)
	{
		if(GL_UART_Config[0]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			if(GL_UART_Config[0]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = USARTx->DR;
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			if(GL_UART_Config[0]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}

	}
	else if(USARTx == USART2)
	{
		if(GL_UART_Config[1]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			if(GL_UART_Config[1]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = USARTx->DR;
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			if(GL_UART_Config[1]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}

	}
	else if(USARTx == USART3)
	{
		if(GL_UART_Config[2]->Data_Length == USART_DATA_LEGNTH_9BIT)
		{
			if(GL_UART_Config[2]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = USARTx->DR;
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
		}
		else
		{
			if(GL_UART_Config[2]->Parity ==USART_PARITY_NONE)
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
			else
			{
				*((uint16_t*)RxDataBuffer) = (USARTx->DR & (uint8_t)0x7F);
			}
		}

	}


}


/**================================================================
 * @Fn			-MCAL_UART_WAIT_TC
 * @brief		-Checks whether data transmit finished or not
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_WAIT_TC(USART_TypeDef *USARTx)
{
	while(!(USARTx->SR & 1<<6));
}



void USART1_IRQHandler(void)
{
	GL_UART_Config[0] ->Ptr_IRQ_CallBack();
}
void USART2_IRQHandler(void)
{
	GL_UART_Config[1] ->Ptr_IRQ_CallBack();
}
void USART3_IRQHandler(void)
{
	GL_UART_Config[2]->Ptr_IRQ_CallBack();
}











