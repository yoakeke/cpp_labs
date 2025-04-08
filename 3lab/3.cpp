//#include <iostream>
//#include <vector> // Для использования векторов
//#include <algorithm> // Для sort()
//#include <locale>
//
//using namespace std;
//
//// Функция для вывода массива
//void printArray(const vector<int>& arr) {
//    cout << "[";
//    for (size_t i = 0; i < arr.size(); i++) {
//        cout << arr[i];
//        if (i < arr.size() - 1) cout << ", ";
//    }
//    cout << "]" << endl;
//}
//
//// Основная функция для сортировки
//vector<int> sortEvenOdd(vector<int>& arr) {
//    vector<int> evens; // Для четных чисел
//    vector<int> odds;  // Для нечетных чисел
//
//    // Разделяем массив на четные и нечетные числа
//    for (int num : arr) {
//        if (num % 2 == 0) {
//            evens.push_back(num); // Добавляем четное число
//        }
//        else {
//            odds.push_back(num);  // Добавляем нечетное число
//        }
//    }
//
//    // Сортируем четные числа по возрастанию
//    sort(evens.begin(), evens.end());
//
//    // Сортируем нечетные числа по убыванию
//    sort(odds.begin(), odds.end(), greater<int>());
//
//    // Объединяем результаты
//    vector<int> result;
//    size_t evenIndex = 0, oddIndex = 0;
//
//    for (int num : arr) {
//        if (num % 2 == 0) {
//            result.push_back(evens[evenIndex++]); // Берем из отсортированных четных
//        }
//        else {
//            result.push_back(odds[oddIndex++]);  // Берем из отсортированных нечетных
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    // Испралвяю кодировку для корректного вывода
//     setlocale(LC_ALL, "Russian_Russia.1251");
//
//    // Исходный массив
//    vector<int> arr = { 5, 8, 3, 12, 7, 6, 9, 4, 10 };
//
//    cout << "Исходный массив:" << endl;
//    printArray(arr);
//
//    // Сортировка четных чисел по возрастанию и нечетных по убыванию
//    vector<int> sortedArr = sortEvenOdd(arr);
//
//    cout << "\nМассив после сортировки:" << endl;
//    printArray(sortedArr);
//
//    return 0;
//}