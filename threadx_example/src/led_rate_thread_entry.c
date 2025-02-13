#include "led_rate_thread.h"

// sleep_ticks global var
#include "extern.h"

/* LED Rate Thread entry function */
void led_rate_thread_entry(void) {
    /* TODO: add your own code here */

    /* tracks one on-off cycle of LEDs
     * increment by 1 each time this thread procs,
     * reset every 2 procs
     */
    uint8_t tick_counter = 0;

    while (1)
    {   // one cycle of on 1s, off 1s, has occurred
        if (sleep_ticks == 100 && tick_counter == 1) {
            sleep_ticks = 50;
            tick_counter = 0;
            tx_thread_sleep (sleep_ticks);
        }
        // one cycle of on .5s, off .5s, has occurred
        else if (sleep_ticks == 50 && tick_counter == 1) {
            sleep_ticks = 100;
            tick_counter = 0;
            tx_thread_sleep(sleep_ticks);
        }
        // increment counter for current cycle
        else {
            tick_counter++;
            tx_thread_sleep (sleep_ticks);

        }

    }
}
