################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include rza_gen/subdir.mk
-include rza/microsoft/azure-rtos/threadx/common/src/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/common/src/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/web/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/tftp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/telnet/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/sntp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/snmp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/smtp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/pop3/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/nat/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/mqtt/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/http/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/ftp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/dns/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/dhcp/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/cloud/subdir.mk
-include rza/microsoft/azure-rtos/netxduo/addons/auto_ip/subdir.mk
-include rza/fsp/src/rm_threadx_port/subdir.mk
-include rza/fsp/src/rm_netxduo_ether/subdir.mk
-include rza/fsp/src/r_mmu/subdir.mk
-include rza/fsp/src/r_ioport/subdir.mk
-include rza/fsp/src/r_gtm/subdir.mk
-include rza/fsp/src/r_gether_phy/targets/KSZ9131RNXI/subdir.mk
-include rza/fsp/src/r_gether_phy/subdir.mk
-include rza/fsp/src/r_gether/subdir.mk
-include rza/fsp/src/bsp/mcu/rza3ul/subdir.mk
-include rza/fsp/src/bsp/mcu/all/subdir.mk
-include rza/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include rza/board/rza3ul_smarc_qspi_xip/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
tcp_mpu_test.srec \

SECONDARY_SIZE += \
tcp_mpu_test.siz \


# All Target
all: tcp_mpu_test.elf secondary-outputs

# Tool invocations
tcp_mpu_test.elf: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(LINKER_SCRIPT)
	$(file > tcp_mpu_test.elf.in,-mcpu=generic+simd -mcmodel=small -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -o "tcp_mpu_test.elf" $(OBJS) $(USER_OBJS) -T "rza3ul_smarc_qspi_xip.ld" -L"C:\\Users\\erik\\e2_studio\\workspace\\tcp_mpu_test/script" -Wl,--start-group  -Wl,--end-group -nostartfiles -Xlinker --gc-sections -Wl,-Map,"tcp_mpu_test.map")
	@echo Building target: $@ && aarch64-none-elf-gcc @"tcp_mpu_test.elf.in"
tcp_mpu_test.srec: tcp_mpu_test.elf
	aarch64-none-elf-objcopy -O srec "tcp_mpu_test.elf"  "tcp_mpu_test.srec"
tcp_mpu_test.siz: tcp_mpu_test.elf
	aarch64-none-elf-size --format=berkeley "tcp_mpu_test.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(LST)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(SRC_DEPS)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(SX_DEPS)  $(ASM_UPPER_DEPS)  $(SX_UPPER_DEPS)  $(OBJS)  $(SECONDARY_FLASH)  $(ASM_DEPS)  $(S_UPPER_DEPS)  $(MAP) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  tcp_mpu_test.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets
