#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Выделяет память для двумерного массива.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на созданную матрицу.
 */
int** allocateMatrix(int rows, int cols)
{

    int** matrix = new int*[rows]{};


    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}
/**
 * @brief Заполняет матрицу оценками.
 * @param matrix Двумерный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        cout << "Введите оценки студента " << i + 1 << ":" << endl;

        for (int j = 0; j < cols; ++j)
        {
            cout << "Оценка " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
}
/**
 * @brief Выводит матрицу на экран.
 * @param matrix Двумерный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param showBorders Показывать ли границы матрицы.
 * @param title Заголовок матрицы.
 */
void printMatrix(
    int** matrix,
    int rows,
    int cols,
    bool showBorders = true,
    string title = "Matrix")
{
    cout << endl;
    cout << title << endl;

  
    if (showBorders)
    {
        cout << "+";
        for (int j = 0; j < cols; ++j)
        {
            cout << "-----+";
        }
        cout << endl;
    }

  
    for (int i = 0; i < rows; ++i)
    {
      
        if (showBorders)
        {
            cout << "|";
        }

        for (int j = 0; j < cols; ++j)
        {
            cout << " " << matrix[i][j] << " ";

        
            if (showBorders)
            {
                cout << "";
            }
        }

        cout << endl;

    
        if (showBorders)
        {
            cout << "+";

            for (int j = 0; j < cols; ++j)
            {
                cout << "-----+";
            }

            cout << endl;
        }
    }
}

/**
 * @brief Освобождает память двумерного массива.
 * @param matrix Двумерный массив.
 * @param rows Количество строк.
 */
void freeMatrix(int** matrix, int rows)
{
   
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main()
{
    int rows;
    int cols;

    cout << "Введите количество студентов: ";
    cin >> rows;

    cout << "Введите количество оценок: ";
    cin >> cols;


    int** matrix = allocateMatrix(rows, cols);

    // Заполняем её оценками
    fillMatrix(matrix, rows, cols);

    // 1. Без дополнительных параметров
    printMatrix(matrix, rows, cols);

    // 2. Только с заголовком
    printMatrix(matrix, rows, cols, true, "Оценки студентов");

    // 3. Со всеми параметрами
    printMatrix(matrix, rows, cols, false, "Таблица оценок");

    // Освобождаем память
    freeMatrix(matrix, rows);

    return 0;
}