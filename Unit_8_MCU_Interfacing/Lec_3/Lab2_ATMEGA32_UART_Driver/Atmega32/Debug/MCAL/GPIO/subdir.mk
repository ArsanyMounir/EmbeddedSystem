################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/ATMEGA32_GPIO_Driver.c 

OBJS += \
./MCAL/GPIO/ATMEGA32_GPIO_Driver.o 

C_DEPS += \
./MCAL/GPIO/ATMEGA32_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/%.o: ../MCAL/GPIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\MCAL\Inc" -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\HAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


