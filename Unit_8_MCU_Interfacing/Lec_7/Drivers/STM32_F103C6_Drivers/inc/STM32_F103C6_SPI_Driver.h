/*
 * STM32_F103C6_SPI_Driver.h
 *
 *  Created on: May 8, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32_F103C6_SPI_DRIVER_H_
#define INC_STM32_F103C6_SPI_DRIVER_H_


//========================================================
//						INCLUDES
//========================================================


#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_USART_Driver.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//				Interrupt Source Structure
//========================================================
typedef struct
{
	uint8_t TXE:1;		//Tx Buffer Empty Interrupt
	uint8_t RXNE:1;		//Rx Buffer not Empty Interrupt
	uint8_t ERROR:1;	//Error Interrupt
	uint8_t Reserved:5;	//Reserved


}S_IRQ_SRC_t;



//========================================================
//				Configuration Structure
//========================================================


typedef struct
{
	uint16_t Device_MODE ; 		//Specifies SPI Operation Mode (Master/Slave)
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref Device_Mode_Define

	uint16_t SPI_MODE ;			//Specifies the SPI communication Mode
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref SPI_Mode_Define

	uint16_t Frame_Format ;  	//Specifies Start with LSB or MSB
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref Frame_Format_Define


	uint16_t Data_Size;			//Specifies Sent/Received Data size
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref Data_Size_Define

	uint16_t Clock_Polarity;	//Specifies Polarity Of Clock
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref Clock_Polarity_Define

	uint16_t Clock_Phase;		//Specifies Phase Of Clock
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref Clock_Phase_Define

	uint16_t NSS_Mode;			//Specifies NSS Mode ( Hardware / Software )
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref NSS_Mode_Define

	uint16_t BaudRate_PreScaler;//Specifies The value of Baud Rate Prescaler
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref BaudRate_PreScaler_Define

	uint16_t IRQ_Enable;		//Enables Or Disable SPI IRQ Tx/Rx
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref SPI_IRQ_Define

	void (* Ptr_IRQ_CallBack)(S_IRQ_SRC_t IRQ_SRC); //Set C function to be called once IRQ Happens


}SPI_Config_t;



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Macros Configuration References
//========================================================

//@ref Device_Mode_Define


//Bit 2 MSTR: Master selection
//0: Slave configuration
//1: Master configuration


#define SPI_Device_Mode_SLAVE							(uint16_t)(0)
#define SPI_Device_Mode_MASTER							(uint16_t)(1<<2)



//------------------------------------------

//@ref SPI_Mode_Define

//Bit 15 BIDIMODE: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected

//Bit 14 BIDIOE: Output enable in bidirectional mode
//This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
//0: Output disabled (receive-only mode)
//1: Output enabled (transmit-only mode)

//Bit 10 RXONLY: Receive only
//This bit combined with the BIDImode bit selects the direction of transfer in 2-line
//unidirectional mode. This bit is also useful in a multislave system in which this particular
//slave is not accessed, the output from the accessed slave is not corrupted.
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive-only mode)

#define SPI_Mode_2Lines										(uint16_t)(0)
#define SPI_Mode_2Lines_RX_Only								(uint16_t)(1<<10)
#define SPI_Mode_1Line_RX_Only								(uint16_t)(1<<15)
#define SPI_Mode_1Line_TX_Only								(uint16_t)(1<<15) | (uint16_t)(1<<14)


//------------------------------------------
//@ref Frame_Format_Define


//Bit 7 LSBFIRST: Frame format
//0: MSB transmitted first
//1: LSB transmitted first

#define SPI_Frame_MSB_First									(uint16_t)(0)
#define SPI_Frame_LSB_First									(uint16_t)(1<<7)


//------------------------------------------
//@ref Data_Size_Define


//Bit 11 DFF: Data frame format
//0: 8-bit data frame format is selected for transmission/reception
//1: 16-bit data frame format is selected for transmission/reception

#define SPI_DataSize_8BIT									(uint16_t)(0)
#define SPI_DataSize_16BIT									(uint16_t)(1<<11)


//------------------------------------------
//@ref Clock_Polarity_Define

//Bit1 CPOL: Clock polarity
//0: CK to 0 when idle
//1: CK to 1 when idle

#define SPI_Clock_Polarity_LOW_IDLE							(uint16_t)(0)
#define SPI_Clock_Polarity_HIGH_IDLE						(uint16_t)(1<<1)




//------------------------------------------
//@ref Clock_Phase_Define

//Bit 0 CPHA: Clock phase
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge

#define SPI_Clock_Phase_1st_EDGE_Data_Capture				(uint16_t)(0)
#define SPI_Clock_Phase_2nd_EDGE_Data_Capture				(uint16_t)(1<<0)



//------------------------------------------
//@ref NSS_Mode_Define



//Bit 9 SSM: Software slave management
//When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
//0: Software slave management disabled
//1: Software slave management enabled

//Bit 8 SSI: Internal slave select
//This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
//NSS pin and the IO value of the NSS pin is ignored


//============IN CR2
//Bit 2 SSOE: SS output enable
//0: SS output is disabled in master mode and the cell can work in multimaster configuration
//1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
//in a multimaster environment

#define SPI_NSS_HARDWARE_SLAVE								(uint16_t)(0)
#define SPI_NSS_HARDWARE_MASTER_Output_EN					(uint16_t)(1<<2) //CR2
#define SPI_NSS_HARDWARE_MASTER_Output_DIS					~(uint16_t)(1<<2) //CR2

#define SPI_NSS_SOFTWARE_SET_BIT							(uint16_t)(1<<9)|(uint16_t)(1<<8)
#define SPI_NSS_SOFTWARE_RESET_BIT							(uint16_t)(1<<9)

//------------------------------------------
//@ref BaudRate_PreScaler_Define

//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256

#define SPI_BaudRate_Prescaler_2							(uint16_t)(0b000<<3)
#define SPI_BaudRate_Prescaler_4							(uint16_t)(0b001<<3)
#define SPI_BaudRate_Prescaler_8							(uint16_t)(0b010<<3)
#define SPI_BaudRate_Prescaler_16							(uint16_t)(0b011<<3)
#define SPI_BaudRate_Prescaler_32							(uint16_t)(0b100<<3)
#define SPI_BaudRate_Prescaler_64							(uint16_t)(0b101<<3)
#define SPI_BaudRate_Prescaler_128							(uint16_t)(0b110<<3)
#define SPI_BaudRate_Prescaler_256							(uint16_t)(0b111<<3)




//------------------------------------------
//@ref SPI_IRQ_Define

//In SPI_CR2 Register
//Bit 7 TXEIE: Tx buffer empty interrupt enable
//0: TXE interrupt masked
//1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
//Bit 6 RXNEIE: RX buffer not empty interrupt enable
//0: RXNE interrupt masked
//1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is
//set.
//Bit 5 ERRIE: Error interrupt enable
//This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
//OVR, MODF in SPI mode and UDR, OVR in I2S mode).
//0: Error interrupt is masked
//1: Error interrupt is enabled


#define SPI_IRQ_Enable_NONE									(uint16_t)(0)
#define SPI_IRQ_Enable_TXEIE								(uint16_t)(1<<7)
#define SPI_IRQ_Enable_RXNEIE								(uint16_t)(1<<6)
#define SPI_IRQ_Enable_ERRIE								(uint16_t)(1<<5)


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "MCAL SPI DRIVER"
//========================================================

void MCAL_SPI_Init (SPI_TypeDef *SPIx,SPI_Config_t *SPI_Config);

void MCAL_SPI_Reset (SPI_TypeDef *SPIx);

void MCAL_SPI_GPIO_Set_Pins (SPI_TypeDef *SPIx);

void MCAL_SPI_Send_Data (SPI_TypeDef *SPIx,uint16_t *ptrTxBuffer ,Polling_Mechanism_t PollingEN );

void MCAL_SPI_Recieve_Data (SPI_TypeDef *SPIx,uint16_t *ptrRxBuffer ,Polling_Mechanism_t PollingEN );

void MCAL_SPI_Send_Recieve (SPI_TypeDef *SPIx,uint16_t *ptrBuffer ,Polling_Mechanism_t PollingEN );






#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */
