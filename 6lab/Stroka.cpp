#define _CRT_SECURE_NO_WARNINGS

#include "Stroka.h"

// Конструктор с заданным размером
Stroka::Stroka(int s) {
    size = s;
    atr = new char[size]; // Выделяем память под строку
    atr[0] = '\0'; // Инициализируем пустую строку
}

// Конструктор с параметром
Stroka::Stroka(const char* string) {
    size = my_strlen(string) + 1; // +1 для нуль-терминатора
    atr = new char[size]; // Выделяем память под строку
    my_strcpy(atr, string); // Копируем строку
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    size = s.size;
    atr = new char[size]; // Выделяем память под строку
    my_strcpy(atr, s.atr); // Копируем строку
}

// Деструктор
Stroka::~Stroka() {
    delete[] atr; // Освобождаем память
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) { // Проверка на самоприсваивание
        delete[] atr; // Освобождаем старую память
        size = s.size;
        atr = new char[size]; // Выделяем новую память
        my_strcpy(atr, s.atr); // Копируем строку
    }
    return *this;
}

// Оператор сцепления
Stroka Stroka::operator+(const Stroka& s) {
    Stroka temp(my_strlen(atr) + my_strlen(s.atr) + 1); // Выделяем память для новой строки
    my_strcpy(temp.atr, atr); // Копируем текущую строку
    my_strcat(temp.atr, s.atr); // Сцепляем с другой строкой
    return temp; // Возвращаем новый объект
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& s) {
    return my_strcmp(atr, s.atr) == 0; // Сравниваем строки
}

// Метод для определения длины строки
int Stroka::dlina() {
    return my_strlen(atr);
}

// Метод для ввода строки
void Stroka::vvod() {
    std::cout << "Введите строку: ";
    std::cin.getline(atr, size); // Ввод строки с учетом размера
}

// Метод для вывода строки
void Stroka::vyvod() {
    std::cout << atr << std::endl; // Вывод строки
}

// Пользовательская функция для определения длины строки
int Stroka::my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Пользовательская функция для копирования строки
void Stroka::my_strcpy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

// Пользовательская функция для сравнения строк
int Stroka::my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Пользовательская функция для конкатенации строк
void Stroka::my_strcat(char* dest, const char* src) {
    while (*dest) {
        dest++; // Находим конец первой строки
    }
    while ((*dest++ = *src++)); // Сцепляем строки
}