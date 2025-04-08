#include <iostream>
#include <cstring> // Для строковых функций
#include <cstdlib> // Для calloc()
#include <locale>  

using namespace std;

// Функция для вывода массива строк
void printArray(char** array, int size) {
    cout << "Массив строк:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "String " << i + 1 << ": " << array[i] << endl;
    }
}

// Функция для определения длины строки
int my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для сравнения строк
int my_strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Функция для конкатенации строк
void my_strcat(char* dest, const char* src) {
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);

    for (int i = 0; i <= len2; i++) {
        dest[len1 + i] = src[i];
    }
}

// Функция для копирования строк
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    // Исправляем кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251");

    const int SIZE = 3; // Количество строк в массиве
    char** strings = new char* [SIZE]; // Массив указателей на строки

    // Выделение памяти для каждой строки с помощью calloc()
    for (int i = 0; i < SIZE; i++) {
        strings[i] = (char*)calloc(100, sizeof(char)); // Выделяем по 100 байт для каждой строки
    }

    // Ввод строк от пользователя
    cout << "Введите " << SIZE << " строк:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Строка " << i + 1 << ": ";
        cin >> strings[i];
    }

    // Проверяем, что все строки корректно введены
    for (int i = 0; i < SIZE; i++) {
        if (strings[i] == nullptr) {
            cerr << "Ошибка: Не удалось выделить память для строки " << i + 1 << "." << endl;
            return 1;
        }
    }

    // Вывод исходного массива строк
    cout << "\nИсходный массив строк:" << endl;
    printArray(strings, SIZE);

    // 1. Определение длины строк
    cout << "\nДлины строк:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Длина строки " << i + 1 << ": " << my_strlen(strings[i]) << endl;
    }

    // 2. Конкатенация строк
    cout << "\nКонкатенация первой и второй строки:" << endl;
    char concatenated[200]; // Буфер для результата конкатенации
    strcpy_s(concatenated, sizeof(concatenated), strings[0]); // Копируем первую строку
    strcat_s(concatenated, sizeof(concatenated), strings[1]); // Добавляем вторую строку
    cout << "Результат: " << concatenated << endl;

    // 3. Сравнение строк
    cout << "\nСравнение первой и второй строки:" << endl;
    int cmpResult = my_strcmp(strings[0], strings[1]);
    if (cmpResult == 0) {
        cout << "Строки равны." << endl;
    }
    else if (cmpResult < 0) {
        cout << "Первая строка меньше второй." << endl;
    }
    else {
        cout << "Первая строка больше второй." << endl;
    }

    // 4. Копирование строк
    cout << "\nКопирование первой строки в третью:" << endl;
    strcpy_s(strings[2], 100, strings[0]); // Копируем первую строку в третью
    cout << "Третья строка после копирования: " << strings[2] << endl;

    // 5. Вывод массива строк после изменений
    cout << "\nМассив строк после всех операций:" << endl;
    printArray(strings, SIZE);

    // Освобождение памяти
    for (int i = 0; i < SIZE; i++) {
        free(strings[i]); // Освобождаем память для каждой строки
    }
    delete[] strings; // Освобождаем массив указателей

    return 0;
}