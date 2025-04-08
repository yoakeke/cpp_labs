//#include <iostream>
//#include <locale>  
//
//using namespace std;
//
//// 1. Определение длины строки (три способа)
//int my_strlen_while(const char* str) {
//    int length = 0;
//    while (str[length] != '\0') { // Используем цикл while
//        length++;
//    }
//    return length;
//}
//
//int my_strlen_for(const char* str) {
//    int length = 0;
//    for (int i = 0; str[i] != '\0'; i++) { // Используем цикл for
//        length++;
//    }
//    return length;
//}
//
//int my_strlen_recursive(const char* str) {
//    if (*str == '\0') { // Базовый случай: если строка пустая
//        return 0;
//    }
//    return 1 + my_strlen_recursive(str + 1); // Рекурсивный вызов
//}
//
//// 2. Сравнение строк
//int my_strcmp(const char* str1, const char* str2) {
//    int i = 0;
//    while (str1[i] != '\0' && str2[i] != '\0') {
//        if (str1[i] != str2[i]) {
//            return str1[i] - str2[i]; // Возвращаем разницу между символами
//        }
//        i++;
//    }
//    return str1[i] - str2[i]; // Если одна строка короче другой
//}
//
//// 3. Конкатенация строк
//void my_strcat(char* dest, const char* src) {
//    int len1 = my_strlen_while(dest); // Длина первой строки
//    int len2 = my_strlen_while(src);  // Длина второй строки
//
//    for (int i = 0; i <= len2; i++) { // Копируем src в конец dest
//        dest[len1 + i] = src[i];
//    }
//}
//
//// 4. Копирование строк
//void my_strcpy(char* dest, const char* src) {
//    int i = 0;
//    while (src[i] != '\0') { // Копируем каждый символ
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0'; // Добавляем завершающий нуль
//}
//
//int main() {
//    // Исправляем кодировку для корректного вывода
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char str1[100] = "Hello";
//    char str2[50] = "World";
//
//    // Тестирование функций
//    cout << "=== Тестирование функций ===" << endl;
//
//    // 1. Три способа определения длины строки
//    cout << "Длина строки str1 (использование цикла while): " << my_strlen_while(str1) << endl;
//    cout << "Длина строки str2 (использование цикла for): " << my_strlen_for(str2) << endl;
//    cout << "Длина строки str1 (использование рекурсии): " << my_strlen_recursive(str1) << endl;
//
//    // 2. Сравнение строк
//    cout << "\nСравнение строк str1 и str2: ";
//    if (my_strcmp(str1, str2) == 0) {
//        cout << "Строки равны." << endl;
//    }
//    else {
//        cout << "Строки не равны." << endl;
//    }
//
//    // 3. Конкатенация строк
//    my_strcat(str1, str2);
//    cout << "\nРезультат конкатенации: " << str1 << endl;
//
//    // 4. Копирование строк
//    char copyStr[100];
//    my_strcpy(copyStr, str1);
//    cout << "\nРезультат копирования: " << copyStr << endl;
//
//    return 0;
//}