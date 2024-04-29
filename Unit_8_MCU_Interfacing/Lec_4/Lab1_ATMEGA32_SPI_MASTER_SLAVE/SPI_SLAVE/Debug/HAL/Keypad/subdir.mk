################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/KEYPAD.c 

OBJS += \
./HAL/Keypad/KEYPAD.o 

C_DEPS += \
./HAL/Keypad/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/%.o: ../HAL/Keypad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\EmbeddedSystemKS\C_Programming\SPI_SLAVE\HAL\Inc" -I"D:\EmbeddedSystemKS\C_Programming\SPI_SLAVE\APP" -I"D:\EmbeddedSystemKS\C_Programming\SPI_SLAVE\MCAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


