#include "button.h"
#include "app.h"

#define SW1 sl_button_sw1

static uint8_t button_status = 0;

void button_handle(void)
{

    static uint8_t ka_status = 0;
    static uint8_t button_count = 0;

    uint8_t timer_count = get_timer_count(); // получаем колчество тиков таймера настроенного на 10 мс

    sl_button_poll_step(&SW1); // слушаем состояние кнопки
    bool btn_state = sl_simple_button_get_state(&SW1);

    switch (ka_status)
    {
    case STATE_IDLE: // если кнопка не нажата ничего не делаем, иначе переходим в состояние 1
        if (btn_state)
        {
            ka_status = 1;
            button_count = timer_count;
        }
        break;
    case STATE_PRESSED:
        uint8_t result_count = timer_count - button_count;
        if (!btn_state)
        {
            if (result_count > BUTTON_SHORT_PRESS_MS) // если кнопка нажата > n отсчетов по 10мс фиксируем короткое нажатие
                button_status = BUTTON_SHORT_CLIK;
            ka_status = 0; // если менее фиксируем дребезг и уходим в начальное состояние
        }

        else
        {
            if (result_count >= BUTTON_LONG_PRESS_MS)
            {
                button_status = BUTTON_LONG_CLIK; // фиксируем длинное нажатие
                ka_status = 2;
            }
        }

        break;

    case STATE_LONG:
        if (!btn_state) // просто ждем пока не отпустят кнопку
            ka_status = 0;
    }
}

uint8_t get_button_status(void)
{
    uint8_t res = button_status;
    button_status = 0; // сбрасываем состояние после чтения
    return res;
}