################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc13xx.c \
../src/crp.c \
../src/debugProject.c \
../src/timer.c 

OBJS += \
./src/cr_startup_lpc13xx.o \
./src/crp.o \
./src/debugProject.o \
./src/timer.o 

C_DEPS += \
./src/cr_startup_lpc13xx.d \
./src/crp.d \
./src/debugProject.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DDONT_ENABLE_SWVTRACECLK -DCORE_M3 -D__LPC13XX__ -D__REDLIB__ -I"C:\Users\Mandrake\Documents\LPCXpresso_7.9.2_493\workspace\debugProject\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


