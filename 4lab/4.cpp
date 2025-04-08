//#include <iostream>
//#include <cstdlib> // ��� malloc()
//#include <cstring> // ��� memset(), strcpy_s()
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
//    // ��������� ������������ ������ � ������� malloc()
//    str1 = (char*)malloc(100 * sizeof(char)); // �������� 100 ����
//    str2 = (char*)malloc(100 * sizeof(char));
//
//    // �������� ���������� ��������� ������
//    if (str1 == nullptr || str2 == nullptr) {
//        cout << "������: �� ������� �������� ������!" << endl;
//        return 1; // ����� �� ��������� ��� ������
//    }
//
//    // ������������� ������ ������ �������
//    memset(str1, 0, 100); // ��������� ������
//    memset(str2, 0, 100);
//
//    // ����������� �������� ������� � �������������� strcpy_s()
//    errno_t result1 = strcpy_s(str1, 100, "Hello");
//    errno_t result2 = strcpy_s(str2, 100, "World");
//
//    // �������� ���������� �����������
//    if (result1 != 0 || result2 != 0) {
//        cout << "������: �� ������� ����������� ������!" << endl;
//        free(str1);
//        free(str2);
//        return 1; // ����� �� ��������� ��� ������
//    }
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