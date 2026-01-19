#include "app.h"
#include "sl_simple_button_instances.h"

#define BUTTON_OFF 0
#define BUTTON_SHORT_CLIK 1
#define BUTTON_LONG_CLIK 2

#define SW1 sl_button_sw1

uint8_t button_status;

void button_handle()
{

    static uint8_t ka_status = 0;
    static uint8_t button_count = 0;
    uint8_t timer_count = get_timer_count();
    sl_button_poll_step(&SW1);

    switch (ka_status)
    {
    case BUTTON_SHORT_CLIK:
        if (sl_simple_button_get_state(&SW1))
        {
            ka_status = 1;
            button_count = timer_count;
        }
        break;
    case BUTTON_LONG_CLIK:
        if (!sl_simple_button_get_state(&SW1))
        {
            if (timer_count - button_count > 3)
            {
                button_status = 1;
                ka_status = 0;
            }
            else
            {
                if (timer_count - button_count >= 10)
                {
                    button_status = 2;
                    ka_status = 2;
                }
            }
        }
        break;

    default:
        break;
    }
}