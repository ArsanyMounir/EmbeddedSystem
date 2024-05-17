/*
 * STM32_F103C6_USART_Driver.h
 *
 *  Created on: Apr 23, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_
//========================================================
//						INCLUDES
//========================================================


#include "STM32F103X6.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				Configuration Structure
//========================================================

typedef struct
{
	uint8_t USART_MODE ; 		//Specifies the Tx/Rx Enable / Disable
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

	uint8_t FlowCtrl;			//Specifies Hw Flow Control mode
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref USART_Flow_Control_Define

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

#define  UART_MODE_RX 								(uint32_t)(1<<2) //Bit 2 RE : Receiver enable
#define  UART_MODE_TX 								(uint32_t)(1<<3) //Bit 3 TE : Transmitter enable
#define  UART_MODE_TX_RX							(uint32_t)(1<<3 | 1<<2)

//------------------------------------------
//@ref USART_BaudRate_Define

#define  UART_BaudRate_2400 						2400
#define  UART_BaudRate_9600 						9600
#define  UART_BaudRate_19200 						19200
#define  UART_BaudRate_57600 						57600
#define  UART_BaudRate_115200 						115200
#define  UART_BaudRate_230400 						230400
#define  UART_BaudRate_460800 						460800
#define  UART_BaudRate_921600 						921600
#define  UART_BaudRate_2250000 						2250000
#define  UART_BaudRate_4500000 						4500000



//------------------------------------------
//@ref USART_Data_Legth_Define

#define  USART_DATA_LEGNTH_8BIT						(uint32_t)(0)
#define  USART_DATA_LEGNTH_9BIT						(uint32_t)(1<<12)



//------------------------------------------
//@ref USART_Parity_Define
#define USART_PARITY_NONE							(uint32_t)(0)
#define USART_PARITY_EVEN							(uint32_t)(1<<10)
#define USART_PARITY_ODD							(uint32_t)(1<<10 | 1<<9)



//------------------------------------------
//@ref USART_Stop_Bits_Define
#define USART_StopBits_HALF							(uint32_t)(1<<12)
#define USART_StopBits_1							(uint32_t)(0)
#define USART_StopBits_1_HALF						(uint32_t)(3<<12)
#define USART_StopBits_2							(uint32_t)(2<<12)

//------------------------------------------
//@ref USART_Flow_Control_Define
#define USART_FlowCtrl_NONE							(uint32_t)(0)
#define USART_FlowCtrl_RTS							(uint32_t)(1<<8)
#define USART_FlowCtrl_CTS							(uint32_t)(1<<9)
#define USART_FlowCtrl_RTS_CTS						(uint32_t)(1<<8|1<<9)


//------------------------------------------
//@ref USART_USART_IRQ_Define
#define USART_IRQ_EN_NONE							(uint32_t)(0)		//No IRQ Enabled
#define USART_IRQ_EN_TXE							(uint32_t)(1<<7) 	//Transmit data register empty
#define USART_IRQ_EN_TC								(uint32_t)(1<<6)	//Transmission Complete
#define USART_IRQ_EN_RXNEIE							(uint32_t)(1<<5)	//Received data ready to be read
#define USART_IRQ_EN_PE								(uint32_t)(1<<8)	//Parity Error


//-------------------------------------------
typedef enum
{
	enable,
	disable
}Polling_Mechanism_t;

//--------------------------------------------
//BaudRate Calc
//USARTDIV = Fclk / (16* BaudRate)
//USARTDIV_MUL100 = 100*Fclk / (16* BaudRate) == (25*Fclk)/(4*BaudRate)
//Mantissa = integar part of USARTDIV
//Mantissa_MUL100 = integar part of USARTDIV * 100
//DIV_Fraction = (( USARTDIV_MUL100 - Mantissa_MUL100 ) *16 ) / 100




#define USARTDIV(_PCLK_,_BAUD_)						(uint32_t)(_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)				(uint32_t)((_PCLK_*25)/(4*_BAUD_))
#define Mantissa(_PCLK_,_BAUD_)						(uint32_t)(USARTDIV(_PCLK_,_BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)				(uint32_t)(USARTDIV(_PCLK_,_BAUD_)*100)
#define DIV_Fraction(_PCLK_,_BAUD_)					(uint32_t)(((USARTDIV_MUL100(_PCLK_,_BAUD_)-Mantissa_MUL100(_PCLK_,_BAUD_))*16)/100)
#define UART_BRR_Reg(_PCLK_,_BAUD_)					((Mantissa(_PCLK_,_BAUD_))<<4)|((DIV_Fraction(_PCLK_,_BAUD_))&0xF)


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------





//========================================================
//			APIs Supported by "MCAL USART DRIVER"
//========================================================

/**================================================================
 * @Fn			-MCAL_UART_Init
 * @brief		-Initializes the USARTx  according to the specified parameters of UART_Config
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in]	-UART_Config : Pointer to USART_Config_t which contains the configuration info for specified UART
 * @retval 		-None
 * Note 		-Supports Asynch mode only , 8Mhz clk
 */
void MCAL_UART_Init(USART_TypeDef *USARTx, USART_Config_t* UART_Config );


/**================================================================
 * @Fn			-MCAL_UART_Reset
 * @brief		-Resets the USARTx Registers
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-Supports Asynch mode only , 8Mhz clk
 */
void MCAL_UART_Reset(USART_TypeDef *USARTx );

/**================================================================
 * @Fn			-MCAL_UART_GPIO_Set_Pins
 * @brief		-Configure GPIO Pins to work as USART
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef *USARTx );


/**================================================================
 * @Fn			-MCAL_UART_SendData
 * @brief		-Send data through Tx
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in] 	-TxDataBuffer : pointer to data to be sent
 * @param [in] 	-Polling_Mechanism : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_SendData(USART_TypeDef *USARTx,uint16_t * TxDataBuffer, Polling_Mechanism_t PollingEN);

/**================================================================
 * @Fn			-MCAL_UART_ReceiveData
 * @brief		-Receive data through Rx
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @param [in] 	-RxDataBuffer : pointer to data to be sent
 * @param [in] 	-Polling_Mechanism : Choose polling mechanism whether enabled or disabled
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_ReceiveData(USART_TypeDef *USARTx,uint16_t * RxDataBuffer, Polling_Mechanism_t PollingEN);


/**================================================================
 * @Fn			-MCAL_UART_WAIT_TC
 * @brief		-Checks whether data transmit finished or not
 * @param [in] 	-USARTx : where x can be (1,2,3 depending on device used) to select which UART Instant
 * @retval 		-None
 * Note 		-None
 */
void MCAL_UART_WAIT_TC(USART_TypeDef *USARTx);


//TODO
//MCAL_USART_Init();
//MCAL_USART_LIN_Init();
//MCAL_USART_DMA_Init();



#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
