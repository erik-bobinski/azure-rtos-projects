#include "new_thread0.h"

// NetX Includes
#ifdef FEATURE_NX_IPV6
#include "../../addons/http/nxd_http_server.h"
#else
#include "../../addons/http/nx_http_server.h"
#endif

#include "../../addons/dhcp/nxd_dhcp_client.h"

#include <string.h>

// FileX Includes
#include "fx_api.h"

// FileX important variables
FX_MEDIA ram_disk;
// CHAR *ram_disk_memory = pointer; // pointer from new_thread0.c
FX_FILE my_file;
uint8_t media_memory[512];                           // Media buffer for FileX operations
uint8_t ram_disk_memory[2048] BSP_ALIGN_VARIABLE(4); // Dedicated RAM disk memory

/* Global counter variable */
static UINT counter = 0;

/* File content storage */
#define MAX_FILE_CONTENT_SIZE 1024
static char file_content[MAX_FILE_CONTENT_SIZE];
static ULONG file_content_size = 0;

/* Function declarations*/
static void nx_common_init0(void);
static void packet_pool_init0(void);
static void ip_init0(void);
static void print_ip(ULONG ip);
static UINT serve_html_file(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr);
static UINT handle_increment(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr);
static UINT handle_get_counter(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr);
static UINT handle_get_file_contents(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr);
static UINT handle_save_file(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr);
VOID _fx_ram_driver(FX_MEDIA *media_ptr);

#define LINK_ENABLE_WAIT_TIME (1000U)

/* IP instance */
NX_IP g_ip0;

/* Stack memory for g_ip0. */
// uint8_t g_ip0_stack_memory[G_IP0_TASK_STACK_SIZE] BSP_PLACE_IN_SECTION(".stack.g_ip0") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
uint8_t g_ip0_stack_memory[G_IP0_TASK_STACK_SIZE];

/* ARP cache memory for g_ip0. */
uint8_t g_ip0_arp_cache_memory[G_IP0_ARP_CACHE_SIZE] BSP_ALIGN_VARIABLE(4);

/* Packet pool instance (If this is a Trustzone part, the memory must be placed in Non-secure memory). */
NX_PACKET_POOL g_packet_pool0;
uint8_t g_packet_pool0_pool_memory[G_PACKET_POOL0_PACKET_NUM * (G_PACKET_POOL0_PACKET_SIZE + sizeof(NX_PACKET))] BSP_ALIGN_VARIABLE(4);

void *packet_address_start = g_packet_pool0_pool_memory;
void *packet_address_end = &g_packet_pool0_pool_memory[sizeof(g_packet_pool0_pool_memory) - 1];

/* Set up the HTTP server global variables */
NX_HTTP_SERVER my_server;
char demo_http_server_stack[4096];

UINT user_request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr);

NX_PACKET Sample_packet;
NX_PACKET *Sample_packet_ptr;
/* Startup Thread entry function */
void new_thread0_entry(void)
{
    // some vars for FileX processing
    ULONG actual;
    CHAR local_buffer[40];

    // status used for NetX and FileX
    UINT status = NX_SUCCESS;

    /* Initialize the NetX system.*/
    nx_common_init0();

    /* Initialize the packet pool.*/
    packet_pool_init0();

    /* create the ip instance.*/
    ip_init0();

    // init the FileX system
    _fx_system_initialize();

    /* Format the RAM disk */
    _fx_media_format(&ram_disk,
                     _fx_ram_driver,          // Driver entry
                     (CHAR *)ram_disk_memory, // RAM disk memory pointer
                     media_memory,            // Media buffer pointer
                     sizeof(media_memory),    // Media buffer size
                     "MY_RAM_DISK",           // Volume Name
                     1,                       // Number of FATs
                     32,                      // Directory Entries
                     0,                       // Hidden sectors
                     256,                     // Total sectors
                     512,                     // Sector size
                     8,                       // Sectors per cluster
                     1,                       // Heads
                     1);                      // Sectors per track

    status = _fx_media_open(&ram_disk, "RAM DISK", _fx_ram_driver, (CHAR *)ram_disk_memory, media_memory, sizeof(media_memory));
    if (status != FX_SUCCESS)
    {
        printf("Media open failed!\r\n");
        return;
    }
    printf("Media open successfully completed");
    counter++;

    // FileX: Create, Read, Write, and Close a file
    status = _fx_file_create(&ram_disk, "TEST.txt");
    if (status != FX_SUCCESS && status != FX_ALREADY_CREATED)
    {
        printf("FILE_CREATE_FAILED ERRNUM=%x\n\r", status);
        return;
    }

    status = _fx_file_open(&ram_disk, &my_file, "TEST.txt", FX_OPEN_FOR_WRITE);
    if (status != FX_SUCCESS)
    {
        printf("FILE_OPEN_FAILED ERRNUM=%x\n\r", status);
        return;
    }

    // seek to the beginning of test file
    status = _fx_file_seek(&my_file, 0);
    if (status != FX_SUCCESS)
    {
        printf("FILE_SEEK failed ERRNUM=%x\n\r", status);
        return;
    }

    // write a string to the test file
    status = _fx_file_write(&my_file, "CONTENT WRITTEN TO FILE VIA FILEX\n", 34);
    if (status != FX_SUCCESS)
    {
        printf("FILE_WRITE failed ERRNUM=%x\n\r", status);
        return;
    }

    // seek back to beginning of the test file
    status = _fx_file_seek(&my_file, 0);
    if (status != FX_SUCCESS)
    {
        printf("FILE_SEEK failed ERRNUM=%x\n\r");
        return;
    }

    // read the first 34 bytes of the test file
    status = _fx_file_read(&my_file, file_content, MAX_FILE_CONTENT_SIZE, &file_content_size);
    if (status != FX_SUCCESS)
    {
        printf("FILE_READ failed ERRNUM=%x\n\r", status);
        return;
    }

    // Null terminate the string
    if (file_content_size < MAX_FILE_CONTENT_SIZE)
    {
        file_content[file_content_size] = '\0';
    }

    // Print the file content
    printf("File content: %s\n\r", file_content);
    printf("File size: %lu bytes\n\r", file_content_size);

    // close the test file
    _fx_file_close(&my_file);
    if (status != FX_SUCCESS)
    {
        printf("FILE CLOSE failed ERRNUM=%x\n\r", status);
        return;
    }

    // close the media
    status = fx_media_close(&ram_disk);
    if (status != FX_SUCCESS)
    {
        printf("FILE CLOSE failed ERRNUM=%x\n\r");
        return;
    }

    /* Create the HTTP Server.  */
    status = nx_http_server_create(&my_server, "My HTTP Server", &g_ip0, NX_NULL,
                                   demo_http_server_stack, sizeof(demo_http_server_stack), &g_packet_pool0, NX_NULL, user_request_notify);
    if (NX_SUCCESS != status)
    {
        printf("SERVER_CREATE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("SERVER_CREATE_FINISHED\n\r");

    /* OK to start the HTTP Server.   */
    status = nx_http_server_start(&my_server);
    if (NX_SUCCESS != status)
    {
        printf("SERVER_START_FAILED ERRNUM=%x\n\r", status);
    }
    printf("SERVER_START_FINISHED\n\r");
    /*Gets IP address*/
    ULONG client_ip_address = 0;
    ULONG network_mask = 0;
    status = nx_ip_address_get(&g_ip0, &client_ip_address, &network_mask);
    if (NX_SUCCESS != status)
    {
        printf("IP_ADDRESS_GET_FAILED\n\r");
    }
    printf("IP_ADDRESS: ");
    print_ip(client_ip_address);
    printf("PACKET_ADDRESS=%lx\n\r", packet_address_start);
    printf("PACKET_ADDRESS_END=%lx\n\r", packet_address_end);
}

/*******************************************************************************************************************/ /**
                                                                                                                       * @brief     Initialization of NetX system.
                                                                                                                       * @param[IN] None
                                                                                                                       * @retval    None
                                                                                                                       **********************************************************************************************************************/
static void nx_common_init0(void)
{
    /* Initialize the NetX system. */
    nx_system_initialize();
}

/*******************************************************************************************************************/ /**
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
                                        sizeof(g_packet_pool0_pool_memory));
    if (NX_SUCCESS != status)
    {
        ;
    }
}
TX_EVENT_FLAGS_GROUP my_event_flags_group;
/*******************************************************************************************************************/ /**
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
                          g_netxduo_ether_1,
                          &g_ip0_stack_memory[0],
                          G_IP0_TASK_STACK_SIZE,
                          G_IP0_TASK_PRIORITY);
    if (NX_SUCCESS != status)
    {
        printf("IP_CREATE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("IP_CREATE_FINISHED\n\r");

    /* Set the gateway address if it is configured. */
    if (IP_ADDRESS(0, 0, 0, 0) != G_IP0_GATEWAY_ADDRESS)
    {
        status = nx_ip_gateway_address_set(&g_ip0, G_IP0_GATEWAY_ADDRESS);
        if (NX_SUCCESS != status)
        {
            printf("GATEWAY_SET_FAILED ERRNUM=%x\n\r", status);
        }
        printf("GATEWAY_SET_FINISHED\n\r");
    }

    /* Enable IP fragment. */
    status = nx_ip_fragment_enable(&g_ip0);
    if (NX_SUCCESS != status)
    {
        printf("IP_FRAGMENT_ENABLE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("IP_FRAGMENT_ENABLE_FINISHED\n\r");

    /* Enables Address Resolution Protocol (ARP).*/
    status = nx_arp_enable(&g_ip0, &g_ip0_arp_cache_memory[0], G_IP0_ARP_CACHE_SIZE);
    if (NX_SUCCESS != status)
    {
        printf("ARP_ENABLE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("ARP_ENABLE_FINISHED\n\r");

    /* Enable udp.*/
    status = nx_udp_enable(&g_ip0);
    if (NX_SUCCESS != status)
    {
        printf("UDP_ENABLE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("UDP_ENABLE_FINISHED\n\r");

    /* Enable tcp.*/
    status = nx_tcp_enable(&g_ip0);
    if (NX_SUCCESS != status)
    {
        printf("TCP_ENABLE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("TCP_ENABLE_FINISHED\n\r");

    /* Enable icmp.*/
    status = nx_icmp_enable(&g_ip0);
    if (NX_SUCCESS != status)
    {
        printf("ICMP_ENABLE_FAILED ERRNUM=%x\n\r", status);
    }
    printf("ICMP_ENABLE_FINISHED\n\r");

    /* Wait for the link to be enabled. */
    ULONG current_state;
    status = nx_ip_status_check(&g_ip0, NX_IP_LINK_ENABLED, &current_state, LINK_ENABLE_WAIT_TIME);
    if (NX_SUCCESS != status)
    {
        printf("STATUS_CHECK_FAILED ERRNUM=%x\n\r", status);
    }
    printf("STATUS_CHECK_FINISHED\n\r");
}

UINT user_request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr)
{
    /* Handle different routes */
    if (strcmp(resource, "/") == 0)
    {
        if (request_type == NX_HTTP_SERVER_GET_REQUEST)
        {
            return serve_html_file(server_ptr, packet_ptr);
        }
    }
    else if (strcmp(resource, "/increment") == 0)
    {
        if (request_type == NX_HTTP_SERVER_POST_REQUEST)
        {
            return handle_increment(server_ptr, packet_ptr);
        }
    }
    else if (strcmp(resource, "/get_counter") == 0)
    {
        if (request_type == NX_HTTP_SERVER_GET_REQUEST)
        {
            return handle_get_counter(server_ptr, packet_ptr);
        }
    }
    else if (strcmp(resource, "/get_file_contents") == 0)
    {
        if (request_type == NX_HTTP_SERVER_GET_REQUEST)
        {
            return handle_get_file_contents(server_ptr, packet_ptr);
        }
    }
    else if (strcmp(resource, "/save_file") == 0)
    {
        if (request_type == NX_HTTP_SERVER_POST_REQUEST)
        {
            return handle_save_file(server_ptr, packet_ptr);
        }
    }

    /* Return 404 for unknown routes */
    char response[] = "HTTP/1.0 404 Not Found\r\nContent-Type: text/plain\r\n\r\nNot Found";
    nx_http_server_callback_data_send(server_ptr, response, strlen(response));
    return (NX_HTTP_CALLBACK_COMPLETED);
}

static UINT serve_html_file(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr)
{
    char header[128];
    const char html_start[] = "<!DOCTYPE html><html><head><title>NetX Demo Control</title>"
                              "<style>body{font-family:Arial,sans-serif;margin:40px;text-align:center}"
                              "button{padding:10px 20px;font-size:16px;cursor:pointer;margin:10px}"
                              "#counter{font-size:24px;margin:20px}"
                              "#file-content{background:#f5f5f5;padding:20px;margin:20px auto;max-width:800px;"
                              "text-align:left;white-space:pre-wrap;font-family:monospace}"
                              "textarea{width:800px;height:200px;margin:20px auto;display:block;padding:10px}"
                              "</style></head><body>";

    const char html_middle[] = "<h1>NetX Demo Control</h1>"
                               "<div id=\"counter\">Counter: 0</div>"
                               "<button onclick=\"incrementCounter()\">Increment Counter</button>"
                               "<h2>File Contents</h2>"
                               "<div id=\"file-content\">Loading...</div>"
                               "<button onclick=\"refreshFileContents()\">Refresh File Contents</button>"
                               "<h2>Edit File Contents</h2>"
                               "<textarea id=\"editor\" placeholder=\"Enter new file contents\"></textarea>"
                               "<button onclick=\"saveFileContents()\">Save Changes</button>";

    const char html_end[] = "<script>"
                            "let counter=0;"
                            "function incrementCounter(){"
                            "fetch('/increment',{method:'POST'})"
                            ".then(response=>response.text())"
                            ".then(data=>{"
                            "counter=parseInt(data);"
                            "document.getElementById('counter').textContent=`Counter: ${counter}`;"
                            "}).catch(error=>console.error('Error:',error))"
                            "}"
                            "function refreshFileContents(){"
                            "fetch('/get_file_contents')"
                            ".then(response=>response.text())"
                            ".then(data=>{"
                            "document.getElementById('file-content').textContent=data;"
                            "document.getElementById('editor').value=data;"
                            "}).catch(error=>console.error('Error:',error))"
                            "}"
                            "function saveFileContents(){"
                            "const content=document.getElementById('editor').value;"
                            "fetch('/save_file',{"
                            "method:'POST',"
                            "body:content"
                            "})"
                            ".then(response=>response.text())"
                            ".then(data=>{"
                            "if(data==='OK'){"
                            "refreshFileContents();"
                            "alert('File saved successfully!');"
                            "}else{"
                            "alert('Error saving file');"
                            "}"
                            "}).catch(error=>{"
                            "console.error('Error:',error);"
                            "alert('Error saving file');"
                            "})"
                            "}"
                            "function updateCounter(){"
                            "fetch('/get_counter')"
                            ".then(response=>response.text())"
                            ".then(data=>{"
                            "counter=parseInt(data);"
                            "document.getElementById('counter').textContent=`Counter: ${counter}`;"
                            "}).catch(error=>console.error('Error:',error))"
                            "}"
                            "window.onload=function(){"
                            "updateCounter();"
                            "refreshFileContents();"
                            "}"
                            "</script></body></html>";

    // Calculate total length
    UINT total_length = strlen(html_start) + strlen(html_middle) + strlen(html_end);

    // Send headers
    sprintf(header, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %u\r\n\r\n", total_length);
    nx_http_server_callback_data_send(server_ptr, header, strlen(header));

    // Send content in chunks
    nx_http_server_callback_data_send(server_ptr, html_start, strlen(html_start));
    nx_http_server_callback_data_send(server_ptr, html_middle, strlen(html_middle));
    nx_http_server_callback_data_send(server_ptr, html_end, strlen(html_end));

    return (NX_HTTP_CALLBACK_COMPLETED);
}

static UINT handle_increment(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr)
{
    counter++;
    char response[64];
    sprintf(response, "HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\n\r\n%d", counter);
    nx_http_server_callback_data_send(server_ptr, response, strlen(response));
    return (NX_HTTP_CALLBACK_COMPLETED);
}

static UINT handle_get_counter(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr)
{
    char response[64];
    sprintf(response, "HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\n\r\n%d", counter);
    nx_http_server_callback_data_send(server_ptr, response, strlen(response));
    return (NX_HTTP_CALLBACK_COMPLETED);
}

static UINT handle_get_file_contents(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr)
{
    char header[128];

    // Send headers first
    sprintf(header, "HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\nContent-Length: %lu\r\n\r\n",
            file_content_size);
    nx_http_server_callback_data_send(server_ptr, header, strlen(header));

    // Then send the content
    nx_http_server_callback_data_send(server_ptr, file_content, file_content_size);

    return (NX_HTTP_CALLBACK_COMPLETED);
}

static UINT handle_save_file(NX_HTTP_SERVER *server_ptr, NX_PACKET *packet_ptr)
{
    CHAR *content_start;
    ULONG content_length;
    UINT status;
    UINT actual_size;
    char temp_buffer[MAX_FILE_CONTENT_SIZE];

    // Find the content in the packet
    if (nx_http_server_content_get(server_ptr, packet_ptr, 0, temp_buffer,
                                   MAX_FILE_CONTENT_SIZE, &actual_size) == NX_SUCCESS)
    {
        // Make sure we don't overflow our buffer
        if (actual_size >= MAX_FILE_CONTENT_SIZE)
        {
            actual_size = MAX_FILE_CONTENT_SIZE - 1;
        }

        // Copy the new content
        memcpy(file_content, temp_buffer, actual_size);
        file_content_size = actual_size;

        // Ensure null termination
        if (file_content_size < MAX_FILE_CONTENT_SIZE)
        {
            file_content[file_content_size] = '\0';
        }

        // Write to the file
        status = _fx_file_seek(&my_file, 0);
        if (status == FX_SUCCESS)
        {
            status = _fx_file_write(&my_file, file_content, file_content_size);
            if (status != FX_SUCCESS)
            {
                printf("File write failed: %d\n\r", status);
            }
        }
        else
        {
            printf("File seek failed: %d\n\r", status);
        }

        // Send success response
        char response[] = "HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 2\r\n\r\nOK";
        nx_http_server_callback_data_send(server_ptr, response, strlen(response));
        return (NX_HTTP_CALLBACK_COMPLETED);
    }

    // Send error response
    char response[] = "HTTP/1.0 400 Bad Request\r\nContent-Type: text/plain\r\nContent-Length: 5\r\n\r\nError";
    nx_http_server_callback_data_send(server_ptr, response, strlen(response));
    return (NX_HTTP_CALLBACK_COMPLETED);
}

static void print_ip(ULONG ip)
{
    ULONG bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;
    printf("%d.%d.%d.%d\r\n", bytes[3], bytes[2], bytes[1], bytes[0]);
}
