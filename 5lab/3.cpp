////#include <stdio.h>
//#include <locale> 
//#include <string.h>
//
//int main(void)
//{
//    // ���������� ��������� ��� ����������� ������
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char filename[50];
//    char search_str[50];
//    char line[1024]; // ����� ��� ������ �����
//
//    printf("������� ��� ����� ��� ������: ");
//    scanf_s("%s", filename, sizeof(filename));
//
//    printf("������� ������ ��� ������: ");
//    scanf_s("%s", search_str, sizeof(search_str));
//
//    FILE* file = NULL;
//    errno_t err = fopen_s(&file, filename, "r");
//    if (err != 0 || file == NULL)
//    {
//        printf("������: ���� '%s' �� ������.\n", filename);
//        return 1;
//    }
//
//    FILE* output_file = NULL;
//    err = fopen_s(&output_file, "results.txt", "w"); // ���������� ������ fopen
//    if (err != 0 || output_file == NULL)
//    {
//        printf("������: �� ������� ������� ���� 'results.txt'.\n");
//        fclose(file);
//        return 1;
//    }
//
//    // ����� ������ � �����
//    while (fgets(line, sizeof(line), file) != NULL)
//    {
//        if (strstr(line, search_str) != NULL) // ���� ������ �������
//        {
//            fputs(line, output_file); // ���������� ������ � �������������� ����
//        }
//    }
//
//    fclose(file);
//    fclose(output_file);
//
//    printf("���������� ������ ��������� � ����� 'results.txt'.\n");
//
//    return 0;
//}