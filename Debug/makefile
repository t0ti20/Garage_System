################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Khaled_El-Sayed/COTS/02-HAL/Stepper_Motor/subdir.mk
-include Khaled_El-Sayed/COTS/02-HAL/Seven_Segment/subdir.mk
-include Khaled_El-Sayed/COTS/02-HAL/LCD/subdir.mk
-include Khaled_El-Sayed/COTS/02-HAL/Keypad/subdir.mk
-include Khaled_El-Sayed/COTS/02-HAL/DC_Motor/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/Timer/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/TWI/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/SPI/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/GIE/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/External_Interrupt/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/DIO/subdir.mk
-include Khaled_El-Sayed/COTS/01-MCAL/ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Project.lss \

FLASH_IMAGE += \
Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Project.elf secondary-outputs

# Tool invocations
Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project.map -mmcu=atmega16 -o "Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Project.lss: Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project.elf  >"Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

Project.hex: Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Project.elf  "Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
