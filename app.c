#include "app.h"

sl_sleeptimer_timer_handle_t timer;
uint8_t timer_count = 0;

static void on_timeout(sl_sleeptimer_timer_handle_t *handle,
                       void *data);

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
  blink_process_action();
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