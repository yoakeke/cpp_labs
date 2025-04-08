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

// Сортировка пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false; // Флаг для оптимизации
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Если текущий элемент больше следующего
                swap(arr[j], arr[j + 1]); // Меняем их местами
                swapped = true;
            }
        }
        if (!swapped) break; // Если за проход не было обменов, массив отсортирован
    }
}

int main() {
    // Испралвяю кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251");

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

    // Сортировка пузырьком
    bubbleSort(arr, size);
    cout << "\nМассив после сортировки пузырьком:" << endl;
    printArray(arr, size);

    return 0;
}