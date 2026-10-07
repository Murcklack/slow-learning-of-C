#include <stdio.h>

int main() {
  int N;
  printf("Введи N\n");
  scanf("%d", &N);

  int matrix[N][N];

  int chislo = 1;

  int verh = 0;
  int niz = N - 1;
  int left = 0;
  int right = N - 1;

  while (chislo <= N * N) {
    for (int i = left; i <= right; i++) { // заполняем слева направо
      matrix[verh][i] = chislo;
      chislo++;
    }
    verh++; // Верхнюю границу двинем вниз

    for (int i = verh; i <= niz; i++) {
      matrix[i][right] = chislo;
      chislo++;
    }
    right--; // Двигаем правую грань влево

    for (int i = right; i >= left; i--) {
      matrix[niz][i] = chislo;
      chislo++;
    }
    niz--; // Двигаем низ вверх

    for (int i = niz; i >= verh; i--) {
      matrix[i][left] = chislo;
      chislo++;
    }
    left++; // Двигаем лево направо
  }
  for (int i = 0; i < N; i++) {
    for (int x = 0; x < N; x++) {
      printf("%3d", matrix[i][x]);
    }
    printf("\n");
  }

  return 0;
}
