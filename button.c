#include "button.h"
#include "app.h"

#define SW1 sl_button_sw1

uint8_t button_status;

void button_handle(void)
{

    static uint8_t ka_status = 0;
    static uint8_t button_count = 0;
    uint8_t timer_count = get_timer_count();
    sl_button_poll_step(&SW1);

    switch (ka_status)
    {
    case 0:
        if (sl_simple_button_get_state(&SW1))
        {
            ka_status = 1;
            button_count = timer_count;
        }
        break;
    case 1:
        if (!sl_simple_button_get_state(&SW1))
        {
            if ((uint8_t)(timer_count - button_count) > 5)
                button_status = BUTTON_SHORT_CLIK;
            ka_status = 0;
        }

        else
        {
            if ((uint8_t)(timer_count - button_count) >= 100)
            {
                button_status = BUTTON_LONG_CLIK;
                ka_status = 2;
            }
        }

        break;

    case 2:
        if (!sl_simple_button_get_state(&SW1))
            ka_status = 0;
    }
}

uint8_t get_button_status(void)
{
    uint8_t res = button_status;
    button_status = 0;
    return res;
}