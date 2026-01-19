#include "blink.h"

// Время мигания в единицах счётчика таймера (минимум 1)
#define BLINK_TIME 50

#if BLINK_TIME < 1
#error "BLINK_TIME must be at least 1"
#endif

void blink_process_action(void)
{
  static uint8_t blink_status, blink_count; // Начальное состояние: светодиод выключен (blink_status = 0)

  uint8_t timer_count = get_timer_count();
  uint8_t res = timer_count - blink_count;
  switch (blink_status)
  {
  case 0:
    if (res < BLINK_TIME)
      break;
    sl_led_turn_on(&LED_INSTANCE);
    blink_count = timer_count;
    blink_status = LED_ON;
    break;

  case 1:
    if (res < BLINK_TIME)
      break;
    sl_led_turn_off(&LED_INSTANCE);
    blink_count = timer_count;
    blink_status = LED_OFF;
    break;
  default:
    blink_status = LED_OFF; // Сброс в начальное состояние
    break;
  }
}