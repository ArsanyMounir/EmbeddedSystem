################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD/keypad.c 

OBJS += \
./HAL/KEYPAD/keypad.o 

C_DEPS += \
./HAL/KEYPAD/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD/keypad.o: ../HAL/KEYPAD/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/EmbeddedSystemKS/Embedded/Drivers/HAL/Inc" -I"D:/EmbeddedSystemKS/Embedded/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

