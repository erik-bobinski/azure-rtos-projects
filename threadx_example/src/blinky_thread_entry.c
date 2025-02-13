/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include "blinky_thread.h"

// sleep_ticks global var
#include "extern.h"

extern bsp_leds_t g_bsp_leds;

/* Blinky Thread entry function */
void blinky_thread_entry (void)
{
    /* LED type structure */
    bsp_leds_t leds = g_bsp_leds;

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while (1)
        {
            ;                          // There are no LEDs on this board
        }
    }

    /* Holds level to set for pins */
    bsp_io_level_t pin_level = BSP_IO_LEVEL_LOW;

    while (1)
    {
        /* Enable access to the PFS registers. If using r_ioport module then register protection is automatically
         * handled. This code uses BSP IO functions to show how it is used.
         */
        R_BSP_PinAccessEnable();

        /* Update all board LEDs */
        for (uint32_t i = 0; i < leds.led_count; i++)
        {
            /* Get pin to toggle */
            uint32_t pin = leds.p_leds[i];

            /* Write to this pin */
            R_BSP_PinWrite((bsp_io_port_pin_t) pin, pin_level);
        }

        /* Protect PFS registers */
        R_BSP_PinAccessDisable();

        /* Toggle level for next write */
        if (BSP_IO_LEVEL_LOW == pin_level)
        {
            pin_level = BSP_IO_LEVEL_HIGH;
        }
        else
        {
            pin_level = BSP_IO_LEVEL_LOW;
        }

        tx_thread_sleep(sleep_ticks);
    }
}



//// CODE FOR LED TOGGLE WITH S1
//#include "blinky_thread.h"
//
//void blinky_thread_entry(void);
//
//extern bsp_leds_t leds = g_bsp_leds;
//
//void blinky_thread_entry(void) {
//    bsp_io_level_t pin_level = BSP_IO_LEVEL_HIGH;
//
//    /* If this board has no LEDs then trap here */
//        if (0 == leds.led_count)
//        {
//            while (1)
//            {
//                ;// There are no LEDs on this board
//            }
//        }
//
//        /* Enable access to the PFS registers.
//         If using r_ioport module then register protection is automatically
//         handled. This code uses BSP IO functions to show how it is used.
//        */
//    R_BSP_PinAccessEnable();
//
//    while(1) {
//
//        /* Update all board LEDs */
//        for (uint32_t i = 0; i < leds.led_count; i++)
//        {
//            /* Get pin to toggle */
//            uint32_t pin = leds.p_leds[i];
//
//            /* Write to this pin */
//            R_BSP_PinWrite((bsp_io_port_pin_t) pin, pin_level);
//        }
//
//
//        if (BSP_IO_LEVEL_LOW == pin_level)
//            {
//                pin_level = BSP_IO_LEVEL_HIGH;
//            }
//            else
//            {
//                pin_level = BSP_IO_LEVEL_LOW;
//            }
//
//        tx_semaphore_get(&g_s1_semaphore0, TX_WAIT_FOREVER);
//
//    }
//}
//
//void external_irq0_callback(external_irq_callback_args_t * p_args) {
//    tx_semaphore_put(&g_s1_semaphore0);
//}

