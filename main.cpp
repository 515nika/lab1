#include <iostream>

using namespace std;

/**
 * @brief Заполняет массив числами, введенными пользователем.
 * @param arr Ссылка на массив из 10 целых чисел.
 */
void fillArray(int (&arr)[10])
{
    cout << "Введите 10 чисел:" << endl;

    for (int i = 0; i < 10; ++i)
    {
        cin >> arr[i];
    }
}

/**
 * @brief Выводит все элементы массива на экран.
 * @param arr Ссылка на массив из 10 целых чисел.
 */
void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }

    cout << endl;
}

/**
 * @brief Меняет местами два элемента массива.
 * @param arr Ссылка на массив.
 * @param first Индекс первого элемента.
 * @param second Индекс второго элемента.
 */
void swapElements(int (&arr)[10], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

/**
 * @brief Умножает каждый элемент массива на два.
 * @param arr Ссылка на массив.
 */
void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}

int main()
{
    int arr[10];

    fillArray(arr);

    cout << "Исходный массив: ";
    printArray(arr);

    swapElements(arr, 0, 9);

    cout << "После обмена первого и последнего элементов: ";
    printArray(arr);

    multiplyByTwo(arr);

    cout << "После умножения всех элементов на 2: ";
    printArray(arr);

    return 0;
}