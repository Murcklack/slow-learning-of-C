#include <stdio.h>
int determintion(int N, double matrix[N][N]){
    if (N == 1){
        return matrix[0][0];
    }
}

int main() {
    int N;
    printf("Введи размерность матрицы коэффициентов NxN: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка ввода размера!\n");
        return 1;
    }
    double matrix[N][N];
    double freedom[N];

    for (int i = 0; i < N; i++) {
        printf("\n--- Заполнение %d-го уравнения ---\n", i + 1);
        
        for (int j = 0; j < N; j++) {
            printf("Введи коэффициент x_%d (строка %d, столбец %d): ", j + 1, i + 1, j + 1);
            scanf("%lf", &matrix[i][j]); 
        }
        
        printf("Введи свободный коэффициент (результат %d уравнения): ", i + 1);
        scanf("%lf", &freedom[i]);
    }

    printf("\nПроверяй введенную систему:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%7.2f ", matrix[i][j]); 
        }
        printf("| %7.2f\n", freedom[i]);
    }
    char ans;
    printf("Продолжить? (Y/N)\n");
    scanf(" %c", &ans);
    if (ans == 'N' || ans == 'n') {
        return 0;
    }
//    printf("Определитель: %d",)    

    return 0;
}
