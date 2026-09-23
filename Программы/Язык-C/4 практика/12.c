#include <stdio.h>

int main(void) {
  int height, weight;
  int ascii = 65;
  printf("Задай параметр фигуры: ");
  scanf("%d", &height);
  weight = height;

  for (int i = 0; i < height; i++) {
    for (int n = 0; n < weight; n++) {
      printf("%c", ascii);
    }
    weight--;
    printf("\n");
    ascii++;
  }
  return 0;
}
