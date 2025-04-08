//#include <iostream>
//#include <cstdlib> // Для calloc()
//#include <cstring> // Для строковых функций
//#include <locale> 
//
//using namespace std;
//
//int main() {
//    // Исправляем кодировку для корректного вывода
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char* str1 = nullptr;
//    char* str2 = nullptr;
//
//    // Выделение динамической памяти с помощью calloc()
//    str1 = (char*)calloc(100, sizeof(char)); // Выделяет 100 байт и инициализирует их нулями
//    str2 = (char*)calloc(100, sizeof(char));
//
//    // Присваиваем значения строкам с использованием strcpy_s()
//    errno_t result1 = strcpy_s(str1, 100, "Hello");
//    errno_t result2 = strcpy_s(str2, 100, "World");
//
//    // Выводим результаты
//    cout << "Результат копирования: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << endl;
//
//    // Освобождаем выделенную память
//    free(str1);
//    free(str2);
//
//    return 0;
//}