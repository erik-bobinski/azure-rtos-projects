################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_client.c \
../rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_server.c 

LST += \
nxd_telnet_client.lst \
nxd_telnet_server.lst 

C_DEPS += \
./rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_client.d \
./rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_server.d 

OBJS += \
./rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_client.o \
./rza/microsoft/azure-rtos/netxduo/addons/telnet/nxd_telnet_server.o 

MAP += \
netx_demo_http_server_rza3_fsp.map 


# Each subdirectory must supply rules for building sources it contributes
rza/microsoft/azure-rtos/netxduo/addons/telnet/%.o: ../rza/microsoft/azure-rtos/netxduo/addons/telnet/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -gdwarf-4 -D_RZA_CORE=CA55_0 -D_RENESAS_RZA_ -D_RZA_ORDINAL=1 -I"C:/Users/ebob/e2_studio/workspace/netx_demo_http_server_rza3_fsp/generate" -I"C:/Users/ebob/e2_studio/workspace/netx_demo_http_server_rza3_fsp/src" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\src" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\inc" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\inc\\api" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\inc\\instances" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\src\\rm_threadx_port" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\threadx\\common\\inc" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\src\\bsp\\mcu\\rza3ul" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_gen" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg\\bsp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg\\azure\\tx" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg\\middleware" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\pop3" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\snmp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\nat" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\mqtt" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\ftp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\tftp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\sntp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\smtp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\web" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\auto_ip" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\telnet" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dns" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\dhcp" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\http" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\common\\inc" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\netxduo\\addons\\cloud" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\src\\rm_netxduo_ether" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg\\azure\\nxd" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\fsp\\inc\\ports" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza\\microsoft\\azure-rtos\\filex\\common\\inc" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\fsp_cfg\\azure\\fx" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\rza_gen" -I"C:\\Users\\ebob\\e2_studio\\workspace\\netx_demo_http_server_rza3_fsp\\rza_cfg\\driver" -I"." -std=c99 -w -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"

