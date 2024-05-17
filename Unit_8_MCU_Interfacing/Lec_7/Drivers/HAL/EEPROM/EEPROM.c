/*
 * EEPROM.c
 *
 *  Created on: May 17, 2024
 *      Author: Arsany
 */

#include "EEPROM.h"




void HAL_EEPROM_Init(void)
{
	//I2C1
	//PB6 : SCL
	//PB7 : SDA

	I2C_Config_t I2C_Config;

	I2C_Config.General_Call = I2C_General_Call_Enabled;
	I2C_Config.ACK_Control = I2C_ACK_Enable;
	I2C_Config.I2C_ClockSpeed = I2C_SCLK_SM_100KHz;
	I2C_Config.I2C_Mode = I2C_Mode_I2C;
	I2C_Config.Ptr_Slave_EV_IRQ_CallBack = NULL;
	I2C_Config.Stretch_Mode = I2C_Stretch_Mode_Enable;

	MCAL_I2C_GPIO_Set_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &I2C_Config);




}


uint8_t HAL_EEPROM_Write_NBytes (uint32_t Memory_Address , uint8_t* Bytes , uint8_t Data_Length)
{
	uint8_t i;
	uint8_t Buffer[265];
	Buffer[0]= (uint8_t)(Memory_Address>>8);	//Upper Bytes Memory Address
	Buffer[1]= (uint8_t)(Memory_Address);		//Lower Bytes Memory Address

	for(i=2;i<(Data_Length+2);i++)
	{
		Buffer[i]= Bytes[i-2];
	}

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_SLAVE_ADDRESS, Buffer, (Data_Length+2), withSTOP, No_Repeated_Start);

	return 0;
}
uint8_t HAL_EEPROM_Read_NBytes (uint32_t Memory_Address , uint8_t* Bytes , uint8_t Data_Length)
{
	uint8_t Buffer[2];
	Buffer[0]= (uint8_t)(Memory_Address>>8);	//Upper Bytes Memory Address
	Buffer[1]= (uint8_t)(Memory_Address);		//Lower Bytes Memory Address

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_SLAVE_ADDRESS, Buffer, 2, withoutSTOP, No_Repeated_Start); //Write Address

	MCAL_I2C_MASTER_RX(I2C1, EEPROM_SLAVE_ADDRESS, Bytes, Data_Length, withSTOP, Repeated_Start);	//Read Data

	return 0;
}

