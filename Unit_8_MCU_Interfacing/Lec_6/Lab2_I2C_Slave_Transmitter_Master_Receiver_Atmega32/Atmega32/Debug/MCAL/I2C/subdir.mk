################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/I2C/I2C.c 

OBJS += \
./MCAL/I2C/I2C.o 

C_DEPS += \
./MCAL/I2C/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/I2C/%.o: ../MCAL/I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\MCAL\Inc" -I"D:\EmbeddedSystemKS\C_Programming\Atmega32\HAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


