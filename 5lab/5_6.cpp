#include <stdio.h>
#include <locale.h> 
#include <string.h>

#define MAX_LINE_LENGTH 1024 // ������������ ����� ������

void encrypt_file(const char* input_file, const char* output_file, const char* key) {
    FILE* infile = NULL;
    errno_t err = fopen_s(&infile, input_file, "rb");
    if (err != 0 || infile == NULL) {
        printf("�� ������� ������� ���� %s\n", input_file);
        return;
    }

    FILE* outfile = NULL;
    err = fopen_s(&outfile, output_file, "wb");
    if (err != 0 || outfile == NULL) {
        printf("�� ������� ������� ���� %s\n", output_file);
        fclose(infile);
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;

    int key_index = 0; // ������ �������� ������� �����

    // ����������/������������ �����
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), infile)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            // ��������� XOR ��� ����������/������������
            buffer[i] ^= key[key_index % strlen(key)];
            key_index++; // ��������� � ���������� ������� �����
        }
        fwrite(buffer, 1, bytes_read, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("������� ��������. ��������� �������� � ����� '%s'.\n", output_file);
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char key[MAX_LINE_LENGTH];

    // ������ ����� �������� �����
    printf("������� ��� �������� �����: ");
    scanf_s("%s", input_filename, sizeof(input_filename));

    // ������ ����� ��������� �����
    printf("������� ��� ��������� �����: ");
    scanf_s("%s", output_filename, sizeof(output_filename));

    // ������ ����� ����������
    printf("������� ���� ����������: ");
    scanf_s("%s", key, sizeof(key));

    // ��� 1: ����������� �������� ����
    encrypt_file(input_filename, output_filename, key);

    // ��� 2: ����������� ������������� ���� ��� ���
    char temp_output[MAX_LINE_LENGTH];
    snprintf(temp_output, sizeof(temp_output), "%s_temp.txt", output_filename);

    encrypt_file(output_filename, temp_output, key);

    // ��������: ���� ������� ���������� ������� �������� �����, �� ��������� �������� ���������
    printf("������� ���������� ���������. ��������� �������� � ����� '%s'.\n", temp_output);

    return 0;
}