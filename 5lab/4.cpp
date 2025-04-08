#include <stdio.h>
#include <locale.h> // Исправляем кодировку для корректного вывода
#include <string.h>
#include <stdlib.h> // Для использования atoi

#define MAX_LINE_LENGTH 1024 // Максимальная длина строки
#define MAX_PAGE_LENGTH 8192 // Максимальная длина содержимого страницы

void process_file(const char* input_file, const char* output_file) {
    FILE* infile = NULL;
    errno_t err = fopen_s(&infile, input_file, "r");
    if (err != 0 || infile == NULL) {
        printf("Не удалось открыть файл %s\n", input_file);
        return;
    }

    FILE* outfile = NULL;
    err = fopen_s(&outfile, output_file, "w");
    if (err != 0 || outfile == NULL) {
        printf("Не удалось создать файл %s\n", output_file);
        fclose(infile);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char page_content[MAX_PAGE_LENGTH] = { 0 };
    char page_number[MAX_LINE_LENGTH] = { 0 };

    while (fgets(line, sizeof(line), infile) != NULL) {
        // Удаляем символы новой строки
        line[strcspn(line, "\n")] = '\0';
        line[strcspn(line, "\r")] = '\0';

        // Проверяем, является ли строка номером страницы
        if (strstr(line, "-") != NULL) {
            // Извлекаем номер страницы
            char* start = strpbrk(line, "0123456789");
            char* end = strrchr(line, ' '); // Находим последний пробел
            if (start != NULL) {
                if (end != NULL) {
                    *end = '\0'; // Завершаем строку перед пробелом
                }
                strncpy_s(page_number, sizeof(page_number), start, _TRUNCATE);
            }
            continue; // Пропускаем добавление этой строки в page_content
        }

        // Проверяем на пустую строку (конец абзаца)
        if (line[0] == '\0') {
            if (page_content[0] != '\0') {
                // Записываем содержимое и номер страницы в файл
                fprintf(outfile, "%s\n", page_content);
                fprintf(outfile, "%s\n", page_number); // Записываем номер страницы
                page_content[0] = '\0'; // Очищаем содержимое для следующей страницы
                page_number[0] = '\0'; // Очищаем номер страницы
            }
        }
        else {
            // Добавляем строку к содержимому страницы, если это не номер страницы
            if (strstr(line, "-") == NULL) { // Если строка не содержит '-'
                if (page_content[0] != '\0') {
                    strcat_s(page_content, sizeof(page_content), "\n");
                }
                strcat_s(page_content, sizeof(page_content), line);
            }
        }
    }

    // Записываем последнюю страницу, если она не была записана
    if (page_content[0] != '\0') {
        fprintf(outfile, "%s\n", page_content);
        fprintf(outfile, "%s\n", page_number);
    }

    fclose(infile);
    fclose(outfile);
}

int main() {
    // Устанавливаем кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251");

    char input_file[MAX_LINE_LENGTH];
    const char* output_file = "processed.txt"; // Фиксированное имя выходного файла

    printf("Введите имя входного файла: ");
    scanf_s("%s", input_file, sizeof(input_file));

    process_file(input_file, output_file);
    printf("Обработка завершена. Результат записан в %s.\n", output_file);

    return 0;
}