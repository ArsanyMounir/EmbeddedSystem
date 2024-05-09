/*
 * STM32_F103C6_SPI_Driver.c
 *
 *  Created on: May 8, 2024
 *      Author: Arsany
 */

//========================================================
//						Includes
//========================================================


#include "STM32_F103C6_SPI_Driver.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------
SPI_Config_t* GL_SPI_Config[2]= {NULL,NULL};


/**================================================================
 * @Fn			-MCAL_SPI_Init
 * @brief		-Initializes the SPIx  according to the specified parameters of SPI_Config
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @param [in]	-SPI_Config : Pointer to SPI_Config_t which contains the configuration info for specified SPI
 * @retval 		-None
 * Note 		-Supports SPI Full Duplex Master/Slave Only
 */
void MCAL_SPI_Init (SPI_TypeDef *SPIx,SPI_Config_t *SPI_Config)
{
	uint16_t temp_CR1 = 0;
	uint16_t temp_CR2 = 0;

	if (SPIx == SPI1)
	{
		GL_SPI_Config[0] = SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if (SPIx == SPI2)
	{
		GL_SPI_Config[1] = SPI_Config;
		RCC_SPI2_CLK_EN();
	}


	//Enable SPI
	temp_CR1 = (uint16_t)(1<<6) ;

	//Master or Slave
	temp_CR1 |= SPI_Config->Device_MODE;

	// SPI Mode
	temp_CR1 |= SPI_Config->SPI_MODE;

	//Frame Format
	temp_CR1 |= SPI_Config->Frame_Format;

	//Data size
	temp_CR1 |= SPI_Config->Data_Size;

	//Clock Polarity
	temp_CR1 |= SPI_Config->Clock_Polarity;

	//Clock Phase
	temp_CR1 |= SPI_Config->Clock_Phase;

	//NSS
	if(SPI_Config->NSS_Mode == SPI_NSS_HARDWARE_MASTER_Output_EN)
	{
		temp_CR2 |=  SPI_Config->NSS_Mode;
	}
	else if (SPI_Config->NSS_Mode == SPI_NSS_HARDWARE_MASTER_Output_DIS)
	{
		temp_CR2 &=  SPI_Config->NSS_Mode;
	}
	else

	{
		temp_CR1 |= SPI_Config->NSS_Mode;
	}


	//BaudRate Prescaler
	temp_CR1 |= SPI_Config->BaudRate_PreScaler;

	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		temp_CR2 |= SPI_Config->IRQ_Enable;
		if(SPIx==SPI1)
		{
			NVIC_IRQ35_SPI1_Enable();
		}
		else if (SPIx==SPI2)
		{
			NVIC_IRQ36_SPI2_Enable();
		}
	}

	SPIx->CR1 = temp_CR1;

	SPIx->CR2 = temp_CR2;

}

/**================================================================
 * @Fn			-MCAL_SPI_Reset
 * @brief		-De-Initializes the SPIx  according to the specified parameters of SPI_Config
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @retval 		-None
 * Note 		-None
 */
void MCAL_SPI_Reset (SPI_TypeDef *SPIx)
{
	if (SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable();
		RCC_SPI1_CLK_RESET();
	}
	else if (SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable();
		RCC_SPI2_CLK_RESET();
	}


}


/**================================================================
 * @Fn			-MCAL_SPI_GPIO_Set_Pins
 * @brief		-Configure GPIO Pins to work as SPI
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @retval 		-None
 * Note 		-None
 */

void MCAL_SPI_GPIO_Set_Pins (SPI_TypeDef *SPIx)
{
	GPIO_PinConfig_t PinConfig;
	if (SPIx == SPI1)
	{
		//SPI1
		//PA4 : NSS
		//PA5 : SCK
		//PA6 : MISO
		//PA7 : MOSI

		if(GL_SPI_Config[0]->Device_MODE == SPI_Device_Mode_MASTER)
		{

			//==============PA4 : NSS===============
			switch (GL_SPI_Config[0]->NSS_Mode)
			{
			case SPI_NSS_HARDWARE_MASTER_Output_DIS:
				PinConfig.GPIO_PinNumber = GPIO_PIN_4;
				PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinConfig);
				break;
			case SPI_NSS_HARDWARE_MASTER_Output_EN:

				PinConfig.GPIO_PinNumber = GPIO_PIN_4;
				PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
				MCAL_GPIO_Init(GPIOA, &PinConfig);
				break;

			}

			//==============PA5 : SCK===============
			PinConfig.GPIO_PinNumber = GPIO_PIN_5;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);


			//==============PA6 : MISO===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_6;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);

			//==============PA7 : MOSI===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_7;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);

		}
		else if(GL_SPI_Config[0]->Device_MODE == SPI_Device_Mode_SLAVE)
		{
			//==============PA4 : NSS===============
			if(GL_SPI_Config[0]->NSS_Mode == SPI_NSS_HARDWARE_SLAVE)
			{
			PinConfig.GPIO_PinNumber = GPIO_PIN_4;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
			}

			//==============PA5 : SCK===============
			PinConfig.GPIO_PinNumber = GPIO_PIN_5;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);


			//==============PA6 : MISO===============
			//Support Only Full Duplex (point to point)
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_6;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);

			//==============PA7 : MOSI===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_7;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);

		}



	}

	else if (SPIx == SPI2)
	{
		//SPI2
		//PB12 : NSS
		//PB13 : SCK
		//PB14 : MISO
		//PB15 : MOSI
		if(GL_SPI_Config[1]->Device_MODE == SPI_Device_Mode_MASTER)
		{

			//==============PB12 : NSS===============
			switch (GL_SPI_Config[1]->NSS_Mode)
			{
			case SPI_NSS_HARDWARE_MASTER_Output_DIS:
				PinConfig.GPIO_PinNumber = GPIO_PIN_12;
				PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinConfig);
				break;
			case SPI_NSS_HARDWARE_MASTER_Output_EN:
				PinConfig.GPIO_PinNumber = GPIO_PIN_12;
				PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
				MCAL_GPIO_Init(GPIOB, &PinConfig);
				break;

			}

			//==============PB13 : SCK===============
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);


			//==============PB14 : MISO===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);

			//==============PB15 : MOSI===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);

		}
		else if(GL_SPI_Config[1]->Device_MODE == SPI_Device_Mode_SLAVE)
		{
			//==============PB12 : NSS===============
			if (GL_SPI_Config[1]->NSS_Mode == SPI_NSS_HARDWARE_SLAVE)
			{
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
			}

			//==============PB13 : SCK===============
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);


			//==============PB14 : MISO===============
			//Support Only Full Duplex (point to point)
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);

			//==============PB15 : MOSI===============
			//Support Only Full Duplex
			//Todo : Rest of cases
			PinConfig.GPIO_PinNumber = GPIO_PIN_15;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);

		}

	}

}


/**================================================================
 * @Fn			-MCAL_SPI_Send_Data
 * @brief		-Send data
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @param [in] 	-ptrTxDataBuffer : pointer to data to be sent
 * @param [in] 	-PollingEN : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-TODO : Check if receieve only / Transmit only
 */

void MCAL_SPI_Send_Data (SPI_TypeDef *SPIx,uint16_t *ptrTxBuffer ,Polling_Mechanism_t PollingEN )
{
	if(PollingEN == enable)
	{
		while (!(SPIx->SR & (1<<1) ));
	}

	SPIx->DR = *ptrTxBuffer;


}


/**================================================================
 * @Fn			-MCAL_SPI_Recieve_Data
 * @brief		-Receive data
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @param [in] 	-ptrRxDataBuffer : pointer to data to be sent
 * @param [in] 	-PollingEN : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */

void MCAL_SPI_Recieve_Data (SPI_TypeDef *SPIx,uint16_t *ptrRxBuffer ,Polling_Mechanism_t PollingEN )
{
	if(PollingEN == enable)
	{
		while (!(SPIx->SR & (1<<0) ));
	}
	*ptrRxBuffer = SPIx->DR;
}


/**================================================================
 * @Fn			-MCAL_SPI_Send_Recieve
 * @brief		-Send & Receive data at the same time
 * @param [in] 	-SPIx : where x can be (1,2 depending on device used) to select which SPI Instant
 * @param [in] 	-ptrBuffer : pointer to data to be sent
 * @param [in] 	-PollingEN : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */

void MCAL_SPI_Send_Recieve (SPI_TypeDef *SPIx,uint16_t *ptrBuffer ,Polling_Mechanism_t PollingEN )
{
	if(PollingEN == enable)
	{
		while (!(SPIx->SR & (1<<1) ));
	}
	SPIx->DR = *ptrBuffer;

	if(PollingEN == enable)
	{
		while (!(SPIx->SR & (1<<0) ));
	}
	*ptrBuffer = SPIx->DR;
}

void SPI1_IRQHandler(void)
{
	S_IRQ_SRC_t IRQ_SRC;
	IRQ_SRC.TXE = (( SPI1->SR & (1<<1)) >>1);
	IRQ_SRC.RXNE = (( SPI1->SR & (1<<0)) >>0);
	IRQ_SRC.ERROR = (( SPI1->SR & (1<<4)) >>4);

	GL_SPI_Config[0]->Ptr_IRQ_CallBack(IRQ_SRC);
}

void SPI2_IRQHandler(void)
{
	S_IRQ_SRC_t IRQ_SRC;
	IRQ_SRC.TXE = (( SPI2->SR & (1<<1)) >>1);
	IRQ_SRC.RXNE = (( SPI2->SR & (1<<0)) >>0);
	IRQ_SRC.ERROR = (( SPI2->SR & (1<<4)) >>4);

	GL_SPI_Config[1]->Ptr_IRQ_CallBack(IRQ_SRC);
}



