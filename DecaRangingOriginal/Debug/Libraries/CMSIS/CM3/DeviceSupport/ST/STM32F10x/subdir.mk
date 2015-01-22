################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c 

OBJS += \
./Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.o 

C_DEPS += \
./Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/%.o: ../Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_CL -DUSE_STDPERIPH_DRIVER -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_OTG_Driver\inc" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\application" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\decadriver" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\usb" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\platform" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\sys" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\compiler" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\audio\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\cdc\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\dfu\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\hid\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\msc\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Core\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32F10x_StdPeriph_Driver\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32F10x_StdPeriph_Driver\src" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\CMSIS\CM3\CoreSupport" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\usb" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\application" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\compiler" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\decadriver" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\platform" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\sys" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


