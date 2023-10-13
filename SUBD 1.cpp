#include <iostream>
#include <random>

using namespace std;
/**
* @brief Функция обрабатывает ввод размера массива 
*/
size_t sizeValidation();
/**
* @brief Функция заполнения массива случайными числами 
* @param arr массив
* @param size размер массива 
* @param minimumNum минимальное число в массиве 
* @param maximumNum максимальное число в массиве 
*/
void fillArr(int* arr, const size_t size, const int minimumNum, const int maximumNum);
/**
* @brief Функция вывода массива
* @param arr массив
* @param size размер массива
*/
void printArray(int* arr, const size_t size);
/**
* @brief Функция нахождения минимального значения в массиве 
* @param arr массив
* @param size размер массива
*/
int findMin(int* arr, const size_t size);

int main() {
    try {
        size_t size = sizeValidation();
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
    fillArr(arr, size, minimumNum, maximumNum);
    printArray(arr, size);

    int min = findMin(arr, size);

    cout << "Minimum of aray: " << min << endl;

    if (arr != nullptr)
    {
        delete[] arr;  
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

    return static_cast<size_t> (size);
}

void fillArr(int* arr, const size_t size, const int minimumNum, const int maximumNum)
{ 
    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<int> uniformIntDistribution(minimumNum, maximumNum);

    for (size_t i = 0; i < size; i++) {
        arr[i] = uniformIntDistribution(gen);
    }
}

void printArray(int* arr, const size_t size)
{
    cout << "Your array: ";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
