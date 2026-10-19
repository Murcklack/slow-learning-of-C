#include <stdio.h>

double determintion(int N, double matrix[N][N])
{
    if (N == 1)
    {
        return matrix[0][0];
    }
    if (N == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    double submatrix[N - 1][N - 1];

    for (int j = 0; j < N; j++)
    {
        int min_str_index = 0;

        for (int r = 1; r < N; r++)
        {
            int min_stolb_index = 0;
            for (int c = 0; c < N; c++)
            {
                if (c == j)
                {
                    continue;
                }
                submatrix[min_str_index][min_stolb_index] = matrix[r][c];
                min_stolb_index++;
            }
            min_str_index++;
        }
        double sign;
        if (j % 2 == 0)
        {
            sign = 1.0;
        }
        else
        {
            sign = -1.0;
        }
        det += sign * matrix[0][j] * determintion(N - 1, submatrix);
    }
    return det;
}

int main()
{
    int N;
    printf("Введи размерность матрицы коэффициентов NxN: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        printf("Ошибка ввода размера!\n");
        return 1;
    }
    double matrix[N][N];
    double freedom[N];

    for (int i = 0; i < N; i++)
    {
        printf("\n--- Заполнение %d-го уравнения ---\n", i + 1);

        for (int j = 0; j < N; j++)
        {
            printf("Введи коэффициент x_%d (строка %d, столбец %d): ", j + 1, i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }

        printf("Введи свободный коэффициент (результат %d уравнения): ", i + 1);
        scanf("%lf", &freedom[i]);
    }

    printf("\nПроверяй введенную систему:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("| %7.2f\n", freedom[i]);
    }
    char ans;
    printf("Продолжить? (Y/N)\n");
    scanf(" %c", &ans);
    if (ans == 'N' || ans == 'n')
    {
        return 0;
    }

    double main_d = determintion(N, matrix);
    printf("Определитель: %f\n", main_d);
    if (main_d == 0)
    {
        printf("Главный определитель равен 0! Метод Крамера неприменим, беее :/\n");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        double help_matrix[N][N];
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                if (col == i)
                {
                    help_matrix[row][col] = freedom[row];
                    continue;
                }
                help_matrix[row][col] = matrix[row][col];
            }
        }
        printf("x%d = %f\n", i + 1, determintion(N, help_matrix) / main_d);
    }

    return 0;
}
