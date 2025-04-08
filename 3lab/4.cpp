#include <iostream>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()
#include <locale>  

using namespace std;

// Функция для вывода массива
void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Сортировка пузырьком на интервале [N1, N2]
void bubbleSortInterval(int arr[], int N1, int N2) {
    for (int i = N1; i < N2; i++) {
        bool swapped = false;
        for (int j = N1; j < N2 - i + N1 - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    // Испралвяю кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251"); 
	  system("chcp 1251");
    const int size = 10;
    int arr[size];

    // Заполнение массива случайными числами
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Случайные числа от 0 до 99
    }

    // Исходный массив
    cout << "Исходный массив:" << endl;
    printArray(arr, size);

    int N1 = 2, N2 = 7; // Интервал индексов для сортировки
    bubbleSortInterval(arr, N1, N2);
    cout << "\nМассив после сортировки на интервале [" << N1 << ", " << N2 << ") по возрастанию:" << endl;
    printArray(arr, size);

    return 0;
}