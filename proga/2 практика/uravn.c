#include <stdio.h>

int main(void){
  printf("Введи x и y: ");
  float x, y;
  scanf("%f%f",&x,&y);
  if (x >= 0 && y >= 0){
    float r_user = x*x + y*y; // Радиус того, что вкинул мне человек
    float r_uborder = 1; // Радиус верхней граицы
    float r_dborder = 0.5 * 0.5; // Радиус нижней границы
    if (r_user >= r_dborder && r_user <= r_uborder){
      printf("Принадлежит\n");
    }
    else{
      printf("Не принадлежит\n");
    }
  }
  else{
    printf("Не принадлежит\n");
  }
  return 0;
}
