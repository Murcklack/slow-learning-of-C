#include <math.h>
#include <stdio.h>
#include <unistd.h>

int max(int a, int b){
  return (a > b ? a : b);
}

int min(int a, int b){
  return (a < b ? a : b);
}


int main(void) {
  int C = 80, A = 10;
  float speed = 0.1, F = 0.3, t=0;

  while (1) {
    printf("\033[H"); // Возврат в верхний угол
    for (int y = 0; y < 50; y++) { // Сколько строчек выплёвываем
      int x1 = round(C + A * sin(F * y + t));
      int x2 = round(C - A * sin(F * y + t));
      
      int L = min(x1, x2);
      int R = max(x1, x2);

      for (int i = 0; i < L; i++){
        printf(" ");
      }
      int distance = R-L;
      if (distance == 0){
        printf("x\033[K\n"); // \033[K\n стирает остатки (очистка до конца строки)
      }
      
      else {
        int spaceBTW = distance - 1;
        printf("0");
                if (y % 2 == 0) {
          printf("\033[32m");
          for (int i = 0; i < spaceBTW; i++) {
            printf("-");
          }
        } else {
          printf("\033[33m"); 
          for (int i = 0; i < spaceBTW; i++) {
            printf("-");
          }
        }
        printf("\033[0m 0 \033[K\n");
      }
    }
    t = t + speed; 
    }
  return 0;
}
