//#include <iostream>
//#include <cstdlib> // Для malloc()
//#include <cstring> // Для memset(), strcpy_s()
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
//    // Выделение динамической памяти с помощью malloc()
//    str1 = (char*)malloc(100 * sizeof(char)); // Выделяет 100 байт
//    str2 = (char*)malloc(100 * sizeof(char));
//
//    // Проверка успешности выделения памяти
//    if (str1 == nullptr || str2 == nullptr) {
//        cout << "Ошибка: Не удалось выделить память!" << endl;
//        return 1; // Выход из программы при ошибке
//    }
//
//    // Инициализация памяти нулями вручную
//    memset(str1, 0, 100); // Обнуление памяти
//    memset(str2, 0, 100);
//
//    // Присваиваем значения строкам с использованием strcpy_s()
//    errno_t result1 = strcpy_s(str1, 100, "Hello");
//    errno_t result2 = strcpy_s(str2, 100, "World");
//
//    // Проверка успешности копирования
//    if (result1 != 0 || result2 != 0) {
//        cout << "Ошибка: Не удалось скопировать строки!" << endl;
//        free(str1);
//        free(str2);
//        return 1; // Выход из программы при ошибке
//    }
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