#include "app.h"

#define APP_STATUS_LED_OFF 0
#define APP_STATUS_LED_ON 1
#define APP_STATUS_BLINK 2

/**
 * @brief Дескриптор периодического таймера для пробуждения системы
 */
static sl_sleeptimer_timer_handle_t timer;

/**
 * @brief Счётчик срабатываний таймера (0–255)
 */
static uint8_t timer_count = 0;

// === Внутренние функции (не для использования вне модуля) ===

/**
 * @brief Обработчик срабатывания таймера
 * @param handle Дескриптор таймера (не используется)
 * @param data Дополнительные данные (не используются)
 * @details Увеличивает timer_count на 1 при каждом срабатывании
 */
static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data);

/**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  // Create timer for waking up the system periodically.
  sl_sleeptimer_start_periodic_timer_ms(&timer,
                                        TOOGLE_DELAY_MS,
                                        on_timeout, NULL,
                                        0,
                                        SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);
}

/**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  button_handle();
  app_handle();
}

static void on_timeout(sl_sleeptimer_timer_handle_t *handle,
                       void *data)
{
  (void)&handle;
  (void)&data;
  timer_count++;
}

uint8_t get_timer_count(void)
{
  return timer_count;
}

void app_handle(void)
{
  static uint8_t app_status = APP_STATUS_LED_OFF;
  uint8_t button_status = get_button_status();

  switch (app_status)
  {
  case APP_STATUS_LED_OFF:
    if (button_status)
    {
      if (button_status == BUTTON_SHORT_CLIK)
        app_status = APP_STATUS_LED_ON;
      if (button_status == BUTTON_LONG_CLIK)
        app_status = APP_STATUS_BLINK;
    }
    sl_led_turn_off(&sl_led_led0);
    break;

  case APP_STATUS_LED_ON:
    sl_led_turn_on(&sl_led_led0);
    if (!button_status)
      break;
    if (button_status == BUTTON_SHORT_CLIK)
      app_status = APP_STATUS_LED_OFF;
    if (button_status == BUTTON_LONG_CLIK)
      app_status = APP_STATUS_BLINK;
    break;

  case APP_STATUS_BLINK:
    blink_process_action();
    if (!button_status)
      break;
    if (button_status == BUTTON_SHORT_CLIK)
      app_status = APP_STATUS_LED_OFF;
    if (button_status == BUTTON_LONG_CLIK)
      app_status = APP_STATUS_LED_ON;
    break;
  }
}