#include <iostream>

using namespace std;

/**
 * @brief Обрабатывает массив, удаляя все элементы после первого отрицательного.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void process(int*& arr, int size)
{
    int index = -1;

    // Ищем первый отрицательный элемент
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            index = i;
            break;
        }
    }

    // Если отрицательного элемента нет
    if (index == -1)
    {
        cout << "Отрицательных элементов нет." << endl;
        return;
    }

    // Создаем новый массив размером до отрицательного элемента
    int* newArr = new int[index]{};

    // Копируем элементы
    for (int i = 0; i < index; ++i)
    {
        newArr[i] = arr[i];
    }

    // Удаляем старый массив
    delete[] arr;

    // Теперь arr указывает на новый массив
    arr = newArr;

    cout << "Новый массив: ";

    for (int i = 0; i < index; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

/**
 * @brief Точка входа в программу. Создает динамический массив,
 * заполняет его и вызывает функцию обработки массива.
 * @return 0 если программа завершилась успешно
 */
int main()
{
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size]{};

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    process(arr, size);

    // Освобождаем память
    delete[] arr;

    // Обнуляем указатель
    arr = nullptr;

    // Безопасная проверка
    if (arr == nullptr)
    {
        cout << "Указатель обнулен." << endl;
    }

    return 0;
}