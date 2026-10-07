#include <iostream>

using namespace std;
/**
 * @brief Структура для хранения динамического массива и его размера.
 */
struct SafeArray
{
    int* data;
    int size;
};

/**
 * @brief Создает динамический массив заданного размера.
 * @param size размер создаваемого массива
 * @return структура SafeArray с выделенной памятью и указанным размером
 */
SafeArray createArray(int size)
{
    SafeArray arr;

    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}

/**
 * @brief Возвращает ссылку на элемент массива по указанному индексу.
 * @param arr ссылка на структуру SafeArray
 * @param index индекс элемента массива
 * @return ссылка на элемент массива или на переменную ошибки,
 * если индекс находится вне границ
 */
int& getElement(SafeArray& arr, int index)
{
    static int errorValue = 0;

    if (index < 0 || index >= arr.size)
    {
        cout << "Ошибка: индекс вне границ массива!" << endl;
        return errorValue;
    }

    return arr.data[index];
}

/**
 * @brief Выводит элементы массива на экран.
 * @param arr константная ссылка на структуру SafeArray
 */
void printSafe(const SafeArray& arr)
{
    cout << "Массив: ";

    for (int i = 0; i < arr.size; ++i)
    {
        cout << arr.data[i] << " ";
    }

    cout << endl;
}

/**
 * @brief Изменяет размер динамического массива с сохранением существующих элементов.
 * @param arr ссылка на структуру SafeArray
 * @param newSize новый размер массива
 */
void reSizeArray(SafeArray& arr, int newSize)
{
    int* newData = new int[newSize]{};

    int minSize;

    if (arr.size < newSize)
    {
        minSize = arr.size;
    }
    else
    {
        minSize = newSize;
    }

    for (int i = 0; i < minSize; ++i)
    {
        newData[i] = arr.data[i];
    }

    // Если массив уменьшается,
    // выводим удаляемые элементы
    if (newSize < arr.size)
    {
        cout << "Удаленные элементы: ";

        for (int i = newSize; i < arr.size; ++i)
        {
            cout << arr.data[i] << " ";
        }

        cout << endl;
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
}

/**
 * @brief Точка входа в программу. Создает SafeArray,
 * заполняет его, изменяет элементы и размеры массива,
 * а затем освобождает выделенную память.
 * @return 0 если программа завершилась успешно
 */
int main()
{
    SafeArray myArr = createArray(5);

    myArr.data[0] = 10;
    myArr.data[1] = 20;
    myArr.data[2] = 30;
    myArr.data[3] = 40;
    myArr.data[4] = 50;

    printSafe(myArr);

    // Использование функции слева от =
    getElement(myArr, 2) = 999;

    printSafe(myArr);

    // Проверка неправильного индекса
    getElement(myArr, 10) = 100;

    // Уменьшаем массив
    reSizeArray(myArr, 3);

    printSafe(myArr);

    // Увеличиваем массив
    reSizeArray(myArr, 6);

    printSafe(myArr);

    // Освобождаем память
    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}