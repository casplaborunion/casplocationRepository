################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/application/instance.c \
../src/application/instance_calib.c \
../src/application/instance_common.c \
../src/application/instance_fast2wr_a.c \
../src/application/instance_fast2wr_c.c \
../src/application/instance_fast2wr_t.c \
../src/application/main.c 

OBJS += \
./src/application/instance.o \
./src/application/instance_calib.o \
./src/application/instance_common.o \
./src/application/instance_fast2wr_a.o \
./src/application/instance_fast2wr_c.o \
./src/application/instance_fast2wr_t.o \
./src/application/main.o 

C_DEPS += \
./src/application/instance.d \
./src/application/instance_calib.d \
./src/application/instance_common.d \
./src/application/instance_fast2wr_a.d \
./src/application/instance_fast2wr_c.d \
./src/application/instance_fast2wr_t.d \
./src/application/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/application/%.o: ../src/application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_CL -DUSE_STDPERIPH_DRIVER -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_OTG_Driver\inc" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\application" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\decadriver" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\usb" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\platform" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\sys" -I"C:\SPB_Data\git\casplocationRepository\DecaRangingOriginal\src\compiler" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\audio\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\cdc\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\dfu\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\hid\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Class\msc\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32_USB_Device_Library\Core\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32F10x_StdPeriph_Driver\inc" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\STM32F10x_StdPeriph_Driver\src" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\CMSIS\CM3\CoreSupport" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\usb" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\application" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\compiler" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\decadriver" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\platform" -I"C:\Users\shjeong\git\casplocationRepository\DecaRangingOriginal\src\sys" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


