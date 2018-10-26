################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO/src/GPIO.c 

OBJS += \
./src/GPIO/src/GPIO.o 

C_DEPS += \
./src/GPIO/src/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
src/GPIO/src/%.o: ../src/GPIO/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"E:\Temp\InfoII_Temp\GPIO\src\GPIO\api" -I"E:\Temp\InfoII_Temp\GPIO\src\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


