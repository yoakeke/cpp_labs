//#include <stdio.h>
//#include <locale.h> // ���������� ��������� ��� ����������� ������
//#include <string.h>
//#include <stdlib.h> // ��� ������������� atoi
//
//#define MAX_LINE_LENGTH 1024 // ������������ ����� ������
//#define MAX_PAGE_LENGTH 8192 // ������������ ����� ����������� ��������
//
//void process_file(const char* input_file, const char* output_file) {
//    FILE* infile = NULL;
//    errno_t err = fopen_s(&infile, input_file, "r");
//    if (err != 0 || infile == NULL) {
//        printf("�� ������� ������� ���� %s\n", input_file);
//        return;
//    }
//
//    FILE* outfile = NULL;
//    err = fopen_s(&outfile, output_file, "w");
//    if (err != 0 || outfile == NULL) {
//        printf("�� ������� ������� ���� %s\n", output_file);
//        fclose(infile);
//        return;
//    }
//
//    char line[MAX_LINE_LENGTH];
//    char page_content[MAX_PAGE_LENGTH] = { 0 };
//    char page_number[MAX_LINE_LENGTH] = { 0 };
//
//    while (fgets(line, sizeof(line), infile) != NULL) {
//        // ������� ������� ����� ������
//        line[strcspn(line, "\n")] = '\0';
//        line[strcspn(line, "\r")] = '\0';
//
//        // ���������, �������� �� ������ ������� ��������
//        if (strstr(line, "-") != NULL) {
//            // ��������� ����� ��������
//            char* start = strpbrk(line, "0123456789");
//            char* end = strrchr(line, ' '); // ������� ��������� ������
//            if (start != NULL) {
//                if (end != NULL) {
//                    *end = '\0'; // ��������� ������ ����� ��������
//                }
//                strncpy_s(page_number, sizeof(page_number), start, _TRUNCATE);
//            }
//            continue; // ���������� ���������� ���� ������ � page_content
//        }
//
//        // ��������� �� ������ ������ (����� ������)
//        if (line[0] == '\0') {
//            if (page_content[0] != '\0') {
//                // ���������� ���������� � ����� �������� � ����
//                fprintf(outfile, "%s\n", page_content);
//                fprintf(outfile, "%s\n", page_number); // ���������� ����� ��������
//                page_content[0] = '\0'; // ������� ���������� ��� ��������� ��������
//                page_number[0] = '\0'; // ������� ����� ��������
//            }
//        }
//        else {
//            // ��������� ������ � ����������� ��������, ���� ��� �� ����� ��������
//            if (strstr(line, "-") == NULL) { // ���� ������ �� �������� '-'
//                if (page_content[0] != '\0') {
//                    strcat_s(page_content, sizeof(page_content), "\n");
//                }
//                strcat_s(page_content, sizeof(page_content), line);
//            }
//        }
//    }
//
//    // ���������� ��������� ��������, ���� ��� �� ���� ��������
//    if (page_content[0] != '\0') {
//        fprintf(outfile, "%s\n", page_content);
//        fprintf(outfile, "%s\n", page_number);
//    }
//
//    fclose(infile);
//    fclose(outfile);
//}
//
//int main() {
//    // ������������� ��������� ��� ����������� ������
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    char input_file[MAX_LINE_LENGTH];
//    const char* output_file = "processed.txt"; // ������������� ��� ��������� �����
//
//    printf("������� ��� �������� �����: ");
//    scanf_s("%s", input_file, sizeof(input_file));
//
//    process_file(input_file, output_file);
//    printf("��������� ���������. ��������� ������� � %s.\n", output_file);
//
//    return 0;
//}