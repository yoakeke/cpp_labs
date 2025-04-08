//#include <iostream>
//#include <locale>  
//
//using namespace std;
//
//// 1. ����������� ����� ������ (��� �������)
//int my_strlen_while(const char* str) {
//    int length = 0;
//    while (str[length] != '\0') { // ���������� ���� while
//        length++;
//    }
//    return length;
//}
//
//int my_strlen_for(const char* str) {
//    int length = 0;
//    for (int i = 0; str[i] != '\0'; i++) { // ���������� ���� for
//        length++;
//    }
//    return length;
//}
//
//int my_strlen_recursive(const char* str) {
//    if (*str == '\0') { // ������� ������: ���� ������ ������
//        return 0;
//    }
//    return 1 + my_strlen_recursive(str + 1); // ����������� �����
//}
//
//// 2. ��������� �����
//int my_strcmp(const char* str1, const char* str2) {
//    int i = 0;
//    while (str1[i] != '\0' && str2[i] != '\0') {
//        if (str1[i] != str2[i]) {
//            return str1[i] - str2[i]; // ���������� ������� ����� ���������
//        }
//        i++;
//    }
//    return str1[i] - str2[i]; // ���� ���� ������ ������ ������
//}
//
//// 3. ������������ �����
//void my_strcat(char* dest, const char* src) {
//    int len1 = my_strlen_while(dest); // ����� ������ ������
//    int len2 = my_strlen_while(src);  // ����� ������ ������
//
//    for (int i = 0; i <= len2; i++) { // �������� src � ����� dest
//        dest[len1 + i] = src[i];
//    }
//}
//
//// 4. ����������� �����
//void my_strcpy(char* dest, const char* src) {
//    int i = 0;
//    while (src[i] != '\0') { // �������� ������ ������
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0'; // ��������� ����������� ����
//}
//
//int main() {
//    // ���������� ��������� ��� ����������� ������
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char str1[100] = "Hello";
//    char str2[50] = "World";
//
//    // ������������ �������
//    cout << "=== ������������ ������� ===" << endl;
//
//    // 1. ��� ������� ����������� ����� ������
//    cout << "����� ������ str1 (������������� ����� while): " << my_strlen_while(str1) << endl;
//    cout << "����� ������ str2 (������������� ����� for): " << my_strlen_for(str2) << endl;
//    cout << "����� ������ str1 (������������� ��������): " << my_strlen_recursive(str1) << endl;
//
//    // 2. ��������� �����
//    cout << "\n��������� ����� str1 � str2: ";
//    if (my_strcmp(str1, str2) == 0) {
//        cout << "������ �����." << endl;
//    }
//    else {
//        cout << "������ �� �����." << endl;
//    }
//
//    // 3. ������������ �����
//    my_strcat(str1, str2);
//    cout << "\n��������� ������������: " << str1 << endl;
//
//    // 4. ����������� �����
//    char copyStr[100];
//    my_strcpy(copyStr, str1);
//    cout << "\n��������� �����������: " << copyStr << endl;
//
//    return 0;
//}