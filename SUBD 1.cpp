#include <iostream>
#include <random>

using namespace std;

size_t sizeValidation();
void fillArray(int* arr, const size_t size, const int minimumNum, const int maximumNum);
void printArray(int* arr, const size_t size);
int findMin(int* arr, const size_t size);

int main() {
    size_t size;
    try {
        size = sizeValidation();
    }
    catch (out_of_range& e) {
        cerr << e.what();
        return 1000;
    }
    int* arr = new int[size];

    cout << "Enter minimum number:";
    int minimumNum;
    cin >> minimumNum;

    cout << "Enter maximum number:";
    int maximumNum;
    cin >> maximumNum;
    fillArray(arr, size, minimumNum, maximumNum);
    printArray(arr, size);
    
    // нахождение наименьшего числа в массиве
    int min = findMin(arr, size);

    cout << "Minimum of aray: " << min << endl;

    if (arr!= nullptr)
    {
        delete[] arr;  // освобождение памяти, выделенной для массива
            arr = nullptr;
    }
    return 0;
}

int findMin(int* arr, const size_t size) {
    int min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

size_t sizeValidation()
{
    int size;
        cout << "Enter size of array: ";
        cin >> size;
        if (size <= 0) {
            throw out_of_range("Error,enter correct size");
        }

    return size;
}

void fillArray(int* arr, const size_t size, const int minimumNum, const int maximumNum)
{ // заполнение массива случайными числами
    random_device rd;
    mt19937 gen(rd());

    const uniform_int_distribution<int> uniformIntDistribution(minimumNum, maximumNum);

    for (size_t i = 0; i < size; i++) {
        arr[i] = uniformIntDistribution(gen);
    }
}

void printArray(int* arr, const size_t size)
{// вывод массива
    cout << "Your array: ";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
