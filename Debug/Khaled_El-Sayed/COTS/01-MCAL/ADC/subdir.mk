################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Khaled_El-Sayed/COTS/01-MCAL/ADC/ADC_Program.c 

OBJS += \
./Khaled_El-Sayed/COTS/01-MCAL/ADC/ADC_Program.o 

C_DEPS += \
./Khaled_El-Sayed/COTS/01-MCAL/ADC/ADC_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Khaled_El-Sayed/COTS/01-MCAL/ADC/%.o: ../Khaled_El-Sayed/COTS/01-MCAL/ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


