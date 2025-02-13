/* generated thread source file - do not edit */
#include "led_rate_thread.h"

TX_THREAD led_rate_thread;
void led_rate_thread_create(void);
static void led_rate_thread_func(ULONG thread_input);
static uint8_t led_rate_thread_stack[1024] BSP_PLACE_IN_SECTION(".stack.led_rate_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void led_rate_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&led_rate_thread, (CHAR*) "LED Rate Thread", led_rate_thread_func, (ULONG) NULL,
                            &led_rate_thread_stack, 1024, 0, 0, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&led_rate_thread, 0);
    }
}

static void led_rate_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    led_rate_thread_entry ();
}
