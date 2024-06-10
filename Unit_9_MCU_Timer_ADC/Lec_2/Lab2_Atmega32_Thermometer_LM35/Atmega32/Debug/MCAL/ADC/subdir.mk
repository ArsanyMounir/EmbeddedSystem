################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC/ADC.c 

OBJS += \
./MCAL/ADC/ADC.o 

C_DEPS += \
./MCAL/ADC/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ADC/%.o: ../MCAL/ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\MCAL\Inc" -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\HAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


