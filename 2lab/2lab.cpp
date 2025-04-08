#include <iostream>
#include <iomanip> // Для setprecision и setw
#include <cstdlib> // Для rand()
#include <cmath>   // Для abs() и других математических операций
#include <locale>  // Для setlocale

#define N 5 // Размер матрицы (N x N)

using namespace std;

// Функция для вывода матрицы
void printMatrix(float matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << setprecision(2) << matrix[i][j]; // Вывод элементов с форматированием
        }
        cout << endl;
    }
}

// Функция для заполнения матрицы случайными числами
void fillMatrix(float matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100 / 10.0; // Генерация случайных чисел от 0 до 9.9
        }
    }
}

// Минимум матрицы
float findMin(float matrix[][N]) {
    float minVal = matrix[0][0]; // Инициализация минимального значения первым элементом
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < minVal) { // Сравнение текущего элемента с минимальным
                minVal = matrix[i][j];
            }
        }
    }
    return minVal; // Возвращаем минимальное значение
}

// Максимум матрицы
float findMax(float matrix[][N]) {
    float maxVal = matrix[0][0]; // Инициализация максимального значения первым элементом
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxVal) { // Сравнение текущего элемента с максимальным
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

// Минимум нижней треугольной части
float findMinLowerTriangle(float matrix[][N]) {
    float minVal = matrix[1][0]; // Первый элемент ниже главной диагонали
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) { // Проход по элементам ниже главной диагонали
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal; // Возвращаем минимальное значение
}

// Максимум нижней треугольной части
float findMaxLowerTriangle(float matrix[][N]) {
    float maxVal = matrix[1][0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) { // Проход по элементам ниже главной диагонали
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

// Минимум верхней треугольной части
float findMinUpperTriangle(float matrix[][N]) {
    float minVal = matrix[0][1]; // Первый элемент выше главной диагонали
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) { // Проход по элементам выше главной диагонали
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal; // Возвращаем минимальное значение
}

// Максимум верхней треугольной части
float findMaxUpperTriangle(float matrix[][N]) {
    float maxVal = matrix[0][1];
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) { // Проход по элементам выше главной диагонали
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

// Минимум главной диагонали
float findMinMainDiagonal(float matrix[][N]) {
    float minVal = matrix[0][0]; // Инициализация минимального значения первым элементом диагонали
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] < minVal) { // Сравнение элементов на главной диагонали
            minVal = matrix[i][i];
        }
    }
    return minVal; // Возвращаем минимальное значение
}

// Максимум главной диагонали
float findMaxMainDiagonal(float matrix[][N]) {
    float maxVal = matrix[0][0]; // Инициализация максимального значения первым элементом диагонали
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] > maxVal) { // Сравнение элементов на главной диагонали
            maxVal = matrix[i][i];
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

// Минимум побочной диагонали
float findMinSecondaryDiagonal(float matrix[][N]) {
    float minVal = matrix[0][N - 1]; // Первый элемент побочной диагонали
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] < minVal) { // Сравнение элементов на побочной диагонали
            minVal = matrix[i][N - 1 - i];
        }
    }
    return minVal; // Возвращаем минимальное значение
}

// Максимум побочной диагонали
float findMaxSecondaryDiagonal(float matrix[][N]) {
    float maxVal = matrix[0][N - 1]; // Первый элемент побочной диагонали
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] > maxVal) { // Сравнение элементов на побочной диагонали
            maxVal = matrix[i][N - 1 - i];
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

// Среднее арифметическое всей матрицы
float findAverageMatrix(float matrix[][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j]; // Суммирование всех элементов матрицы
        }
    }
    return sum / (N * N); // Возвращаем среднее арифметическое
}

// Среднее арифметическое нижней треугольной части
float findAverageLowerTriangle(float matrix[][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) { // Проход по элементам ниже главной диагонали
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count; // Возвращаем среднее арифметическое
}

// Среднее арифметическое верхней треугольной части
float findAverageUpperTriangle(float matrix[][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) { // Проход по элементам выше главной диагонали
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count; // Возвращаем среднее арифметическое
}

// Суммы строк
void rowSums(float matrix[][N], float sums[]) {
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < N; j++) {
            sums[i] += matrix[i][j]; // Суммирование элементов строки
        }
    }
}

// Суммы столбцов
void columnSums(float matrix[][N], float sums[]) {
    for (int j = 0; j < N; j++) {
        sums[j] = 0;
        for (int i = 0; i < N; i++) {
            sums[j] += matrix[i][j]; // Суммирование элементов столбца
        }
    }
}

// Минимумы строк
void rowMins(float matrix[][N], float mins[]) {
    for (int i = 0; i < N; i++) {
        mins[i] = matrix[i][0]; // Инициализация минимального значения первой ячейкой строки
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] < mins[i]) {
                mins[i] = matrix[i][j];
            }
        }
    }
}

// Минимумы столбцов
void columnMins(float matrix[][N], float mins[]) {
    for (int j = 0; j < N; j++) {
        mins[j] = matrix[0][j]; // Инициализация минимального значения первой ячейкой столбца
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] < mins[j]) {
                mins[j] = matrix[i][j];
            }
        }
    }
}

// Максимумы строк
void rowMaxs(float matrix[][N], float maxs[]) {
    for (int i = 0; i < N; i++) {
        maxs[i] = matrix[i][0]; // Инициализация максимального значения первой ячейкой строки
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > maxs[i]) {
                maxs[i] = matrix[i][j];
            }
        }
    }
}

// Максимумы столбцов
void columnMaxs(float matrix[][N], float maxs[]) {
    for (int j = 0; j < N; j++) {
        maxs[j] = matrix[0][j]; // Инициализация максимального значения первой ячейкой столбца
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] > maxs[j]) {
                maxs[j] = matrix[i][j];
            }
        }
    }
}

// Средние арифметические строки
void rowAverages(float matrix[][N], float averages[]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j]; // Суммирование элементов строки
        }
        averages[i] = sum / N; // Вычисление среднего арифметического строки
    }
}

// Средние арифметические столбцов
void columnAverages(float matrix[][N], float averages[]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += matrix[i][j]; // Суммирование элементов столбца
        }
        averages[j] = sum / N; // Вычисление среднего арифметического столбца
    }
}

// Элемент матрицы, наиболее близкий к среднему арифметическому всего массива
float findClosestToAverage(float matrix[][N], float average) {
    float closestElement = matrix[0][0]; // Инициализация первого элемента как ближайшего
    float minDifference = abs(matrix[0][0] - average); // Разница между первым элементом и средним
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float currentDifference = abs(matrix[i][j] - average); // Текущая разница
            if (currentDifference < minDifference) { // Если текущая разница меньше минимальной
                minDifference = currentDifference;
                closestElement = matrix[i][j];
            }
        }
    }
    return closestElement; // Возвращаем ближайший элемент
}

int main() {
    float matrix[N][N];
    float rowSumsArray[N], columnSumsArray[N], rowMinsArray[N], columnMinsArray[N];
    float rowMaxsArray[N], columnMaxsArray[N], rowAveragesArray[N], columnAveragesArray[N];

    // Испралвяю кодировку для корректного вывода
    setlocale(LC_ALL, "Russian_Russia.1251"); // Для Windows


    // Заполнение матрицы случайными числами
    fillMatrix(matrix);

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    // Вычисление и вывод различных характеристик матрицы
    cout << "\nМинимум матрицы: " << findMin(matrix) << endl;
    cout << "Максимум матрицы: " << findMax(matrix) << endl;

    cout << "Минимум нижней треугольной части: " << findMinLowerTriangle(matrix) << endl;
    cout << "Максимум нижней треугольной части: " << findMaxLowerTriangle(matrix) << endl;

    cout << "Минимум верхней треугольной части: " << findMinUpperTriangle(matrix) << endl;
    cout << "Максимум верхней треугольной части: " << findMaxUpperTriangle(matrix) << endl;

    cout << "Минимум главной диагонали: " << findMinMainDiagonal(matrix) << endl;
    cout << "Максимум главной диагонали: " << findMaxMainDiagonal(matrix) << endl;

    cout << "Минимум побочной диагонали: " << findMinSecondaryDiagonal(matrix) << endl;
    cout << "Максимум побочной диагонали: " << findMaxSecondaryDiagonal(matrix) << endl;

    cout << "Среднее арифметическое всей матрицы: " << findAverageMatrix(matrix) << endl;
    cout << "Среднее арифметическое нижней треугольной части: " << findAverageLowerTriangle(matrix) << endl;
    cout << "Среднее арифметическое верхней треугольной части: " << findAverageUpperTriangle(matrix) << endl;

    rowSums(matrix, rowSumsArray);
    cout << "\nСуммы строк: ";
    for (int i = 0; i < N; i++) {
        cout << rowSumsArray[i] << " ";
    }

    columnSums(matrix, columnSumsArray);
    cout << "\nСуммы столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << columnSumsArray[j] << " ";
    }

    rowMins(matrix, rowMinsArray);
    cout << "\nМинимумы строк: ";
    for (int i = 0; i < N; i++) {
        cout << rowMinsArray[i] << " ";
    }

    columnMins(matrix, columnMinsArray);
    cout << "\nМинимумы столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << columnMinsArray[j] << " ";
    }

    rowMaxs(matrix, rowMaxsArray);
    cout << "\nМаксимумы строк: ";
    for (int i = 0; i < N; i++) {
        cout << rowMaxsArray[i] << " ";
    }

    columnMaxs(matrix, columnMaxsArray);
    cout << "\nМаксимумы столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << columnMaxsArray[j] << " ";
    }

    rowAverages(matrix, rowAveragesArray);
    cout << "\nСредние арифметические строки: ";
    for (int i = 0; i < N; i++) {
        cout << rowAveragesArray[i] << " ";
    }

    columnAverages(matrix, columnAveragesArray);
    cout << "\nСредние арифметические столбцы: ";
    for (int j = 0; j < N; j++) {
        cout << columnAveragesArray[j] << " ";
    }

    float average = findAverageMatrix(matrix);
    float closestElement = findClosestToAverage(matrix, average);
    cout << "\n\nЭлемент матрицы, наиболее близкий к среднему арифметическому: " << closestElement << endl;

    return 0;
}