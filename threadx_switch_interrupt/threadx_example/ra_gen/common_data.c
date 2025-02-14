/* generated common source file - do not edit */
#include "common_data.h"
icu_instance_ctrl_t g_external_irq0_ctrl;
const external_irq_cfg_t g_external_irq0_cfg =
{ .channel = 0, .trigger = EXTERNAL_IRQ_TRIG_FALLING, .filter_enable = false, .clock_source_div =
          EXTERNAL_IRQ_CLOCK_SOURCE_DIV_1,
  .p_callback = g_external_irq0_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (2),
#if defined(VECTOR_NUMBER_ICU_IRQ0)
    .irq                 = VECTOR_NUMBER_ICU_IRQ0,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq0 =
{ .p_ctrl = &g_external_irq0_ctrl, .p_cfg = &g_external_irq0_cfg, .p_api = &g_external_irq_on_icu };
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
TX_SEMAPHORE g_sw1_semaphore0;
void tx_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void)
{
    UINT err_g_sw1_semaphore0;
    err_g_sw1_semaphore0 = tx_semaphore_create (&g_sw1_semaphore0, (CHAR*) "SW1 Semaphore", 0);
    if (TX_SUCCESS != err_g_sw1_semaphore0)
    {
        tx_startup_err_callback (&g_sw1_semaphore0, 0);
    }
}
