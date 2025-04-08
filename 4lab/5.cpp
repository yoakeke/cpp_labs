#include <iostream>
#include <cstring> // ��� ��������� �������
#include <cstdlib> // ��� calloc()
#include <locale>  

using namespace std;

// ������� ��� ������ ������� �����
void printArray(char** array, int size) {
    cout << "������ �����:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "String " << i + 1 << ": " << array[i] << endl;
    }
}

// ������� ��� ����������� ����� ������
int my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// ������� ��� ��������� �����
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

// ������� ��� ������������ �����
void my_strcat(char* dest, const char* src) {
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);

    for (int i = 0; i <= len2; i++) {
        dest[len1 + i] = src[i];
    }
}

// ������� ��� ����������� �����
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    // ���������� ��������� ��� ����������� ������
    setlocale(LC_ALL, "Russian_Russia.1251");

    const int SIZE = 3; // ���������� ����� � �������
    char** strings = new char* [SIZE]; // ������ ���������� �� ������

    // ��������� ������ ��� ������ ������ � ������� calloc()
    for (int i = 0; i < SIZE; i++) {
        strings[i] = (char*)calloc(100, sizeof(char)); // �������� �� 100 ���� ��� ������ ������
    }

    // ���� ����� �� ������������
    cout << "������� " << SIZE << " �����:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "������ " << i + 1 << ": ";
        cin >> strings[i];
    }

    // ���������, ��� ��� ������ ��������� �������
    for (int i = 0; i < SIZE; i++) {
        if (strings[i] == nullptr) {
            cerr << "������: �� ������� �������� ������ ��� ������ " << i + 1 << "." << endl;
            return 1;
        }
    }

    // ����� ��������� ������� �����
    cout << "\n�������� ������ �����:" << endl;
    printArray(strings, SIZE);

    // 1. ����������� ����� �����
    cout << "\n����� �����:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "����� ������ " << i + 1 << ": " << my_strlen(strings[i]) << endl;
    }

    // 2. ������������ �����
    cout << "\n������������ ������ � ������ ������:" << endl;
    char concatenated[200]; // ����� ��� ���������� ������������
    strcpy_s(concatenated, sizeof(concatenated), strings[0]); // �������� ������ ������
    strcat_s(concatenated, sizeof(concatenated), strings[1]); // ��������� ������ ������
    cout << "���������: " << concatenated << endl;

    // 3. ��������� �����
    cout << "\n��������� ������ � ������ ������:" << endl;
    int cmpResult = my_strcmp(strings[0], strings[1]);
    if (cmpResult == 0) {
        cout << "������ �����." << endl;
    }
    else if (cmpResult < 0) {
        cout << "������ ������ ������ ������." << endl;
    }
    else {
        cout << "������ ������ ������ ������." << endl;
    }

    // 4. ����������� �����
    cout << "\n����������� ������ ������ � ������:" << endl;
    strcpy_s(strings[2], 100, strings[0]); // �������� ������ ������ � ������
    cout << "������ ������ ����� �����������: " << strings[2] << endl;

    // 5. ����� ������� ����� ����� ���������
    cout << "\n������ ����� ����� ���� ��������:" << endl;
    printArray(strings, SIZE);

    // ������������ ������
    for (int i = 0; i < SIZE; i++) {
        free(strings[i]); // ����������� ������ ��� ������ ������
    }
    delete[] strings; // ����������� ������ ����������

    return 0;
}