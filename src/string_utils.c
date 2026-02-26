/* string_utils.c
 * Янушкевич Максим
 * Группа: 12
 */

/*
 * Реализация функций модуля обработки строк.
 */

#include "string_utils.h"
#include <string.h>

/* Проверяет, является ли символ буквой (латиница или кириллица) */
static int is_letter(char c)
{
    unsigned char uc = (unsigned char)c;

    /* Латиница */
    if ((uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z')) {
        return 1;
    }

    /* Кириллица (для кодировки CP1251/KOI8-R) */
    if (uc >= 192 && uc <= 255) {
        return 1;
    }

    return 0;
}

/* Удаляет буквы на чётных позициях в строке.
 * Используется два указателя: read_idx для чтения, write_idx для записи.
 * Позиция считается от 1 (первый символ - позиция 1).
 */
int process_string(char *str)
{
    if (str == NULL) {
        return 0;
    }

    size_t len = strlen(str);
    size_t read_idx = 0;
    size_t write_idx = 0;
    size_t position = 1;
    int removed = 0;

    for (read_idx = 0; read_idx < len; read_idx++) {
        char current_char = str[read_idx];

        /* Проверка: буква на чётной позиции */
        if (is_letter(current_char) && (position % 2 == 0)) {
            removed++;  /* буква удаляется */
        } else {
            /* символ остаётся, сдвигаем если нужно */
            if (write_idx != read_idx) {
                str[write_idx] = current_char;
            }
            write_idx++;
        }
        position++;
    }

    str[write_idx] = '\0';
    return removed;
}