#define _CRT_SECURE_NO_WARNINGS

#include "Stroka.h"

// ����������� � �������� ��������
Stroka::Stroka(int s) {
    size = s;
    atr = new char[size]; // �������� ������ ��� ������
    atr[0] = '\0'; // �������������� ������ ������
}

// ����������� � ����������
Stroka::Stroka(const char* string) {
    size = my_strlen(string) + 1; // +1 ��� ����-�����������
    atr = new char[size]; // �������� ������ ��� ������
    my_strcpy(atr, string); // �������� ������
}

// ����������� �����������
Stroka::Stroka(const Stroka& s) {
    size = s.size;
    atr = new char[size]; // �������� ������ ��� ������
    my_strcpy(atr, s.atr); // �������� ������
}

// ����������
Stroka::~Stroka() {
    delete[] atr; // ����������� ������
}

// �������� ������������
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) { // �������� �� ����������������
        delete[] atr; // ����������� ������ ������
        size = s.size;
        atr = new char[size]; // �������� ����� ������
        my_strcpy(atr, s.atr); // �������� ������
    }
    return *this;
}

// �������� ���������
Stroka Stroka::operator+(const Stroka& s) {
    Stroka temp(my_strlen(atr) + my_strlen(s.atr) + 1); // �������� ������ ��� ����� ������
    my_strcpy(temp.atr, atr); // �������� ������� ������
    my_strcat(temp.atr, s.atr); // �������� � ������ �������
    return temp; // ���������� ����� ������
}

// �������� ���������
bool Stroka::operator==(const Stroka& s) {
    return my_strcmp(atr, s.atr) == 0; // ���������� ������
}

// ����� ��� ����������� ����� ������
int Stroka::dlina() {
    return my_strlen(atr);
}

// ����� ��� ����� ������
void Stroka::vvod() {
    std::cout << "������� ������: ";
    std::cin.getline(atr, size); // ���� ������ � ������ �������
}

// ����� ��� ������ ������
void Stroka::vyvod() {
    std::cout << atr << std::endl; // ����� ������
}

// ���������������� ������� ��� ����������� ����� ������
int Stroka::my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// ���������������� ������� ��� ����������� ������
void Stroka::my_strcpy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

// ���������������� ������� ��� ��������� �����
int Stroka::my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// ���������������� ������� ��� ������������ �����
void Stroka::my_strcat(char* dest, const char* src) {
    while (*dest) {
        dest++; // ������� ����� ������ ������
    }
    while ((*dest++ = *src++)); // �������� ������
}