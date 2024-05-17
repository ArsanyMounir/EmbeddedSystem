################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM/EEPROM.c 

OBJS += \
./HAL/EEPROM/EEPROM.o 

C_DEPS += \
./HAL/EEPROM/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM/EEPROM.o: ../HAL/EEPROM/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/EmbeddedSystemKS/Embedded/Drivers/HAL/Inc" -I"D:/EmbeddedSystemKS/Embedded/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/EEPROM/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

