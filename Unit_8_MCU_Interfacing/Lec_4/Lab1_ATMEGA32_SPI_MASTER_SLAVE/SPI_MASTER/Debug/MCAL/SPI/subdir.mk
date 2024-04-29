################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI/SPI.c 

OBJS += \
./MCAL/SPI/SPI.o 

C_DEPS += \
./MCAL/SPI/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI/%.o: ../MCAL/SPI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\EmbeddedSystemKS\C_Programming\SPI_MASTER\MCAL\Inc" -I"D:\EmbeddedSystemKS\C_Programming\SPI_MASTER\HAL\Inc" -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


