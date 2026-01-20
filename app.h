/**
 * @file app.h
 * @brief Заголовочный файл модуля управления светодиодом и кнопкой
 * @version 1.0
 * @date 2026-01-19
 */

#ifndef APP_H
#define APP_H

#include <stdint.h>
#include "sl_sleeptimer.h"
#include "button.h"
#include "blink.h"

// === Глобальные переменные ===

// === Прототипы функций ===

/**
 * @brief Инициализация приложения
 * @details Создаёт периодический таймер для пробуждения системы
 */
void app_init(void);

/**
 * @brief Основной цикл обработки
 * @details Вызывает обработку кнопки и основную логику приложения
 */
void app_process_action(void);

/**
 * @brief Получение текущего значения счётчика таймера
 * @return uint8_t Текущее значение timer_count
 */
uint8_t get_timer_count(void);

/**
 * @brief Основная логика управления состоянием
 * @details Реализует конечный автомат с тремя состояниями:
 *          - 0: светодиод выключен
 *          - 1: светодиод включён
 *          - 2: светодиод мигает
 */
void app_handle(void);

// === Макросы и константы ===

/**
 * @def TOOGLE_DELAY_MS
 * @brief Период срабатывания таймера в миллисекундах
 * @note Определяется в конфигурационном файле проекта
 */
#ifndef TOOGLE_DELAY_MS
#define TOOGLE_DELAY_MS 10 // Пример: 10 милисекунд
#endif

#endif // APP_H
