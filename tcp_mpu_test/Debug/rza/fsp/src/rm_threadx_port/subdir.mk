################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../rza/fsp/src/rm_threadx_port/tx_initialize_low_level.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_context_restore.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_context_save.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_interrupt_control.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_schedule.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_stack_build.asm \
../rza/fsp/src/rm_threadx_port/tx_thread_system_return.asm \
../rza/fsp/src/rm_threadx_port/tx_timer_interrupt.asm \
../rza/fsp/src/rm_threadx_port/tx_vector_table.asm 

C_SRCS += \
../rza/fsp/src/rm_threadx_port/tx_isr_end.c \
../rza/fsp/src/rm_threadx_port/tx_isr_start.c \
../rza/fsp/src/rm_threadx_port/tx_thread_fp_disable.c \
../rza/fsp/src/rm_threadx_port/tx_thread_fp_enable.c 

LST += \
tx_initialize_low_level.lst \
tx_isr_end.lst \
tx_isr_start.lst \
tx_thread_context_restore.lst \
tx_thread_context_save.lst \
tx_thread_fp_disable.lst \
tx_thread_fp_enable.lst \
tx_thread_interrupt_control.lst \
tx_thread_interrupt_disable.lst \
tx_thread_interrupt_restore.lst \
tx_thread_schedule.lst \
tx_thread_stack_build.lst \
tx_thread_system_return.lst \
tx_timer_interrupt.lst \
tx_vector_table.lst 

C_DEPS += \
./rza/fsp/src/rm_threadx_port/tx_isr_end.d \
./rza/fsp/src/rm_threadx_port/tx_isr_start.d \
./rza/fsp/src/rm_threadx_port/tx_thread_fp_disable.d \
./rza/fsp/src/rm_threadx_port/tx_thread_fp_enable.d 

OBJS += \
./rza/fsp/src/rm_threadx_port/tx_initialize_low_level.o \
./rza/fsp/src/rm_threadx_port/tx_isr_end.o \
./rza/fsp/src/rm_threadx_port/tx_isr_start.o \
./rza/fsp/src/rm_threadx_port/tx_thread_context_restore.o \
./rza/fsp/src/rm_threadx_port/tx_thread_context_save.o \
./rza/fsp/src/rm_threadx_port/tx_thread_fp_disable.o \
./rza/fsp/src/rm_threadx_port/tx_thread_fp_enable.o \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_control.o \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.o \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.o \
./rza/fsp/src/rm_threadx_port/tx_thread_schedule.o \
./rza/fsp/src/rm_threadx_port/tx_thread_stack_build.o \
./rza/fsp/src/rm_threadx_port/tx_thread_system_return.o \
./rza/fsp/src/rm_threadx_port/tx_timer_interrupt.o \
./rza/fsp/src/rm_threadx_port/tx_vector_table.o 

ASM_DEPS += \
./rza/fsp/src/rm_threadx_port/tx_initialize_low_level.d \
./rza/fsp/src/rm_threadx_port/tx_thread_context_restore.d \
./rza/fsp/src/rm_threadx_port/tx_thread_context_save.d \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_control.d \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.d \
./rza/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.d \
./rza/fsp/src/rm_threadx_port/tx_thread_schedule.d \
./rza/fsp/src/rm_threadx_port/tx_thread_stack_build.d \
./rza/fsp/src/rm_threadx_port/tx_thread_system_return.d \
./rza/fsp/src/rm_threadx_port/tx_timer_interrupt.d \
./rza/fsp/src/rm_threadx_port/tx_vector_table.d 

MAP += \
tcp_mpu_test.map 


# Each subdirectory must supply rules for building sources it contributes
rza/fsp/src/rm_threadx_port/%.o: ../rza/fsp/src/rm_threadx_port/%.asm
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=generic+simd -mcmodel=small -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -x assembler-with-cpp -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\src" -I"." -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\api" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\instances" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_threadx_port" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\threadx\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\bsp\\mcu\\rza3ul" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_gen" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\bsp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\tx" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\pop3" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\snmp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\nat" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\mqtt" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\ftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\tftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\sntp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\smtp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\web" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\auto_ip" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\telnet" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dns" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dhcp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\http" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\cloud" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_netxduo_ether" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\middleware" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\nxd" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"
rza/fsp/src/rm_threadx_port/%.o: ../rza/fsp/src/rm_threadx_port/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=generic+simd -mcmodel=small -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\src" -I"." -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\api" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\instances" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_threadx_port" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\threadx\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\bsp\\mcu\\rza3ul" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_gen" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\bsp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\tx" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\pop3" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\snmp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\nat" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\mqtt" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\ftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\tftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\sntp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\smtp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\web" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\auto_ip" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\telnet" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dns" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dhcp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\http" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\cloud" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_netxduo_ether" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\middleware" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\nxd" -std=c99 -Wno-format-truncation -Wno-stringop-overflow --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"

