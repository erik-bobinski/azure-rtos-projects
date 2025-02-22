/*
 * Hello my friends, it is I Vincent.
 * This is the code for the TCP Server.
 * This code sets a static IP address.
 * It also sends a singular test message to the client.
 * You may now look at the code.
 * (:
*/

#include <tcp_server_thread.h>
// #include "common_utils.h"


/* Function declarations*/
static void nx_common_init0(void);
static void packet_pool_init0(void);
static void ip_init0(void);
static void tcp_serv_init(void);
ULONG ip_to_ulong(UINT, UINT, UINT, UINT);

#define SERVER_PORT 5000
#define LINK_ENABLE_WAIT_TIME (1000U)

/* Global variables */
TX_EVENT_FLAGS_GROUP my_event_flags_group;

/* IP instance */
NX_IP g_ip0;

/* Stack memory for g_ip0. */
uint8_t g_ip0_stack_memory[G_IP0_TASK_STACK_SIZE] BSP_PLACE_IN_SECTION(".stack.g_ip0") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);

/* ARP cache memory for g_ip0. */
uint8_t g_ip0_arp_cache_memory[G_IP0_ARP_CACHE_SIZE] BSP_ALIGN_VARIABLE(4);

/* Packet pool instance (If this is a Trustzone part, the memory must be placed in Non-secure memory). */
NX_PACKET_POOL g_packet_pool0;
uint8_t g_packet_pool0_pool_memory[G_PACKET_POOL0_PACKET_NUM * (G_PACKET_POOL0_PACKET_SIZE + sizeof(NX_PACKET))] BSP_ALIGN_VARIABLE(4) ETHER_BUFFER_PLACE_IN_SECTION;

NX_TCP_SOCKET server_socket;

/* DHCP Client Thread entry function */
void tcp_server_thread_entry(void)
{
//    UINT               status  = NX_SUCCESS;

    /* Initialize the RTT Thread.*/
    // rtt_thread_init_check();
    /* print the banner and EP info. */
    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_BANNER, RESET_VALUE, NULL);

    /* Initialize the NetX system.*/
    nx_common_init0();

    /* Initialize the packet pool.*/
    packet_pool_init0();

    /* create the ip instance.*/
    ip_init0();

    // Set the static IP address and network mask
    ULONG ip_address = ip_to_ulong(192, 168, 8, 173);        // 192.168.8.141
    ULONG network_mask = ip_to_ulong(255, 255, 255, 0);       // 255.255.255.0
    nx_ip_address_set(&g_ip0, ip_address, network_mask);

    tcp_serv_init();

    while (true)
    {
        tx_thread_sleep (1);
    }
}

/*******************************************************************************************************************//**
 * @brief     Initialization of NetX system.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void nx_common_init0(void)
{
    /* Initialize the NetX system. */
    nx_system_initialize ();
}

/*******************************************************************************************************************//**
 * @brief     Create the packet pool.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void packet_pool_init0(void)
{
    /* Create the packet pool. */
    UINT status = nx_packet_pool_create(&g_packet_pool0,
                                        "g_packet_pool0 Packet Pool",
                                        G_PACKET_POOL0_PACKET_SIZE,
                                        &g_packet_pool0_pool_memory[0],
                                        G_PACKET_POOL0_PACKET_NUM * (G_PACKET_POOL0_PACKET_SIZE + sizeof(NX_PACKET)));
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_packet_pool_create failed."), "nx_packet_pool_create failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }
}

/*******************************************************************************************************************//**
 * @brief     Create the ip instance and enables ARP,UDP,ICMP.
 * @param[IN] None
 * @retval    None
 **********************************************************************************************************************/
static void ip_init0(void)
{
    UINT status = NX_SUCCESS;

    /* Create the ip instance. */
    status = nx_ip_create(&g_ip0,
                          "g_ip0 IP Instance",
                          G_IP0_ADDRESS,
                          G_IP0_SUBNET_MASK,
                          &g_packet_pool0,
                          g_netxduo_ether_0,
                          &g_ip0_stack_memory[0],
                          G_IP0_TASK_STACK_SIZE,
                          G_IP0_TASK_PRIORITY);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_ip_create failed."), "nx_ip_create failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Set the gateway address if it is configured. */
//    if (IP_ADDRESS(0, 0, 0, 0) != G_IP0_GATEWAY_ADDRESS)
//    {
//        status = nx_ip_gateway_address_set(&g_ip0, G_IP0_GATEWAY_ADDRESS);
//        if(NX_SUCCESS != status)
//        {
//            app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_ip_gateway_address_set failed."), "nx_ip_gateway_address_set failed.");
//            app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
//        }
//    }

    /* Enables Address Resolution Protocol (ARP).*/
    status = nx_arp_enable(&g_ip0, &g_ip0_arp_cache_memory[0], G_IP0_ARP_CACHE_SIZE);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_arp_enable failed."), "nx_arp_enable failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Enable udp.*/
//    status = nx_udp_enable(&g_ip0);
//    if(NX_SUCCESS != status)
//    {
//        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_udp_enable failed."), "nx_udp_enable failed.");
//        app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
//    }

    // Enable TCP
    status = nx_tcp_enable(&g_ip0);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_enable failed."), "nx_tcp_enable failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Enable icmp.*/
    status = nx_icmp_enable(&g_ip0);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_icmp_enable failed."), "nx_icmp_enable failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    /* Wait for the link to be enabled. */
    ULONG current_state;
    status = nx_ip_status_check(&g_ip0, NX_IP_LINK_ENABLED, &current_state, LINK_ENABLE_WAIT_TIME);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_ip_status_check failed."), "nx_ip_status_check failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }
}

ULONG ip_to_ulong(UINT octet1, UINT octet2, UINT octet3, UINT octet4) {
    return ((ULONG)octet1 << 24) | ((ULONG)octet2 << 16) | ((ULONG)octet3 << 8) | (ULONG)octet4;
}

static void tcp_serv_init(void)
{
    UINT status = NX_SUCCESS;

    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Setting up TCP sock."), "Setting up TCP sock.");

    status = nx_tcp_socket_create(&g_ip0, &server_socket, "TCP Server Socket", NX_IP_NORMAL, NX_DONT_FRAGMENT, NX_IP_TIME_TO_LIVE, 200, NX_NULL, NX_NULL);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_socket_create failed."), "nx_tcp_socket_create failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Socket Created"), "Socket Created");

    ULONG ip_address, netmask, gateway;
    nx_ip_address_get(&g_ip0, &ip_address, &netmask);
    nx_ip_gateway_address_get(&g_ip0, &gateway);

//    char ip_str[20];

    // Print each octet separately
//    snprintf(ip_str, sizeof(ip_str), "IP First Octet: %lu", (ip_address >> 24) & 0xFF);
//    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof(ip_str), ip_str);
//
//    snprintf(ip_str, sizeof(ip_str), "IP Second Octet: %lu", (ip_address >> 16) & 0xFF);
//    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof(ip_str), ip_str);
//
//    snprintf(ip_str, sizeof(ip_str), "IP Third Octet: %lu", (ip_address >> 8) & 0xFF);
//    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof(ip_str), ip_str);
//
//    snprintf(ip_str, sizeof(ip_str), "IP Fourth Octet: %lu", ip_address & 0xFF);
//    app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof(ip_str), ip_str);

    status = nx_tcp_server_socket_listen(&g_ip0, SERVER_PORT, &server_socket, 5, NX_NULL);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_server_socket_listen failed."), "nx_tcp_server_socket_listen failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Socket Listening"), "Socket Listening");

    status = nx_tcp_server_socket_accept(&server_socket, NX_WAIT_FOREVER);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_server_socket_accept failed."), "nx_tcp_server_socket_accept failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Socket accept"), "Socket Accept");


    NX_PACKET *packet;
    status = nx_packet_allocate(&g_packet_pool0, &packet, NX_TCP_PACKET, NX_WAIT_FOREVER);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_packet_allocate failed."), "nx_packet_allocate failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    status = nx_packet_data_append(packet, "Hello, Client!", 15, &g_packet_pool0, NX_WAIT_FOREVER);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_packet_data_append failed."), "nx_packet_data_append failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    status = nx_tcp_socket_send(&server_socket, packet, NX_WAIT_FOREVER);
    if(NX_SUCCESS != status)
    {
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_STR, sizeof("nx_tcp_socket_send failed."), "nx_tcp_socket_send failed.");
        // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_ERR_TRAP, sizeof(UINT *), &status);
    }

    nx_packet_release(packet);
    nx_tcp_socket_disconnect(&server_socket, NX_WAIT_FOREVER);
    nx_tcp_client_socket_unbind(&server_socket);
    nx_tcp_socket_delete(&server_socket);

    // app_rtt_print_data(RTT_OUTPUT_MESSAGE_APP_INFO_STR, sizeof("Client socket closed"), "Client socket closed");
}
