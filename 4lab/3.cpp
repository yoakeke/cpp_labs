//#include <iostream>
//#include <cstdlib> // ��� calloc()
//#include <cstring> // ��� ��������� �������
//#include <locale> 
//
//using namespace std;
//
//int main() {
//    // ���������� ��������� ��� ����������� ������
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char* str1 = nullptr;
//    char* str2 = nullptr;
//
//    // ��������� ������������ ������ � ������� calloc()
//    str1 = (char*)calloc(100, sizeof(char)); // �������� 100 ���� � �������������� �� ������
//    str2 = (char*)calloc(100, sizeof(char));
//
//    // ����������� �������� ������� � �������������� strcpy_s()
//    errno_t result1 = strcpy_s(str1, 100, "Hello");
//    errno_t result2 = strcpy_s(str2, 100, "World");
//
//    // ������� ����������
//    cout << "��������� �����������: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << endl;
//
//    // ����������� ���������� ������
//    free(str1);
//    free(str2);
//
//    return 0;
//}