################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_icu/r_icu.c 

C_DEPS += \
./ra/fsp/src/r_icu/r_icu.d 

OBJS += \
./ra/fsp/src/r_icu/r_icu.o 

SREC += \
threadx_example.srec 

MAP += \
threadx_example.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_icu/%.o: ../ra/fsp/src/r_icu/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -Oz -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM23 -D_RA_ORDINAL=1 -I"/Users/erik/e2_studio/workspace/threadx_example/src" -I"." -I"/Users/erik/e2_studio/workspace/threadx_example/ra/fsp/inc" -I"/Users/erik/e2_studio/workspace/threadx_example/ra/fsp/inc/api" -I"/Users/erik/e2_studio/workspace/threadx_example/ra/fsp/inc/instances" -I"/Users/erik/e2_studio/workspace/threadx_example/ra/fsp/src/rm_threadx_port" -I"/Users/erik/e2_studio/workspace/threadx_example/ra/microsoft/azure-rtos/threadx/common/inc" -I"/Users/erik/e2_studio/workspace/threadx_example/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"/Users/erik/e2_studio/workspace/threadx_example/ra_gen" -I"/Users/erik/e2_studio/workspace/threadx_example/ra_cfg/fsp_cfg/bsp" -I"/Users/erik/e2_studio/workspace/threadx_example/ra_cfg/fsp_cfg" -I"/Users/erik/e2_studio/workspace/threadx_example/ra_cfg/fsp_cfg/azure/tx" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

