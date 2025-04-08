//#include <iostream>
//#include <cstdlib> // ��� rand()
//#include <ctime>   // ��� time()
//
//using namespace std;
//
//// ������� ��� ������ �������
//void printArray(int arr[], int size) {
//    cout << "[";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i];
//        if (i < size - 1) cout << ", ";
//    }
//    cout << "]" << endl;
//}
//
//// ������� ���������� (QuickSort)
//void quickSort(int arr[], int left, int right) {
//    if (left >= right) return; // ������� ������: ������ �� ������ ��������
//
//    int pivot = arr[(left + right) / 2]; // �������� ������� ������� (��������)
//    int i = left, j = right;
//
//    while (i <= j) {
//        while (arr[i] < pivot) i++; // ���� ������� �����, ������� ������ ��� ����� ��������
//        while (arr[j] > pivot) j--; // ���� ������� ������, ������� ������ ��� ����� ��������
//        if (i <= j) {
//            swap(arr[i], arr[j]); // ������ �������� �������
//            i++;
//            j--;
//        }
//    }
//
//    // ���������� ��������� ����� � ������ �����
//    quickSort(arr, left, j);
//    quickSort(arr, i, right);
//}
//
//int main() {
//    const int size = 10;
//    int arr[size];
//    // ��������� ��������� ��� ����������� ������
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    // ���������� ������� ���������� �������
//    srand(time(0)); // ������������� ���������� ��������� �����
//    for (int i = 0; i < size; i++) {
//        arr[i] = rand() % 100; // ��������� ����� �� 0 �� 99
//    }
//
//    // �������� ������
//    cout << "�������� ������:" << endl;
//    printArray(arr, size);
//
//    // ������� ����������
//    quickSort(arr, 0, size - 1);
//    cout << "\n������ ����� ������� ����������:" << endl;
//    printArray(arr, size);
//
//    return 0;
//}