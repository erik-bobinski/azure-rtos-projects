/* generated HAL source file - do not edit */
#include "hal_data.h"
gtm_instance_ctrl_t g_timer0_ctrl;
const gtm_extended_cfg_t g_timer0_extend =
{ .generate_interrupt_when_starts = GTM_GIWS_TYPE_DISABLED, .gtm_mode = GTM_TIMER_MODE_INTERVAL, };
const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC,
  .period_counts = (uint32_t) 0x1869f /* Actual period: 0.001 seconds. */,
  .channel = 0,
  .p_callback = NULL,
  .p_context = NULL,
  .cycle_end_ipl = 30,
  .p_extend = &g_timer0_extend,
#if defined(VECTOR_NUMBER_GTM0_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GTM0_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = GTM0_OSTM0INT_IRQn,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_gtm };
extern void _tx_timer_interrupt(void);

#define portDISABLE_INTERRUPTS()									\
	__asm volatile ( "MSR DAIFSET, #1" ::: "memory" );				\
	__asm volatile ( "DSB SY" );									\
	__asm volatile ( "ISB SY" );

#define portENABLE_INTERRUPTS()										\
	__asm volatile ( "MSR DAIFCLR, #1" ::: "memory" );				\
	__asm volatile ( "DSB SY" );									\
	__asm volatile ( "ISB SY" );

/* In all GICs 255 can be written to the priority mask register to unmask all
 (but the lowest) interrupt priority. */
#define portUNMASK_VALUE				( 0xFFUL )

/* Macro to unmask all interrupt priorities. */
/* s3_0_c4_c6_0 is ICC_PMR_EL1. */
#define portCLEAR_INTERRUPT_MASK()						\
{														\
	__asm volatile (	"MSR DAIFSET, #1 		\n"		\
						"DSB SY					\n"		\
						"ISB SY					\n"		\
						"MSR s3_0_c4_c6_0, %0 	\n"		\
						"DSB SY					\n"		\
						"ISB SY					\n"		\
						"MSR DAIFCLR, #1 		\n"		\
						"DSB SY					\n"		\
						"ISB SY					\n"		\
						::"r"( portUNMASK_VALUE ) );	\
}

void tx_tick_handler(__attribute__( ( unused ))  timer_callback_args_t *unused);

void tx_tick_handler(__attribute__( ( unused ))  timer_callback_args_t *unused)
{
    /* Must be the lowest possible priority. */
#if !defined( QEMU )
    {
        uint64_t ullRunningInterruptPriority;
        /* s3_0_c12_c11_3 is ICC_RPR_EL1. */
        __asm volatile ( "MRS %0, s3_0_c12_c11_3" : "=r" ( ullRunningInterruptPriority ) );
//		configASSERT( ullRunningInterruptPriority == ( portLOWEST_USABLE_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) );
    }
#endif

    /* Set interrupt mask before altering scheduler structures.   The tick
     handler runs at the lowest priority, so interrupts cannot already be masked,
     so there is no need to save and restore the current mask value.  It is
     necessary to turn off interrupts in the CPU itself while the ICCPMR is being
     updated. */
    /* s3_0_c4_c6_0 is ICC_PMR_EL1. */
    __asm volatile ( "MSR s3_0_c4_c6_0, %0		\n"
            "DSB SY					\n"
            "ISB SY					\n"
            :: "r" ( (17UL) << (3) ) : "memory" );
//					 :: "r" ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) : "memory" );

    /* Ok to enable interrupts after the interrupt source has been cleared. */
    portENABLE_INTERRUPTS();

#ifndef TX_NO_TIMER
    _tx_timer_interrupt ();
#endif

    /* Ensure all interrupt priorities are active again. */
    portCLEAR_INTERRUPT_MASK();
}

__attribute__( ( weak ) ) void vPortSetupTimerInterrupt(void) /* PRIVILEGED_FUNCTION */
{
    /* Stop and reset the SysTick. */
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg);
    /* Configure SysTick to interrupt at the requested rate. */
    g_timer0.p_api->callbackSet (g_timer0.p_ctrl, tx_tick_handler, NULL, NULL);
    /* Start the SysTick. */
    g_timer0.p_api->start (g_timer0.p_ctrl);

}
#if configGENERATE_RUN_TIME_STATS
__attribute__( ( weak ) ) void vPortConfigureTimerForRunTimeStatus( void )
{
	/* Stop and reset the Status Timer. */
	FSP_NOT_DEFINED.p_api->open(FSP_NOT_DEFINED.p_ctrl, FSP_NOT_DEFINED.p_cfg);
	/* Start the Status Timer. */
	FSP_NOT_DEFINED.p_api->start(FSP_NOT_DEFINED.p_ctrl);
}

/* Count clock = 100MHz
   10-bits-right-shift makes 10.24us counting interval */
#define runtimeCLOCK_SCALE_SHIFT    ( 10 )

/* GTM overflows 32bit */
#define runtimeOVERFLOW_SHIFT       ( 32 - runtimeCLOCK_SCALE_SHIFT )
__attribute__( ( weak ) ) unsigned long ulGetRunTimeCounterValue( void )
{
	static unsigned long ulLastCounterValue = 0UL, ulOverflows = 0;
	unsigned long ulValueNow = 0;
	timer_status_t timer_status;

	/* Get count value */
	if (FSP_SUCCESS == FSP_NOT_DEFINED.p_api->statusGet(FSP_NOT_DEFINED.p_ctrl, &timer_status))
	{
		ulValueNow = timer_status.counter;

		/* Has the value overflowed since it was last read. */
		if( ulValueNow < ulLastCounterValue )
		{
			ulOverflows++;
		}
		ulLastCounterValue = ulValueNow;

		/* move the count value to  */
		ulValueNow >>= runtimeCLOCK_SCALE_SHIFT;
		ulValueNow += ulOverflows << runtimeOVERFLOW_SHIFT;
	}

	return ulValueNow;
}
#endif
void g_hal_init(void)
{
    g_common_init ();
}
