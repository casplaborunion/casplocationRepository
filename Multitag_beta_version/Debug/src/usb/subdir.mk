################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/usb/usb.c \
../src/usb/usb_bsp_evk.c \
../src/usb/usbd_cdc_vcp.c \
../src/usb/usbd_desc.c \
../src/usb/usbd_usr.c 

OBJS += \
./src/usb/usb.o \
./src/usb/usb_bsp_evk.o \
./src/usb/usbd_cdc_vcp.o \
./src/usb/usbd_desc.o \
./src/usb/usbd_usr.o 

C_DEPS += \
./src/usb/usb.d \
./src/usb/usb_bsp_evk.d \
./src/usb/usbd_cdc_vcp.d \
./src/usb/usbd_desc.d \
./src/usb/usbd_usr.d 


# Each subdirectory must supply rules for building sources it contributes
src/usb/%.o: ../src/usb/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_CL -DUSE_STDPERIPH_DRIVER -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_OTG_Driver\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\application" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\audio\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\cdc\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\dfu\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\hid\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Class\msc\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32_USB_Device_Library\Core\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32F10x_StdPeriph_Driver\inc" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\STM32F10x_StdPeriph_Driver\src" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\CMSIS\CM3\CoreSupport" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\usb" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\application" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\compiler" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\decadriver" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\platform" -I"C:\SPB_Data\git\casplocationRepository\Multitag_beta_version\src\sys" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

