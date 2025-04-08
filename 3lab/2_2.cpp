//#include <iostream>
//#include <cstdlib> // Для rand()
//#include <ctime>   // Для time()
//
//using namespace std;
//
//// Функция для вывода массива
//void printArray(int arr[], int size) {
//    cout << "[";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i];
//        if (i < size - 1) cout << ", ";
//    }
//    cout << "]" << endl;
//}
//
//// Быстрая сортировка (QuickSort)
//void quickSort(int arr[], int left, int right) {
//    if (left >= right) return; // Базовый случай: массив из одного элемента
//
//    int pivot = arr[(left + right) / 2]; // Выбираем опорный элемент (середина)
//    int i = left, j = right;
//
//    while (i <= j) {
//        while (arr[i] < pivot) i++; // Ищем элемент слева, который больше или равен опорному
//        while (arr[j] > pivot) j--; // Ищем элемент справа, который меньше или равен опорному
//        if (i <= j) {
//            swap(arr[i], arr[j]); // Меняем элементы местами
//            i++;
//            j--;
//        }
//    }
//
//    // Рекурсивно сортируем левую и правую части
//    quickSort(arr, left, j);
//    quickSort(arr, i, right);
//}
//
//int main() {
//    const int size = 10;
//    int arr[size];
//    // Испралвяю кодировку для корректного вывода
//    setlocale(LC_ALL, "Russian_Russia.1251");
//
//    // Заполнение массива случайными числами
//    srand(time(0)); // Инициализация генератора случайных чисел
//    for (int i = 0; i < size; i++) {
//        arr[i] = rand() % 100; // Случайные числа от 0 до 99
//    }
//
//    // Исходный массив
//    cout << "Исходный массив:" << endl;
//    printArray(arr, size);
//
//    // Быстрая сортировка
//    quickSort(arr, 0, size - 1);
//    cout << "\nМассив после быстрой сортировки:" << endl;
//    printArray(arr, size);
//
//    return 0;
//}