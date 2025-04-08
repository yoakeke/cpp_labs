#ifndef STROKA_H
#define STROKA_H

#include <iostream>
#include <windows.h> // Для установки кодировки консоли
#include <locale>

class Stroka {
    char* atr; // Указатель на динамически выделенную память для строки
    int size; // Размер строки
public:
    // Конструкторы
    Stroka(int s); // Конструктор с заданным размером
    Stroka(const char* string); // Конструктор с параметром
    Stroka(const Stroka& s); // Конструктор копирования
    ~Stroka(); // Деструктор

    // Операции
    Stroka& operator=(const Stroka& s); // Оператор присваивания
    Stroka operator+(const Stroka& s); // Оператор сцепления
    bool operator==(const Stroka& s); // Оператор сравнения

    // Методы
    int dlina(); // Метод для определения длины строки
    void vvod(); // Метод для ввода строки
    void vyvod(); // Метод для вывода строки

private:
    int my_strlen(const char* str); // Пользовательская функция для определения длины строки
    void my_strcpy(char* dest, const char* src); // Пользовательская функция для копирования строки
    int my_strcmp(const char* str1, const char* str2); // Пользовательская функция для сравнения строк
    void my_strcat(char* dest, const char* src); // Пользовательская функция для конкатенации строк
};

#endif // STROKA_H