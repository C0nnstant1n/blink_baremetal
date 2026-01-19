#include "app.h"
#include "button.h"
#include "blink.h"

sl_sleeptimer_timer_handle_t timer;
uint8_t timer_count = 0;

static void on_timeout(sl_sleeptimer_timer_handle_t *handle,
                       void *data);

void app_handle(void);

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
  static uint8_t app_status;
  uint8_t button_status = get_button_status();

  switch (app_status)
  {
  case 0:
    if (button_status)
    {
      if (button_status == 1)
        app_status = 1;
      if (button_status == 2)
        app_status = 2;
    }
    sl_led_turn_off(&sl_led_led0);
    break;

  case 1:
    sl_led_turn_on(&sl_led_led0);
    if (!button_status)
      break;
    if (button_status == 1)
      app_status = 0;
    if (button_status == 2)
      app_status = 2;
    break;

  case 2:
    blink_process_action();
    if (!button_status)
      break;
    if (button_status == 1)
      app_status = 0;
    if (button_status == 2)
      app_status = 1;
    break;

  default:
    break;
  }
}