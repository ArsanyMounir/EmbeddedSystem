/*
 * SPI.h
 *
 *  Created on: Apr 29, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_SPI_H_
#define MCAL_INC_SPI_H_

//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32_GPIO_Driver.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//				Configuration Structure
//========================================================

typedef struct{
	volatile uint8_t SPI_MODE;			//Specifies the SPI Mode (MASTER/SLAVE)
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_MODE_DEFINE


	volatile uint8_t SPI_DATA_ORDER;	//Specifies the Data order (LSB/MSB)
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_DATA_ORDER_DEFINE


	volatile uint8_t SPI_CLK_POLARITY;	//Specifies the Clock Idle state (HIGH/LOW)
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_CLK_POLARITY_DEFINE

	volatile uint8_t SPI_CLOCK_PHASE;	//Specifies the Clock phase (Sample/Setup)
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_CLK_PHASE_DEFINE



	volatile uint8_t SPI_SCK_RATE;		//Specifies the Clock Rate Prescaler
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_SCK_RATE_DEFINE




	volatile uint8_t SPI_IRQ_EN;		//Enables Interrupt for SPI
										//This Parameter must be set with value
										//from Macro Configuration Manual @ref SPI_IRQ_DEFINE




}SPI_Config_t;


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//			Macros Configuration References
//========================================================

//@ref SPI_MODE_DEFINE
#define SPI_MASTER 											1
#define SPI_SLAVE 											0

//@ref SPI_DATA_ORDER_DEFINE
#define SPI_DATA_LSB_FIRST									1
#define SPI_DATA_MSB_FIRST 									0

//@ref SPI_CLK_POLARITY_DEFINE
#define SPI_CLK_POLARITY_HIGH								1
#define SPI_CLK_POLARITY_LOW 								0

//@ref SPI_CLK_PHASE_DEFINE
#define SPI_CLK_SAMPLE_PHASE								1
#define SPI_CLK_SETUP_PHASE									0

//@ref SPI_SCK_RATE_DEFINE
#define SPI_SCK_RATE_4										0
#define SPI_SCK_RATE_16										1
#define SPI_SCK_RATE_64										2
#define SPI_SCK_RATE_128									3

#define SPI_SCK_RATE_2										4
#define SPI_SCK_RATE_8										5
#define SPI_SCK_RATE_32										6

//ref SPI_IRQ_DEFINE
#define SPI_IRQ_ENABLE										1
#define SPI_IRQ_DISABLE										0

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//			APIs Supported by "MCAL SPI DRIVER"
//========================================================

void MCAL_SPI_Init(SPI_Config_t * Config);
uint8_t MCAL_SPI_MASTER_SEND(uint8_t data);
uint8_t MCAL_SPI_SLAVE_RECIEVE(void);
uint8_t MCAL_SPI_SEND_RECIEVE(uint8_t data);



#endif /* MCAL_INC_SPI_H_ */
