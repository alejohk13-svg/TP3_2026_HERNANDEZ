################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Teclado/TECLADO.c 

OBJS += \
./Teclado/TECLADO.o 

C_DEPS += \
./Teclado/TECLADO.d 


# Each subdirectory must supply rules for building sources it contributes
Teclado/%.o: ../Teclado/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VETx -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/StdPeriph_Driver/inc" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/inc" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/CMSIS/device" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/CMSIS/core" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/LCD" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/Menu" -I"C:/Users/alejo/OneDrive/Desktop/UTN/Tecnicas Digitales II/Laboratorios/TP3_2026_HERNANDEZ/Teclado" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


