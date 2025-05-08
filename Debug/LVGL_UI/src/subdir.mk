################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL_UI/src/global_styles.c \
../LVGL_UI/src/home_screen.c \
../LVGL_UI/src/main_screen.c \
../LVGL_UI/src/screen_manager.c \
../LVGL_UI/src/settings.c \
../LVGL_UI/src/status_bar.c 

OBJS += \
./LVGL_UI/src/global_styles.o \
./LVGL_UI/src/home_screen.o \
./LVGL_UI/src/main_screen.o \
./LVGL_UI/src/screen_manager.o \
./LVGL_UI/src/settings.o \
./LVGL_UI/src/status_bar.o 

C_DEPS += \
./LVGL_UI/src/global_styles.d \
./LVGL_UI/src/home_screen.d \
./LVGL_UI/src/main_screen.d \
./LVGL_UI/src/screen_manager.d \
./LVGL_UI/src/settings.d \
./LVGL_UI/src/status_bar.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL_UI/src/%.o LVGL_UI/src/%.su LVGL_UI/src/%.cyclo: ../LVGL_UI/src/%.c LVGL_UI/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3" -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3/CMSIS/core" -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3/HAL_Driver/Inc" -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3/Utilities/STM32746G-Discovery" -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3/CMSIS/device" -I"C:/Users/SolveigKorslien/Projects/stm32-disco-3/stm32-disco-3/LVGL_UI/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL_UI-2f-src

clean-LVGL_UI-2f-src:
	-$(RM) ./LVGL_UI/src/global_styles.cyclo ./LVGL_UI/src/global_styles.d ./LVGL_UI/src/global_styles.o ./LVGL_UI/src/global_styles.su ./LVGL_UI/src/home_screen.cyclo ./LVGL_UI/src/home_screen.d ./LVGL_UI/src/home_screen.o ./LVGL_UI/src/home_screen.su ./LVGL_UI/src/main_screen.cyclo ./LVGL_UI/src/main_screen.d ./LVGL_UI/src/main_screen.o ./LVGL_UI/src/main_screen.su ./LVGL_UI/src/screen_manager.cyclo ./LVGL_UI/src/screen_manager.d ./LVGL_UI/src/screen_manager.o ./LVGL_UI/src/screen_manager.su ./LVGL_UI/src/settings.cyclo ./LVGL_UI/src/settings.d ./LVGL_UI/src/settings.o ./LVGL_UI/src/settings.su ./LVGL_UI/src/status_bar.cyclo ./LVGL_UI/src/status_bar.d ./LVGL_UI/src/status_bar.o ./LVGL_UI/src/status_bar.su

.PHONY: clean-LVGL_UI-2f-src

