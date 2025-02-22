################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../rza/fsp/src/bsp/mcu/all/bsp_delay_asm.asm 

C_SRCS += \
../rza/fsp/src/bsp/mcu/all/bsp_clocks.c \
../rza/fsp/src/bsp/mcu/all/bsp_common.c \
../rza/fsp/src/bsp/mcu/all/bsp_delay.c \
../rza/fsp/src/bsp/mcu/all/bsp_gicv3.c \
../rza/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../rza/fsp/src/bsp/mcu/all/bsp_guard.c \
../rza/fsp/src/bsp/mcu/all/bsp_io.c \
../rza/fsp/src/bsp/mcu/all/bsp_irq.c \
../rza/fsp/src/bsp/mcu/all/bsp_rom_registers.c \
../rza/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../rza/fsp/src/bsp/mcu/all/bsp_security.c 

LST += \
bsp_clocks.lst \
bsp_common.lst \
bsp_delay.lst \
bsp_delay_asm.lst \
bsp_gicv3.lst \
bsp_group_irq.lst \
bsp_guard.lst \
bsp_io.lst \
bsp_irq.lst \
bsp_rom_registers.lst \
bsp_sbrk.lst \
bsp_security.lst 

C_DEPS += \
./rza/fsp/src/bsp/mcu/all/bsp_clocks.d \
./rza/fsp/src/bsp/mcu/all/bsp_common.d \
./rza/fsp/src/bsp/mcu/all/bsp_delay.d \
./rza/fsp/src/bsp/mcu/all/bsp_gicv3.d \
./rza/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./rza/fsp/src/bsp/mcu/all/bsp_guard.d \
./rza/fsp/src/bsp/mcu/all/bsp_io.d \
./rza/fsp/src/bsp/mcu/all/bsp_irq.d \
./rza/fsp/src/bsp/mcu/all/bsp_rom_registers.d \
./rza/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./rza/fsp/src/bsp/mcu/all/bsp_security.d 

OBJS += \
./rza/fsp/src/bsp/mcu/all/bsp_clocks.o \
./rza/fsp/src/bsp/mcu/all/bsp_common.o \
./rza/fsp/src/bsp/mcu/all/bsp_delay.o \
./rza/fsp/src/bsp/mcu/all/bsp_delay_asm.o \
./rza/fsp/src/bsp/mcu/all/bsp_gicv3.o \
./rza/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./rza/fsp/src/bsp/mcu/all/bsp_guard.o \
./rza/fsp/src/bsp/mcu/all/bsp_io.o \
./rza/fsp/src/bsp/mcu/all/bsp_irq.o \
./rza/fsp/src/bsp/mcu/all/bsp_rom_registers.o \
./rza/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./rza/fsp/src/bsp/mcu/all/bsp_security.o 

ASM_DEPS += \
./rza/fsp/src/bsp/mcu/all/bsp_delay_asm.d 

MAP += \
tcp_mpu_test.map 


# Each subdirectory must supply rules for building sources it contributes
rza/fsp/src/bsp/mcu/all/%.o: ../rza/fsp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=generic+simd -mcmodel=small -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\src" -I"." -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\api" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\instances" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_threadx_port" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\threadx\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\bsp\\mcu\\rza3ul" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_gen" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\bsp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\tx" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\pop3" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\snmp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\nat" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\mqtt" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\ftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\tftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\sntp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\smtp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\web" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\auto_ip" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\telnet" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dns" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dhcp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\http" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\cloud" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_netxduo_ether" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\middleware" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\nxd" -std=c99 -Wno-format-truncation -Wno-stringop-overflow --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"
rza/fsp/src/bsp/mcu/all/%.o: ../rza/fsp/src/bsp/mcu/all/%.asm
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=generic+simd -mcmodel=small -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -x assembler-with-cpp -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\src" -I"." -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\api" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\inc\\instances" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_threadx_port" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\threadx\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\bsp\\mcu\\rza3ul" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_gen" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\bsp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\tx" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\pop3" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\snmp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\nat" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\mqtt" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\ftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\tftp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\sntp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\smtp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\web" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\auto_ip" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\telnet" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dns" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dhcp" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\http" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\common\\inc" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\cloud" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza\\fsp\\src\\rm_netxduo_ether" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\middleware" -I"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test\\rza_cfg\\fsp_cfg\\azure\\nxd" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"

