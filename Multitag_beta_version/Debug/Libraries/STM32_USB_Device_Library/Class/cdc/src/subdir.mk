################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_core.c \
../Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_if_template.c 

OBJS += \
./Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_core.o \
./Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_if_template.o 

C_DEPS += \
./Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_core.d \
./Libraries/STM32_USB_Device_Library/Class/cdc/src/usbd_cdc_if_template.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STM32_USB_Device_Library/Class/cdc/src/%.o: ../Libraries/STM32_USB_Device_Library/Class/cdc/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_CL -DUSE_STDPERIPH_DRIVER -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_OTG_Driver\inc" -I"C:\Users\Slave\Desktop\������Ʈ\MNsoft\Deca\test\RemoteSystemsTempFiles" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\audio\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\cdc\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\dfu\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\hid\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\msc\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Core\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32F10x_StdPeriph_Driver\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32F10x_StdPeriph_Driver\src" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\CMSIS\CM3\CoreSupport" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\usb" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\application" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\compiler" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\decadriver" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\platform" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\sys" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

