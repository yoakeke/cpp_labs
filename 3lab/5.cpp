#include <iostream>
#include <cstdlib> // ��� rand()
#include <ctime>   // ��� time()
#include <locale>  

using namespace std;

// ������� ��� ������ �������
void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ���������� �� �������� �� ��������� [N1, N2]
void descendingSortInterval(int arr[], int N1, int N2) {
    for (int i = N1; i < N2; i++) {
        bool swapped = false;
        for (int j = N1; j < N2 - i + N1 - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    // ��������� ��������� ��� ����������� ������
    setlocale(LC_ALL, "Russian_Russia.1251"); 


    const int size = 10;
    int arr[size];

    // ���������� ������� ���������� �������
    srand(time(0)); // ������������� ���������� ��������� �����
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // ��������� ����� �� 0 �� 99
    }

    // �������� ������
    cout << "�������� ������:" << endl;
    printArray(arr, size);

    int N1 = 2, N2 = 7; // �������� �������� ��� ����������
    descendingSortInterval(arr, N1, N2);
    cout << "\n������ ����� ���������� �� ��������� [" << N1 << ", " << N2 << ") �� ��������:" << endl;
    printArray(arr, size);

    return 0;
}