/* main.c
 * Автор: Янушкевич Максим
 * Группа: 12
 */

/*
 * Клиентская программа для задания 1 варианта 24.
 * Принимает предложения из аргументов командной строки.
 */

#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

/* Выводит информацию об использовании программы */
static void print_usage(const char *program_name);

int main(int argc, char *argv[])
{
		if (argc < 2) {
				fprintf(stderr, "Ошибка: не переданы предложения для обработки.\n");
				print_usage(argv[0]);
				return EXIT_FAILURE;
		}

		printf("Задание 1, Вариант 24\n");
		printf("---------------------\n");

		int total_removed = 0;

		for (int i = 1; i < argc; i++) {
				char *original = argv[i];
				printf("Исходное %d: \"%s\"\n", i, original);

				int removed = process_string(argv[i]);

				printf("Обработано %d: \"%s\"\n", i, argv[i]);
				printf("Удалено букв: %d\n\n", removed);

				total_removed += removed;
		}

		printf("Всего удалено букв: %d\n", total_removed);
		return EXIT_SUCCESS;
}

static void print_usage(const char *program_name)
{
		printf("Использование: %s \"предложение1\" \"предложение2\" ...\n", program_name);
		printf("Пример: %s \"Привет мир\" \"AbCdEf\"\n", program_name);
}