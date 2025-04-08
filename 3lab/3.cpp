//#include <iostream>
//#include <vector> // ��� ������������� ��������
//#include <algorithm> // ��� sort()
//#include <locale>
//
//using namespace std;
//
//// ������� ��� ������ �������
//void printArray(const vector<int>& arr) {
//    cout << "[";
//    for (size_t i = 0; i < arr.size(); i++) {
//        cout << arr[i];
//        if (i < arr.size() - 1) cout << ", ";
//    }
//    cout << "]" << endl;
//}
//
//// �������� ������� ��� ����������
//vector<int> sortEvenOdd(vector<int>& arr) {
//    vector<int> evens; // ��� ������ �����
//    vector<int> odds;  // ��� �������� �����
//
//    // ��������� ������ �� ������ � �������� �����
//    for (int num : arr) {
//        if (num % 2 == 0) {
//            evens.push_back(num); // ��������� ������ �����
//        }
//        else {
//            odds.push_back(num);  // ��������� �������� �����
//        }
//    }
//
//    // ��������� ������ ����� �� �����������
//    sort(evens.begin(), evens.end());
//
//    // ��������� �������� ����� �� ��������
//    sort(odds.begin(), odds.end(), greater<int>());
//
//    // ���������� ����������
//    vector<int> result;
//    size_t evenIndex = 0, oddIndex = 0;
//
//    for (int num : arr) {
//        if (num % 2 == 0) {
//            result.push_back(evens[evenIndex++]); // ����� �� ��������������� ������
//        }
//        else {
//            result.push_back(odds[oddIndex++]);  // ����� �� ��������������� ��������
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    // ��������� ��������� ��� ����������� ������
//     setlocale(LC_ALL, "Russian_Russia.1251");
//
//    // �������� ������
//    vector<int> arr = { 5, 8, 3, 12, 7, 6, 9, 4, 10 };
//
//    cout << "�������� ������:" << endl;
//    printArray(arr);
//
//    // ���������� ������ ����� �� ����������� � �������� �� ��������
//    vector<int> sortedArr = sortEvenOdd(arr);
//
//    cout << "\n������ ����� ����������:" << endl;
//    printArray(sortedArr);
//
//    return 0;
//}