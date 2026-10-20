#include <stdio.h>

int check_rows(int SIZE, int sudoku[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        int nums[SIZE];
        for (int n = 0; n < SIZE; n++)
        {
            nums[n] = sudoku[r][n];
            for (int i = 0; i < n; i++)
            {
                if (sudoku[r][n] == nums[i])
                {
                    printf("Ошибка, строка: %d номер: %d\n", r + 1, n + 1);
                    return 1;
                }
            }
        }
    }
    return 0;
};
int check_colums(int SIZE, int sudoku[SIZE][SIZE])
{
    for (int c = 0; c < SIZE; c++)
    {
        int nums[SIZE];
        for (int n = 0; n < SIZE; n++)
        {
            nums[n] = sudoku[n][c];
            for (int i = 0; i < n; i++)
            {
                if (sudoku[n][c] == nums[i])
                {
                    printf("Ошибка, столбец: %d номер: %d\n", c + 1, n + 1);
                    return 1;
                }
            }
        }
    }
    return 0;
};

int check_squares(int SIZE, int sudoku[SIZE][SIZE])
{
    int count = 0;
    while (count < SIZE)
    {
        int row_tek_kv = (count / 3) * 3;
        int col_tek_kv = (count % 3) * 3;

        int nums[SIZE];

        for (int i = 0; i < SIZE; i++)
        {
            int r = row_tek_kv + (i / 3);
            int c = col_tek_kv + (i % 3);
            nums[i] = sudoku[r][c];

            for (int j = 0; j < i; j++)
            {
                if (sudoku[r][c] == nums[j])
                {
                    printf("Ошибка, квадрат номер: %d\n", count + 1);
                    return 1;
                }
            }
        }
        count += 1;
    }
    return 0;
}

int is_valid_sudoku(int SIZE, int sudoku[SIZE][SIZE])
{
    int r = check_rows(SIZE, sudoku);
    int c = check_colums(SIZE, sudoku);
    int s = check_squares(SIZE, sudoku);

    printf("Проверка строк: %d\n", r);
    printf("Проверка столбцов: %d\n", c);
    printf("Проверка квадратов: %d\n", s);

    if (r == 1 || c == 1 || s == 1)
        return 1;
    return 0;
}

int main()
{
#define SIZE 9

    int sudoku[SIZE][SIZE] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    for (int r = 0; r < SIZE; r++)
    {
        for (int n = 0; n < SIZE; n++)
        {
            int p = sudoku[r][n];
            if ((p != 1) & (p != 2) & (p != 3) & (p != 4) & (p != 5) & (p != 6) & (p != 7) & (p != 8) & (p != 9))
            {
                printf("Странное число: %d в матрице", p);
                return 0;
            }
        }
    }
    is_valid_sudoku(SIZE, sudoku);

    return 0;
}