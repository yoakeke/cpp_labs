//#include <stdio.h>
#include <locale> 
#include <string.h>

int main(void)
{
    // Исправляем кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251");

    char filename[50];
    char search_str[50];
    char line[1024]; // Буфер для чтения строк

    printf("Введите имя файла для поиска: ");
    scanf_s("%s", filename, sizeof(filename));

    printf("Введите строку для поиска: ");
    scanf_s("%s", search_str, sizeof(search_str));

    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL)
    {
        printf("Ошибка: Файл '%s' не найден.\n", filename);
        return 1;
    }

    FILE* output_file = NULL;
    err = fopen_s(&output_file, "results.txt", "w"); // Безопасная версия fopen
    if (err != 0 || output_file == NULL)
    {
        printf("Ошибка: Не удалось создать файл 'results.txt'.\n");
        fclose(file);
        return 1;
    }

    // Поиск строки в файле
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, search_str) != NULL) // Если строка найдена
        {
            fputs(line, output_file); // Записываем строку в результирующий файл
        }
    }

    fclose(file);
    fclose(output_file);

    printf("Результаты поиска сохранены в файле 'results.txt'.\n");

    return 0;
}