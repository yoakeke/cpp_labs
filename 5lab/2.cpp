//#include <stdio.h>
//#include <locale> 
//#include <ctype.h>
//
//int main(void)
//{
//    // Исправляем кодировку для корректного вывода
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char ch;
//    int empty_count = 0; // Подсчет пустых символов
//    int non_empty_count = 0; // Подсчет непустых символов
//    char filename[50];
//
//    printf("Введите имя файла для анализа: ");
//    scanf_s("%s", filename, sizeof(filename)); // Безопасная версия scanf
//
//    FILE* file = NULL;
//    errno_t err = fopen_s(&file, filename, "r"); // Безопасная версия fopen
//    if (err != 0 || file == NULL)
//    {
//        printf("Ошибка: Файл '%s' не найден.\n", filename);
//        return 1;
//    }
//
//    // Чтение файла посимвольно
//    while ((ch = getc(file)) != EOF)
//    {
//        if (isspace(ch)) // Проверка на пробельные символы
//            empty_count++;
//        else
//            non_empty_count++;
//    }
//
//    fclose(file);
//
//    printf("Количество пустых символов: %d\n", empty_count);
//    printf("Количество непустых символов: %d\n", non_empty_count);
//
//    return 0;
//}