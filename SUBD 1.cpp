#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {

    int size;
    cout << "Enter size of array: ";
    try {
        cin >> size;
        if (size <= 0) {
            throw out_of_range("Error,enter correct size");
        }
    }
    catch (out_of_range& e) {
        cerr << e.what();
        return 1000;
    }

    cout << "Enter minimum number:";
    int minimumNum;
    cin >> minimumNum;

    cout << "Enter maximum number:";
    int maximumNum;
    cin >> maximumNum;

    // заполнение массива случайными числами
    random_device rd;
    mt19937 gen(rd());

    const uniform_int_distribution<int> uniformIntDistribution(minimumNum, maximumNum);

    int* arr = new int[size]; // создание динамического массива
    for (size_t i = 0; i < size; i++) {
        arr[i] = uniformIntDistribution(gen);
    }

    // вывод массива
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // нахождение наименьшего числа в массиве
    int min = findMin(arr, size);

    cout << "Minimum of aray: " << min << endl;

    delete[] arr; // освобождение памяти, выделенной для массива

    return 0;
}