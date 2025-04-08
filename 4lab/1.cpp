//#include <iostream>
//#include <cstring> // Для строковых функций
//#include <locale>  
//
//#define _CRT_SECURE_NO_WARNINGS // Отключение предупреждений о небезопасных функциях
//
//using namespace std;
//
//int main() {
//    // Исправляем кодировку для корректного вывода
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    // Увеличиваем размер str1 для предотвращения переполнения буфера
//    char str1[20] = "Hello"; // Теперь достаточно места для конкатенации
//    char str2[] = "World";
//
//    // 1. Определение длины строки
//    cout << "Длина строки str1: " << strlen(str1) << endl;
//    cout << "Длина строки str2: " << strlen(str2) << endl;
//
//    // 2. Конкатенация строк
//    strcat_s(str1, sizeof(str1), str2); // Добавляем str2 в конец str1
//    cout << "Результат конкатенации: " << str1 << endl;
//
//    // 3. Копирование строк
//    char copyStr[50];
//    strcpy_s(copyStr, sizeof(copyStr), str1); // Копируем str1 в copyStr
//    cout << "Результат копирования: " << copyStr << endl;
//
//    // 4. Сравнение строк
//    if (strcmp(str1, str2) == 0) {
//        cout << "Строки равны." << endl;
//    }
//    else {
//        cout << "Строки не равны." << endl;
//    }
//
//    return 0;
//}