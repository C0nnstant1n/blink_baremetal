#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h> // Для типов uint8_t
#include "sl_simple_button_instances.h"

// Макросы конфигурации времени (в тиках таймера, шаг 10 мс)
#define BUTTON_SHORT_PRESS_MS 5  // 5 × 10 мс = 50 мс (короткое нажатие)
#define BUTTON_LONG_PRESS_MS 100 // 100 × 10 мс = 1 с (длинное нажатие)

// Статусы нажатия кнопки
#define BUTTON_OFF 0        // Нет нажатия
#define BUTTON_SHORT_CLIK 1 // Короткое нажатие
#define BUTTON_LONG_CLIK 2  // Длинное нажатие

// Состояния конечного автомата
#define STATE_IDLE 0    // Ожидание нажатия
#define STATE_PRESSED 1 // Обработка нажатия
#define STATE_LONG 2    // Длительное нажатие

/**
 * @brief Обрабатывает состояние кнопки.
 *
 * Вызывается регулярно (каждые 10 мс) для отслеживания:
 * - короткого нажатия (≥ 50 мс);
 * - длинного нажатия (≥ 1 с);
 * - подавления дребезга.
 *
 * Использует внешний таймер с шагом 10 мс и библиотеку sl_button.
 */
void button_handle(void);

/**
 * @brief Возвращает текущий статус нажатия кнопки.
 *
 * @return
 *   - BUTTON_OFF (0) — нет нажатия;
 *   - BUTTON_SHORT_CLIK (1) — короткое нажатие;
 *   - BUTTON_LONG_CLIK (2) — длинное нажатие.
 *
 * @note Статус сбрасывается после чтения (устанавливается в BUTTON_OFF).
 */
uint8_t get_button_status(void);

#endif // BUTTON_H
